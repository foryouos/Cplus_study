#include "threadPool.h"
//初始化线程池，需要的最小和最大数量参数
template <typename T>
ThreadPool<T>::ThreadPool(int minNum, int maxNum)
{
    // 实例化任务队列
    m_taskQ = new TaskQueue<T>;
    do
    {
        // 初始化线程池
        m_minNum = minNum;
        m_maxNum = maxNum;
        m_busyNum = 0;
        m_aliveNum = minNum;

        m_managerID = thread(manager, this);

        m_threadIDs.resize(m_maxNum);
        for (int i = 0; i < m_minNum; i++)
        {
            m_threadIDs[i] = thread(worker, this);
        }
        return;
    } while (0);
}

template <typename T>
ThreadPool<T>::~ThreadPool()
{
    cout << "线程进入退出程序 ....!" << endl;
    m_shutdown = true;
    // 销毁管理者线程
    //pthread_join(m_managerID, NULL);
    if (m_managerID.joinable())
    {
        m_managerID.join();
    }
    // 唤醒所有消费者线程
    m_notEmpty.notify_all();
    for (int i = 0; i < m_maxNum; ++i)
    {
        if (m_threadIDs[i].joinable())
        {
            m_threadIDs[i].join();
        }
    }
    
    cout << "线程退出完毕.....!" << endl;
}
template <typename T>
void ThreadPool<T>::addTask(Task<T> task)
{
    if (m_shutdown)
    {
        return;
    }
    // 添加任务，不需要加锁，任务队列中有锁
    //调用 任务队列函数,从线程池中调用即可
    m_taskQ->addTask(task);
    // 唤醒工作的线程
    //pthread_cond_signal(&m_notEmpty); //不是空的，会进行对应的任务处理
    m_notEmpty.notify_all();
}
template <typename T>
int ThreadPool<T>::getAliveNumber()
{
    int threadNum = 0;
    m_lock.lock();
    threadNum = m_aliveNum;
    m_lock.unlock();
    return threadNum;
}
template <typename T>
int ThreadPool<T>::getBusyNumber()
{
    int busyNum = 0;
    m_lock.lock();
    busyNum = m_busyNum;
    m_lock.unlock();
    return busyNum;
}


// 工作线程任务函数
template <typename T>
void* ThreadPool<T>::worker(void* arg)
{
    ThreadPool* pool = static_cast<ThreadPool*>(arg);
    // 一直不停的工作
    while (true)
    {
        // 访问任务队列(共享资源)加锁
        unique_lock<std::mutex> lk(pool->m_lock);
        // 判断任务队列是否为空, 如果为空工作线程阻塞
        while (pool->m_taskQ->taskNumber() == 0 && !pool->m_shutdown)
        {
            cout << "thread " << this_thread::get_id() << " waiting..." << endl;
            // 阻塞线程
            //pthread_cond_wait(&pool->m_notEmpty, &pool->m_lock);
            pool->m_notEmpty.wait(lk);

            // 解除阻塞之后, 判断是否要销毁线程
            if (pool->m_exitNum > 0)
            {
                pool->m_exitNum--;
                if (pool->m_aliveNum > pool->m_minNum)
                {
                    pool->m_aliveNum--;
                    cout << "threadId :" << this_thread::get_id() <<"exit ......" << endl;
                    lk.unlock();
                    return nullptr;
                }
            }
        }
        // 判断线程池是否被关闭了
        if (pool->m_shutdown)
        {
            cout << "threadId :" << this_thread::get_id() << "exit ......" << endl;
            //lk.unlock();
            return nullptr;
        }

        // 从任务队列中取出一个任务
        Task<T> task = pool->m_taskQ->takeTask();
        // 工作的线程+1
        pool->m_busyNum++;
        // 线程池解锁
        lk.unlock();
        // 执行任务
        cout << "thread " << this_thread::get_id() << " start working..." << endl;
        // 执行取出的函数
        task.function(task.arg);
        delete task.arg;
        task.arg = nullptr;

        // 任务处理结束
        cout << "thread " << this_thread::get_id() << " end working..." << endl;
        lk.lock();
        pool->m_busyNum--;
        lk.unlock();
    }

    return nullptr;
}


// 管理者线程任务函数
template <typename T>
void* ThreadPool<T>::manager(void* arg)
{
    ThreadPool* pool = static_cast<ThreadPool*>(arg);
    // 如果线程池没有关闭, 就一直检测
    while (!pool->m_shutdown)
    {
        // 每隔5s检测一次
        this_thread::sleep_for(2s);
        // 取出线程池中的任务数和线程数量
        //  取出工作的线程池数量
        unique_lock<mutex> lk(pool->m_lock);
        int queueSize = pool->m_taskQ->taskNumber();
        int liveNum = pool->m_aliveNum;
        int busyNum = pool->m_busyNum;
        lk.unlock();

        // 创建线程

        // 当前任务个数>存活的线程数 && 存活的线程数<最大线程个数
        if (queueSize > liveNum && liveNum < pool->m_maxNum)
        {
            // 线程池加锁
            lk.lock();
            int num = 0;
            for (int i = 0; i < pool->m_maxNum && num < NUMBER
                && pool->m_aliveNum < pool->m_maxNum; ++i)
            {
                if (pool->m_threadIDs[i].get_id() == thread::id())
                {
                    //pthread_create(&pool->m_threadIDs[i], NULL, worker, pool);
                    pool->m_threadIDs[i] = thread(worker, pool);
                    num++;
                    pool->m_aliveNum++;
                }
            }
            lk.unlock();
        }

        // 销毁多余的线程
        // 忙线程*2 < 存活的线程数目 && 存活的线程数 > 最小线程数量
        if (busyNum * 2 < liveNum && liveNum > pool->m_minNum)
        {
            lk.lock();

            pool->m_exitNum = NUMBER;
            lk.unlock();
            for (int i = 0; i < NUMBER; ++i)
            {
                pool->m_notEmpty.notify_all();
            }
        }
    }
    return nullptr;
}
