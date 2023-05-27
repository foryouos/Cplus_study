#include <pthread.h>
#include <stdio.h>
#include <unistd.h> //sleep
void* thfunc(void* arg)
{
    printf("in thfunc\n");
    return (void*)0;
}

int main(int argc,char *argv[])
{
    pthread_t tidp;
    int ret;
    ret = pthread_create(&tidp, NULL, thfunc, NULL); //创建线程 ,如果成功返回0
    if (ret) //0不会 执行
    {
        printf("pthread_create fail:%d\n", ret);
        return -1;
    }
    sleep(1); //main线程挂起 一秒钟
    printf("in main:thread is created!\n");
    return 0;
}