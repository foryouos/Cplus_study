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
    m_queue.push(task); //将任务压入队列
    m_mutex.unlock();
}
//重载添加任务队列
template <typename T>
void TaskQueue<T>::addTask(callback func, void* arg)
{
    m_mutex.lock();
    Task<T> task; //创建结构体，将所需要的函数和参数传入结构体，然后压入队列
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
        t = m_queue.front(); //取头部节点
        m_queue.pop(); //弹出
    }
    m_mutex.unlock();
    return t;
}