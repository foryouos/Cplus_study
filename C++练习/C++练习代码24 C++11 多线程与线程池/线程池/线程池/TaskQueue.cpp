#include "TaskQueue.h"
template <typename T>
TaskQueue<T>::TaskQueue()
{
    //pthread_mutex_init(&m_mutex, NULL);
}
template <typename T>
TaskQueue<T>::~TaskQueue()
{
    //pthread_mutex_destroy(&m_mutex);
}
template <typename T>
void TaskQueue<T>::addTask(Task<T> task)
{
    m_mutex.lock();
    m_queue.push(task); //������ѹ�����
    m_mutex.unlock();
}
//��������������
template <typename T>
void TaskQueue<T>::addTask(callback func, void* arg)
{
    m_mutex.lock();
    Task<T> task; //�����ṹ�壬������Ҫ�ĺ����Ͳ�������ṹ�壬Ȼ��ѹ�����
    task.function = func;
    task.arg = arg;
    m_queue.push(task);
    m_mutex.unlock();
}
template <typename T>
Task<T> TaskQueue<T>::takeTask()
{
    Task<T> t;
    m_mutex.lock();
    if (m_queue.size() > 0)
    {
        t = m_queue.front(); //ȡͷ���ڵ�
        m_queue.pop(); //����
    }
    m_mutex.unlock();
    return t;
}