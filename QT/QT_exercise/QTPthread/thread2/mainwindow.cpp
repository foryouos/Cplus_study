#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"
#include <QThread>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //当运行，用户点击按钮，就要调用子线程生成随机数，传递给主线程

    //1,创建子线程对象，
//    QThread* t1 = new QThread(this);  //添加之后会析构申请的空间
//    QThread* t2 = new QThread(this);
//    QThread* t3 = new QThread(this);

    QThread* t1 = new QThread;
    QThread* t2 = new QThread;
    QThread* t3 = new QThread;
    //2,创建任务类的对象
    Generate* gen = new Generate;
    BubbleSort * bubble = new BubbleSort;
    QuickSort * quick = new QuickSort;
    //3,将任务对象移动到某个子线程中
    gen->moveToThread(t1); //生成随机数
    bubble->moveToThread(t2);
    quick->moveToThread(t3);

    //信号和槽，主函数将starting的数，传递给子线程的recNum用户接受数量
    connect(this,&MainWindow::starting,gen,&Generate::working);


    //启动子线程,使用信号与槽，当用户点击

    connect(ui->start,&QPushButton::clicked,this,[=]()
    {
        emit starting(10000);
        //给子线程发送信号
        t1->start(); //调用子线程运行方法,还没有执行

    });



    //当有了随机数之后，开始起痘冒泡和快速排序线程

    //在排序之前，线程要先拿到所需要的数据

    connect(gen,&Generate::sendArray,bubble,&BubbleSort::working);

    connect(gen,&Generate::sendArray,quick,&QuickSort::working);

    //添加connect用于接受子线程传过来的list容器随机数
    //连接子线程，但子线程信号sendArray运行时，主线程接受
    connect(gen,&Generate::sendArray,this,[=](QVector <int> list)
    {
        //
        //主线程开始接受来自子线程发送过来的list，于此同时子线程开始运行
        t2->start();
        t3->start();


        for(int i =0;i<list.size();i++)
        {
            ui->randlist->addItem(QString::number(list.at(i)));
        }
    });

    //排序运行之后，将排序好的数据放到主线程
    connect(bubble,&BubbleSort::finish,this,[=](QVector<int> list)
    {
        for(int i =0;i<list.size();++i)
        {
            ui->bubblelist->addItem(QString::number(list.at(i)));
        }
    });
    connect(quick,&QuickSort::finish,this,[=](QVector<int> list)
    {
        for(int i =0;i<list.size();++i)
        {
            ui->quicklist->addItem(QString::number(list.at(i)));
        }
    });

    //手写销毁资源
    connect(this,&MainWindow::destroy,this,[=]()
    {
        t1->quit();
        t1->wait();
        t1->deleteLater(); //释放空间

        t2->quit();
        t2->wait();
        t2->deleteLater(); //释放空间

        t3->quit();
        t3->wait();
        t3->deleteLater(); //释放空间

        gen->deleteLater();
        bubble->deleteLater();
        quick->deleteLater();
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}
