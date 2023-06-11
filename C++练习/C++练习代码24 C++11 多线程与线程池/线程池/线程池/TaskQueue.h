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
// ��������ṹ�� �������
using callback = void(*)(void*);
//����ṹ��
template <typename T>
struct Task
{
    //���캯��
    Task<T>()
    {
        function = nullptr;
        arg = nullptr;
    }
    //�вκ�������
    Task<T>(callback f, void* arg)
    {
        function = f;
        this->arg = (T*)arg;
    }
    //�� ����ָ��
    callback function;
    //��������
    T* arg;
};

// �������
template <typename T>
class TaskQueue
{
public:
    //���캯��
    TaskQueue();
    ~TaskQueue();

    // �������
    void addTask(Task<T> task);
    void addTask(callback func, void* arg);

    // ȡ��һ������
    Task<T> takeTask();

    // ��ȡ��ǰ�������������
    inline size_t taskNumber() //�����������Ч��
    {
        return m_queue.size(); //���ض��и���
    }

private:
    //ȡ�����������񣬼���
    mutex m_mutex;    // ������
    //����ṹ��Ķ���
    std::queue<Task<T>> m_queue;   // �������
};
#endif