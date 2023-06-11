#ifndef _THREADPOOL_H
#define _THREADPOOL_H
#include <iostream>
#include <queue>
#include <string.h>
#include <string>
#include "TaskQueue.h"
#include "TaskQueue.cpp"
#include <thread>
#include <Windows.h>
#include <mutex>
#include <vector>
#include <condition_variable>
using namespace std;
//�̳߳���
template <typename T>
class ThreadPool
{
public:
    //Ĭ�Ϲ��캯��
    ThreadPool(int min, int max);
    ~ThreadPool();

    // �������
    void addTask(Task<T> task);
    // ��ȡæ�̵߳ĸ���
    int getBusyNumber();
    // ��ȡ���ŵ��̸߳���
    int getAliveNumber();

private:
    // �������̵߳�������
    static void* worker(void* arg);
    // �������̵߳�������
    static void* manager(void* arg);

private:
    mutex m_lock;
    condition_variable m_notEmpty;
    vector<thread> m_threadIDs;  //�����߳�
    thread m_managerID;  //�������� ��
    TaskQueue<T>* m_taskQ;  //�������
    static const int NUMBER = 2;
    int m_minNum;  //��С����
    int m_maxNum;  //�������
    int m_busyNum;  //æµ���߳�
    int m_aliveNum;  //�����߳���
    int m_exitNum;  //Ҫ���ٵ��߳���
    bool m_shutdown = false;  //�Ƿ�Ҫ�����̳߳�
};
#endif