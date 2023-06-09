#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,[=]()
    {
        qDebug()<<ui->widget->getValue(); //获得当前的值，点击之后
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) //如果点击左键
    {
        qDebug()<<"左键局部坐标:"<<event->x()<<event->y();
    }
    else if (event->button() == Qt::RightButton)
    {
        qDebug()<<"右键全局坐标:"<<event->globalX()<<event->globalY(); //线束全局坐标
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event) //鼠标释放
{
    Q_UNUSED(event);
    qDebug()<<"Button is released";
}

void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    //鼠标双击
    if(event->button() == Qt::LeftButton)//左键双击
    {
        //判断是否全屏
        if(windowState()!=Qt::WindowFullScreen)
        {
            //设置全屏
            setWindowState(Qt::WindowFullScreen);
        }
        else {
            //若已经全屏，再双击会到初始状态
            setWindowState(Qt::WindowNoState);
        }
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        QPoint tmp;
        tmp = event->globalPos() - pos; //鼠标当前的位置-窗口所在的位置
        move(tmp); //移动这个差值
    }
}

void Widget::wheelEvent(QWheelEvent *event)
{
    if(event->delta() > 0) //向上滚动
    {
        ui->textEdit->zoomOut();  //字体放大
    }
    else {
        ui->textEdit->zoomIn(); //字体缩小
    }
}
