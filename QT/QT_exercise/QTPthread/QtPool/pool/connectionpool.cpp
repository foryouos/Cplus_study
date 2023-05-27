#include "connectionpool.h"
QMutex ConnectionPool::mutex;
QWaitCondition ConnectionPool::waitCondition;
ConnectionPool *ConnectionPool::instance = nullptr;

ConnectionPool::ConnectionPool()
{
    // 创建数据库连接的这些信息在实际开发的时都需要通过读取配置文件得到，
    // 这里为了演示方便所以写死在了代码里。
    hostName     = "127.0.0.1";
    databaseName = "qq";
    username     = "root";
    password     = "root";
    databaseType = "QMYSQL";
    testOnBorrow = true;
    testOnBorrowSql = "SELECT 1";

    maxWaitTime  = 1000;
    waitInterval = 200;
    maxConnectionCount  = 100;
}
//删除所有数据库连接
ConnectionPool::~ConnectionPool()
{
    //销毁连接池的时候删除所有的连接
    foreach (QString connectionName, usedConnectionNames) {
        QSqlDatabase::removeDatabase(connectionName);
    }
    foreach (QString connectionName, unUsedConnectionNames) {
        QSqlDatabase::removeDatabase(connectionName);
    }
}

void ConnectionPool::release()
{
    QMutexLocker locker(&mutex);
    //删除连接池对象，会调用析构函数，删除池中所有的连接
    delete instance;
    instance = nullptr;
}

QSqlDatabase ConnectionPool::openConnection()
{
    ConnectionPool &pool = ConnectionPool::getInstance();
    QString connectionName;
    mutex.lock();
    // 已创建连接数
    int connectionCount = pool.unUsedConnectionNames.size() + pool.usedConnectionNames.size();
    // 如果连接已经用完，且当前总连接数等于最大连接数，等待 waitInterval 毫秒看看是否有可用连接，
    //最长等待 maxWaitTime 毫秒
    for (int i = 0; i < pool.maxWaitTime
         && pool.unUsedConnectionNames.size() == 0
         && connectionCount == pool.maxConnectionCount; i=i+ waitInterval)
    {
        //阻塞，期间其他线程可以使用 mutex 锁，等待唤醒，唤醒后继续加锁，执行后续代码
        waitCondition.wait(&mutex, pool.waitInterval);
        // 重新计算已创建连接数
        connectionCount = pool.unUsedConnectionNames.size() + pool.usedConnectionNames.size();
    }

    if (pool.unUsedConnectionNames.size() > 0)
        // 有已经回收的连接，复用它们
        connectionName = pool.unUsedConnectionNames.dequeue();
    else if (connectionCount < maxConnectionCount)
        // 没有已经回收的连接，但是没有达到最大连接数，则创建新的连接
        connectionName = QString("Connection-%1").arg(connectionCount + 1);
    else {
        // 已经达到最大连接数
        qDebug() << "Cannot create more connections.";
        //这里相当于 return NULL
        return QSqlDatabase();
    }
    mutex.unlock();
    //因为创建连接很耗时，所以不放在 lock 的范围内，提高并发效率
    //获取新的连接（为什么不是创建，因为有可能是已经回收的连接，直接复用即可）
    QSqlDatabase db = pool.createConnection(connectionName);

    // 有效的连接才放入 usedConnectionNames
    if (db.isOpen()){
        mutex.lock();
        pool.usedConnectionNames.enqueue(connectionName);
        mutex.unlock();
    }
    return db;
}

/**
 * 这里的关闭连接并不是真的关闭，而是将连接放回连接池，只有关闭连接池的时候，才关闭所有连接
 */
void ConnectionPool::closeConnection(QSqlDatabase connection)
{
    ConnectionPool &pool = ConnectionPool::getInstance();
    QString connectionName = connection.connectionName();

    // 如果是我们创建的连接，从 used 里删除，放入 unused 里
    if (pool.usedConnectionNames.contains(connectionName)) {
        QMutexLocker locker(&mutex);
        pool.usedConnectionNames.removeOne(connectionName);
        pool.unUsedConnectionNames.enqueue(connectionName);
        //唤醒所有线程，此时阻塞的 QWaitCondition 会被唤醒
        waitCondition.wakeOne();
    }
}

/**
 * 单例：双重检查锁
 */
ConnectionPool &ConnectionPool::getInstance()
{
    if (nullptr == instance) {
        QMutexLocker locker(&mutex);
        if (nullptr == instance) {
            instance = new ConnectionPool();
        }
    }
    return *instance;
}

QSqlDatabase ConnectionPool::createConnection(const QString &connectionName)
{
    // 连接已经创建过了，复用它，而不是重新创建
    if (QSqlDatabase::contains(connectionName)) {
        QSqlDatabase unUsedDb = QSqlDatabase::database(connectionName);

        if (testOnBorrow) {
            // 返回连接前访问数据库，如果连接断开，重新建立连接
            qDebug() << "Test connection on borrow, execute:" << testOnBorrowSql << ", for" << connectionName;
            //测试连接
            QSqlQuery query(testOnBorrowSql, unUsedDb);
            // 若查询报错，或者连接无法打开
            if (query.lastError().type() != QSqlError::NoError && !unUsedDb.open()) {
                qDebug() << "Open datatabase error:" << query.lastError().text();
                return QSqlDatabase();
            }
        }
        return unUsedDb;
    }

    //新创建连接
    QSqlDatabase db = QSqlDatabase::addDatabase(databaseType, connectionName);
    db.setHostName(hostName);
    db.setDatabaseName(databaseName);
    db.setUserName(username);
    db.setPassword(password);

    if (!db.open()) {
        qDebug() << "Open datatabase error:" << db.lastError().text();
        return QSqlDatabase();
    }
    return db;
}

