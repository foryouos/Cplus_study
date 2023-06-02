#include "flay.h"
#include <QPainter>
#include <QMouseEvent>
#include <QRandomGenerator> //生成随机数
#include <QApplication>
#include <QDesktopWidget>
#include <QGuiApplication>
#include <QScreen>
Flay::Flay(QWidget *parent) : QWidget(parent)
{
    //加载首个图片
    m_pixmap.load(m_photo_name);
    //动态，添加定时器定时的切换位置
    setFixedSize(QSize(300,300));
    startTimer(300);

}

void Flay::load_photo(QString photo,QString photo_change)
{
    m_photo_name = photo;
    m_photo_change = photo_change;

}

//飞的不同位置
void Flay::fly(int min, int max)
{
//    m_index++;
//    if(m_index >2)
//    {
//        m_index = 1;
//    }
    //QString name = QString(":/image/bbx0%1.png").arg(m_index); //拼接图片
    //QString name = QString(m_photo_change);  //使用原始图片
    m_pixmap.load(m_photo_change); //重新加载图片
    update();//强制窗口刷新

    int stepX = QRandomGenerator::global()->bounded(min,max);
    int stepY = QRandomGenerator::global()->bounded(min,max);
    //要移动到的坐标点
    int curX= this->geometry().topLeft().x() + stepX;
    int curY = this->geometry().topLeft().y()+stepY;

    //右边界
//    QDesktopWidget* desk = QApplication::desktop();
//    if(curX >= desk->screenGeometry().right() )
//    {
//        curX = desk->screenGeometry().left();
//    }
//    if(curY >= desk->screenGeometry().bottom() )
//    {
//        curY = desk->screenGeometry().top();
//    }
    QRect screenRect = QGuiApplication::screens().at(0)->geometry();
    if(curX >= screenRect.right())
    {
    curX = screenRect.left();
    }
    if(curY >= screenRect.bottom())
    {
    curY = screenRect.top();
    }



    move(curX,curY);
}

void Flay::paintEvent(QPaintEvent *ev)
{
    Q_UNUSED(ev);
    //将01图片画出来
    QPainter P(this);
    P.drawPixmap(rect(),m_pixmap);

}
//会启动定时器
void Flay::timerEvent(QTimerEvent *ev)
{
    Q_UNUSED(ev);
    //调用移动函数
    fly(10,30);
}

void Flay::mousePressEvent(QMouseEvent *ev)
{
    //当鼠标左键按下 //获取按压的点
    if(ev->button() == Qt::LeftButton)
    {
        //使用 全局坐标globalPos
        m_pt = ev->globalPos()-this->geometry().topLeft(); //计算点击的点与左上角的距离
    }
}

void Flay::mouseMoveEvent(QMouseEvent *ev)
{
    //当鼠标左键按下 //buttons是个持续的状态
    if(ev->buttons() == Qt::LeftButton)
    {
        this->move(ev->globalPos()-m_pt); //将鼠标移动的点减去差点，让其会到左上角正确的位置
    }
}

void Flay::enterEvent(QEvent *ev)
{
    Q_UNUSED(ev);
    //移动的不够远解决方案
    fly(-200,200);
}
