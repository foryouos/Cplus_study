#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QRunnable>
#include <QVector>
#include <QObject>
//创建的子线程,生成随机数
class Generate : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Generate(QObject *parent = nullptr);
    //接受主线程传过来的参数,随机数num
    void recNum(int num);

    //子线程运行函数
    void run() override;
signals:


    //使用信号槽将数据传递给主线程，界面操作只能由主线程来进行
    void sendArray(QVector<int> num);

public slots:

private:
    //设置信号槽接受主线程传过来的数据
    int m_num;
};




//冒泡排序
class BubbleSort : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit BubbleSort(QObject *parent = nullptr);
    //接受主线程传过来的参数,数组
    void recArray(QVector<int> list);

    //子线程运行函数
    void run() override;
signals:
    //使用信号槽将数据传递给主线程，界面操作只能由主线程来进行
    //发送的有序数组
    void finish(QVector<int> list);

public slots:

private:
    //设置信号槽接受主线程传过来的数据
    QVector<int> m_list;
};





//快速排序
class QuickSort : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit QuickSort(QObject *parent = nullptr);
    //接受主线程传过来的参数,随机数num
    void recArray(QVector<int> list);

    //子线程运行函数
    void run() override;
signals:


    //使用信号槽将数据传递给主线程，界面操作只能由主线程来进行
    void finish(QVector<int> list);

public slots:

private:
    //设置信号槽接受主线程传过来的数据
    QVector<int> m_list;

    //实现快速排序算法
    //容器，起始位置，结束位置
    void quickSort(QVector<int> &list,int l,int r);
};

#endif // MYTHREAD_H
