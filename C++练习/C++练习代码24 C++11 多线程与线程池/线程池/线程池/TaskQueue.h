#pragma once
#ifndef _TASKQUEUE_H
#define _TASKQUEUE_H
#include <thread>
#include <iostream>
#include <queue>
#include <string.h>
#include <Windows.h>
#include <mutex>
#include <condition_variable>
using namespace std;
// 定义任务结构体 定义别名
using callback = void(*)(void*);
//任务结构体
template <typename T>
struct Task
{
    //构造函数
    Task<T>()
    {
        function = nullptr;
        arg = nullptr;
    }
    //有参函数构造
    Task<T>(callback f, void* arg)
    {
        function = f;
        this->arg = (T*)arg;
    }
    //类 函数指针
    callback function;
    //函数参数
    T* arg;
};

// 任务队列
template <typename T>
class TaskQueue
{
public:
    //构造函数
    TaskQueue();
    ~TaskQueue();

    // 添加任务
    void addTask(Task<T> task);
    void addTask(callback func, void* arg);

    // 取出一个任务
    Task<T> takeTask();

    // 获取当前队列中任务个数
    inline size_t taskNumber() //内联函数提高效率
    {
        return m_queue.size(); //返回队列个数
    }

private:
    //取任务和添加任务，加锁
    mutex m_mutex;    // 互斥锁
    //任务结构体的队列
    std::queue<Task<T>> m_queue;   // 任务队列
};
#endif