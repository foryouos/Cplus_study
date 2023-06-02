#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "mybutton.h"
#include "bbflay.h"
#include <QRandomGenerator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 给自定义按钮设置图片
    //将图片作为参数传递过去
    //ui->button->setImage(":/bbb.png", ":/bbb01.png", ":/bbb02.png");
    // 处理自定义按钮的鼠标点击事件
    //连接点击信号与事件处理
//    connect(ui->button, &mybutton::clicked, this, [=]()
//    {
//        QMessageBox::information(this, "按钮", "莫要调戏我...");
//    });
    //
    BBFlay* win = new BBFlay(this);
    //位于中心位置
    win->move((width() - win->width())/2,(height()-win->height())/2);

    //去掉主窗口的边框，并透明
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    //设置窗口透明
    setAttribute(Qt::WA_TranslucentBackground);
    //当前窗口最大化
    showMaximized();
    //循环多个bbfly对象
    for(int i =0;i<100;i++)
    {
        BBFlay* win = new BBFlay(this);
        //让每个蝴蝶的起点不一样
        win->move(QRandomGenerator::global()->bounded(this->width()),QRandomGenerator::global()->bounded(this->height()));
        win->show();
    }



}

MainWindow::~MainWindow()
{
    delete ui;
}
