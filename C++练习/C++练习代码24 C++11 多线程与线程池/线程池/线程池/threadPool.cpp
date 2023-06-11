#include "threadPool.h"
//��ʼ���̳߳أ���Ҫ����С�������������
template <typename T>
ThreadPool<T>::ThreadPool(int minNum, int maxNum)
{
    // ʵ�����������
    m_taskQ = new TaskQueue<T>;
    do
    {
        // ��ʼ���̳߳�
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
    cout << "�߳̽����˳����� ....!" << endl;
    m_shutdown = true;
    // ���ٹ������߳�
    //pthread_join(m_managerID, NULL);
    if (m_managerID.joinable())
    {
        m_managerID.join();
    }
    // ���������������߳�
    m_notEmpty.notify_all();
    for (int i = 0; i < m_maxNum; ++i)
    {
        if (m_threadIDs[i].joinable())
        {
            m_threadIDs[i].join();
        }
    }
    
    cout << "�߳��˳����.....!" << endl;
}
template <typename T>
void ThreadPool<T>::addTask(Task<T> task)
{
    if (m_shutdown)
    {
        return;
    }
    // ������񣬲���Ҫ�������������������
    //���� ������к���,���̳߳��е��ü���
    m_taskQ->addTask(task);
    // ���ѹ������߳�
    //pthread_cond_signal(&m_notEmpty); //���ǿյģ�����ж�Ӧ��������
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


// �����߳�������
template <typename T>
void* ThreadPool<T>::worker(void* arg)
{
    ThreadPool* pool = static_cast<ThreadPool*>(arg);
    // һֱ��ͣ�Ĺ���
    while (true)
    {
        // �����������(������Դ)����
        unique_lock<std::mutex> lk(pool->m_lock);
        // �ж���������Ƿ�Ϊ��, ���Ϊ�չ����߳�����
        while (pool->m_taskQ->taskNumber() == 0 && !pool->m_shutdown)
        {
            cout << "thread " << this_thread::get_id() << " waiting..." << endl;
            // �����߳�
            //pthread_cond_wait(&pool->m_notEmpty, &pool->m_lock);
            pool->m_notEmpty.wait(lk);

            // �������֮��, �ж��Ƿ�Ҫ�����߳�
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
        // �ж��̳߳��Ƿ񱻹ر���
        if (pool->m_shutdown)
        {
            cout << "threadId :" << this_thread::get_id() << "exit ......" << endl;
            //lk.unlock();
            return nullptr;
        }

        // �����������ȡ��һ������
        Task<T> task = pool->m_taskQ->takeTask();
        // �������߳�+1
        pool->m_busyNum++;
        // �̳߳ؽ���
        lk.unlock();
        // ִ������
        cout << "thread " << this_thread::get_id() << " start working..." << endl;
        // ִ��ȡ���ĺ���
        task.function(task.arg);
        delete task.arg;
        task.arg = nullptr;

        // ���������
        cout << "thread " << this_thread::get_id() << " end working..." << endl;
        lk.lock();
        pool->m_busyNum--;
        lk.unlock();
    }

    return nullptr;
}


// �������߳�������
template <typename T>
void* ThreadPool<T>::manager(void* arg)
{
    ThreadPool* pool = static_cast<ThreadPool*>(arg);
    // ����̳߳�û�йر�, ��һֱ���
    while (!pool->m_shutdown)
    {
        // ÿ��5s���һ��
        this_thread::sleep_for(2s);
        // ȡ���̳߳��е����������߳�����
        //  ȡ���������̳߳�����
        unique_lock<mutex> lk(pool->m_lock);
        int queueSize = pool->m_taskQ->taskNumber();
        int liveNum = pool->m_aliveNum;
        int busyNum = pool->m_busyNum;
        lk.unlock();

        // �����߳�

        // ��ǰ�������>�����߳��� && �����߳���<����̸߳���
        if (queueSize > liveNum && liveNum < pool->m_maxNum)
        {
            // �̳߳ؼ���
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

        // ���ٶ�����߳�
        // æ�߳�*2 < �����߳���Ŀ && �����߳��� > ��С�߳�����
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
