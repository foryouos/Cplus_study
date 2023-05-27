#include "mythread.h"
#include <QElapsedTimer>  //记录时间
#include <QtDebug>
#include <QThread>
Generate::Generate(QObject *parent) : QObject(parent)
{

}

void Generate::working(int num)
{
    qDebug()<< "生成随机数的线程地址" <<QThread::currentThread();
    //存放随机数vector容器
    QVector<int> list;  //子线程生成数据，要通过传递给主线程

    QElapsedTimer time;
    time.start();//开始记录
    for (int i = 0;i <num;++i)
    {
        //从尾部插入
        list.push_back(qrand()%100000);

    }
    qint64 milsec = time.elapsed(); //毫秒
    qDebug()<< "生成" <<num << "个随机总数用时"<<milsec<<"毫秒";
    //发送给主线程
    emit sendArray(list); //将数据发给主线程
}
//冒泡排序,补齐parent
BubbleSort::BubbleSort(QObject *parent) : QObject(parent)
{

}

//实现冒泡排序,实现相邻两个元素的交换
void BubbleSort::working(QVector<int> list)
{
    qDebug()<< "冒泡排序的线程地址" <<QThread::currentThread();
    //存放随机数vector容器
    QElapsedTimer time;
    time.start();
    int temp;
    for(int i = 0;i<list.size();++i)
    {
        for(int j =0;j<list.size()-i-1;++j) //从后数往前比较
        {
            if(list[j]>list[j+1])
            {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1]=temp;
            }
        }
    }
    qint64 milsec = time.elapsed();
    qDebug()<< "冒泡排序用时" <<milsec<<"毫秒";
    //发送给主线程
    emit finish(list); //将数据发给主线程
}


//快速,补齐parent
QuickSort::QuickSort(QObject *parent) : QObject(parent)
{

}

//实现快速排序
void QuickSort::working(QVector<int> list)
{
    qDebug()<< "快速排序的线程地址" <<QThread::currentThread();
    //存放随机数vector容器
    QElapsedTimer time;
    time.start();
    //快速排序算法

    quickSort(list,0,list.size()-1);
    qint64 milsec = time.elapsed();
    qDebug()<< "快速排序用时" <<milsec<<"毫秒";
    //发送给主线程
    emit finish(list); //将数据发给主线程
}
//快排算法
void QuickSort::quickSort(QVector<int> &s, int l, int r)
{
    if(l < r)
    {
        int i = l,j=r;
        //拿出第一个元素，保存到x中，第一个位置为空
        int x = s[l];
        while (i < j)
        {
            // 从右向左找小于x的数
            while (i < j && s[j] >= x)
            {
                //左移, 直到遇到小于等于x的数
                j--;
            }
            if (i < j)
            {
                //将右侧找到的小于x的元素放入左侧坑中, 右侧出现一个坑
                //左侧元素索引后移
                s[i++] = s[j];
            }

            // 从左向右找大于等于x的数
            while (i < j && s[i] < x)
            {
                //右移, 直到遇到大于x的数
                i++;
            }
            if (i < j)
            {
                //将左侧找到的元素放入右侧坑中, 左侧出现一个坑
                //右侧元素索引向前移动
                s[j--] = s[i];
            }
        }
        //此时 i=j,将保存在x中的数填入坑中
        s[i] = x;
        quickSort(s, l, i - 1); // 递归调用
        quickSort(s, i + 1, r);
    }
}

