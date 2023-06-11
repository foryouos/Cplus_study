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
//线程池类
template <typename T>
class ThreadPool
{
public:
    //默认构造函数
    ThreadPool(int min, int max);
    ~ThreadPool();

    // 添加任务
    void addTask(Task<T> task);
    // 获取忙线程的个数
    int getBusyNumber();
    // 获取活着的线程个数
    int getAliveNumber();

private:
    // 工作的线程的任务函数
    static void* worker(void* arg);
    // 管理者线程的任务函数
    static void* manager(void* arg);

private:
    mutex m_lock;
    condition_variable m_notEmpty;
    vector<thread> m_threadIDs;  //工作线程
    thread m_managerID;  //管理者线 程
    TaskQueue<T>* m_taskQ;  //任务队列
    static const int NUMBER = 2;
    int m_minNum;  //最小数量
    int m_maxNum;  //最大数量
    int m_busyNum;  //忙碌的线程
    int m_aliveNum;  //存活的线程数
    int m_exitNum;  //要销毁的线程数
    bool m_shutdown = false;  //是否要销毁线程池
};
#endif