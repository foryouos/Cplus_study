#ifndef CONNECTIONPOOL_H
#define CONNECTIONPOOL_H

#include <QObject>
#include <QtSql/QtSql>
#include <QMutex>
#include <QMutexLocker>
#include <QWaitCondition>

class ConnectionPool
{
public:

    ~ConnectionPool();

    static void release(); //关闭连接池

    static QSqlDatabase openConnection(); //获取数据库连接

    static void closeConnection(QSqlDatabase connection); //释放数据库连接回连接池

private:
    //数据库信息
    QString hostName;
    QString databaseName;
    QString username;
    QString password;
    QString databaseType;

    bool testOnBorrow; //取得连接的时候验证连接是否有效
    QString testOnBorrowSql; //测试访问数据库的 SQL

    int maxWaitTime; //获取连接最大等待时间
    int waitInterval; //尝试获取连接时等待间隔时间
    int maxConnectionCount; //最大连接数

    QQueue<QString> usedConnectionNames; //已使用的数据库连接名
    QQueue<QString> unUsedConnectionNames; //未使用的数据库连接名

    static QMutex mutex; //同步锁
    static QWaitCondition waitCondition; //条件等待锁
    static ConnectionPool *instance;

    ConnectionPool();

    //单例，需提供拷贝构造函数和赋值运算符
    static ConnectionPool& getInstance();
    ConnectionPool(const ConnectionPool &other); //拷贝构造函数
    ConnectionPool& operator=(const ConnectionPool &other); //赋值运算符

    QSqlDatabase createConnection(const QString &connectionName);




};

#endif // CONNECTIONPOOL_H
