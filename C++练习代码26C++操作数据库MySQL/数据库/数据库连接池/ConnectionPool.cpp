#include "ConnectionPool.h"
#include <json/json.h>
#include <fstream>
#include <mysql.h>
#include <thread> //加载多线程
using namespace Json;
ConnectionPool* ConnectionPool::getConnectPool()
{
    static ConnectionPool pool; //静态局部对象，不管后面调用多少次，得到的都是同一块内存地址

    return &pool;
}
//打开数据库信息文件，并判断是否读取到相关信息
bool ConnectionPool::paraseJsonFile()
{
    ifstream ifs("dbconf.json");
    Reader rd;
    Value root;
    rd.parse(ifs, root);
    if (root.isObject())
    {
        m_ip = root["ip"].asString();
        m_port = root["port"].asInt();
        m_user = root["userName"].asString();
        m_passwd = root["password"].asString();
        m_dbName = root["dbName"].asString();
        m_minSize = root["minSize"].asInt();
        m_maxSize = root["maxSize"].asInt();
        m_maxIdleTime = root["maxIdlTime"].asInt();
        m_timeout = root["timeout"].asInt();
        return true;
    }
    return false;
}
void ConnectionPool::prodeceConnection()
{
    while (true)
    {
        unique_lock<mutex> locker(m_mutexQ);
        while (m_connectionQ.size() >= m_minSize)
        {
            m_cond.wait(locker);
        }
        addConnection();
    }
}
void ConnectionPool::recycleConnection()
{

}
void ConnectionPool::addConnection()
{
    MySqlConnect* conn = new MySqlConnect;
    conn->connect(m_user, m_passwd, m_dbName, m_ip, m_port);

    m_connectionQ.push(conn);
}
//构造函数的实现
ConnectionPool::ConnectionPool()
{
    //加载配置文件
    if (!paraseJsonFile())
    {
        return;
    }
    //初始化配置连接数
    for (int i = 0; i < m_minSize; ++i)
    {
        MySqlConnect* conn = new MySqlConnect;
        conn->connect(m_user, m_passwd, m_dbName, m_ip, m_port);

        m_connectionQ.push(conn);
    }
    //当前实例对象this指针
    thread producer(&ConnectionPool::prodeceConnection,this); //生成线程池的连接
    thread recycler(&ConnectionPool::recucleConnection,this); //有没有需要销毁的连接
    //主线程和子线程分离
    producer.detach();
    recycler.detach();
}