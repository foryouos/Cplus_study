#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "flay.h"
#include <QRandomGenerator>
#include <QResizeEvent>
#include <QDebug>
#include <QCloseEvent>
#include <QLabel>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Flay* win = new Flay(this);
    win->load_photo(":/xinke/0.jpg",":/xinke/1.jpg");
    //位于中心位置
    win->move((width() - win->width())/2,(height()-win->height())/2);

    //去掉主窗口的边框，并透明
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    //设置窗口透明
    setAttribute(Qt::WA_TranslucentBackground);
    //当前窗口最大化
    showMaximized();
    //循环多个bbfly对象
    for(int i =0;i<50;i++)
    {
        Flay* win = new Flay(this);
        QString name = QString(":/xinke/%1.jpg").arg(i);
        win->load_photo(name,name);
        //让每个蝴蝶的起点不一样
        win->move(QRandomGenerator::global()->bounded(this->width()),QRandomGenerator::global()->bounded(this->height()));
        win->show();
    }

    //将轮播需要的照片传递到参数当中
    for(int i =0;i<=42;i++)
    {
        QString name = QString(":/xinke/%1.jpg").arg(i);
        imageList.append(name);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{



    //当关闭窗口时调用的
    QMessageBox msgBox;
    msgBox.setWindowTitle("新科六窝窝图片墙");
     //利用时间定时器来进行照片的轮播显示，其实就是更新图片
//    QLabel* label = new QLabel(&msgBox);
//    label->setFixedSize(200,200);
//    label->setAlignment(Qt::AlignLeft); //图片位于左边显示

    QTimer* timer = new QTimer(&msgBox); //时间计时器
    connect(timer,&QTimer::timeout,[&]()
    {
        static int index = 0; //选择图片，每次选择一个，使用静态变量

        QPixmap pixmap(imageList[index]);
        //图片适应大小
        pixmap = pixmap.scaled(QSize(200,200), Qt::IgnoreAspectRatio); // 缩放图片
        msgBox.setIconPixmap(pixmap); //设置为图片
        index++;
       //如果达到最大，会到0index
        if(index >= imageList.size())
        {
            index = 0;
        }
    });
    timer->start(2000); //启动计时器2秒
    //设置退出的ICON图片
    msgBox.setIconPixmap(QPixmap(":/image/bbx01.png"));//加载图片作为图片显示
    msgBox.setText("新科七窝窝各位小伙伴们:\n\n\t前路漫漫，戴口罩的大学就此结束啦,祝各位在新的人生路途上，以天下为己任，努力成长为堪当民族复兴大任的时代新人.虽前路艰难，但只要思想不滑坡，方法总比困难多，奥利给！");
    //msgBox.setInformativeText("");

    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setButtonText(QMessageBox::Yes, "后会有期");
    msgBox.setButtonText(QMessageBox::No, "没有退路");

    int ret = msgBox.exec(); //
    if (ret == QMessageBox::Yes) {
        //接收并处理这个事件
        event->accept();
    } else {
        //忽略这个事件
        event->ignore();
        //设置成都是退出
        //event->accept();
    }
}
