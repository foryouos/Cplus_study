#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //锁定全局大小不可放大
    //setFixedSize(400,300);
    //设置标题
    setWindowTitle("My first No UI");
    mc1 = new MyClass(this);
    mc2 = new MyClass2(this);
    //connect连接信号与槽
    //一个信号可以关联多个槽，多个槽可以被多个信号关联
    connect(ui->close,&QPushButton::clicked,mc2,&MyClass2::MySlot); //调用
    connect(mc1,&MyClass::MySignal,mc2,&MyClass2::MySlot);

    connect(mc1,&MyClass::Num,mc2,&MyClass2::NumSlot);

    connect(ui->num,&QPushButton::clicked,mc1,&MyClass::MySignal);  //当点击数字信号发出，同时调用另一个信号

    //label标签
    QLabel *label = new QLabel(this); //创建label是带this参数，即显示到当前主页面
    label->setText("你好呀!");
    label->move(200,100);  //移动位置，以左上角为起点
    emit mc1->MySignal();
    // 或者使用
    // label->setParent(this);
    //锁定this窗口的大小，不能放大

    //button标签
    QPushButton* button = new QPushButton(this);
    button->setText("点击");
    button->move(200,150);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_num_clicked()
{
    emit mc1->Num(num); //当点击num之后，调用mc1函数的Num信号，并传递num数值
}

void MainWindow::on_close_num_clicked()
{
    //当点击close_num取消数字关联，参数和connect内容相同
    disconnect(mc1,&MyClass::Num,mc2,&MyClass2::NumSlot);
}
