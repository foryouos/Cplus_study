#include "ConnectionPool.h"
#include <json/json.h>
#include <fstream>
#include <mysql.h>
#include <thread> //���ض��߳�
using namespace Json;
ConnectionPool* ConnectionPool::getConnectPool()
{
    static ConnectionPool pool; //��̬�ֲ����󣬲��ܺ�����ö��ٴΣ��õ��Ķ���ͬһ���ڴ��ַ

    return &pool;
}
//�����ݿ���Ϣ�ļ������ж��Ƿ��ȡ�������Ϣ
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
//���캯����ʵ��
ConnectionPool::ConnectionPool()
{
    //���������ļ�
    if (!paraseJsonFile())
    {
        return;
    }
    //��ʼ������������
    for (int i = 0; i < m_minSize; ++i)
    {
        MySqlConnect* conn = new MySqlConnect;
        conn->connect(m_user, m_passwd, m_dbName, m_ip, m_port);

        m_connectionQ.push(conn);
    }
    //��ǰʵ������thisָ��
    thread producer(&ConnectionPool::prodeceConnection,this); //�����̳߳ص�����
    thread recycler(&ConnectionPool::recucleConnection,this); //��û����Ҫ���ٵ�����
    //���̺߳����̷߳���
    producer.detach();
    recycler.detach();
}