#include "threadPool.h"
#include "threadPool.cpp"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <Windows.h>
#include <mutex>
#include <condition_variable>
using namespace std;

void taskFunc(void* arg)
{
    int num = *(int*)arg;
    cout << "thread" << this_thread::get_id() << " is working, number =" << to_string(num) << endl;
    this_thread::sleep_for(1s);
}
int main(void)
{
    //创建线程池
    ThreadPool<int> pool(3, 8);
    for (int i = 0; i < 100; ++i)
    {

        int* num = new int(i + 100); //new和delete对应
        //添加任务队列
        pool.addTask(Task<int>(taskFunc, num));
    }
    this_thread::sleep_for(30s);
    return 0;
}