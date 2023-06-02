#include "bbflay.h"
#include <QPainter>
#include <QMouseEvent>
#include <QRandomGenerator> //生成随机数
#include <QApplication>
#include <QDesktopWidget>
BBFlay::BBFlay(QWidget *parent) : QWidget(parent)
{
    m_pixmap.load(":/bbx01.png");
    //动态，添加定时器定时的切换位置
    setFixedSize(m_pixmap.size());
    startTimer(100);
}

void BBFlay::fly(int min, int max)
{
    m_index++;
    if(m_index >2)
    {
        m_index = 1;
    }
    QString name = QString(":/bbx0%1.png").arg(m_index); //拼接图片
    m_pixmap.load(name); //重新加载图片
    update();//强制窗口刷新

    int stepX = QRandomGenerator::global()->bounded(min,max);
    int stepY = QRandomGenerator::global()->bounded(min,max);
    //要移动到的坐标点
    int curX= this->geometry().topLeft().x() + stepX;
    int curY = this->geometry().topLeft().y()+stepY;

    //右边界
    QDesktopWidget* desk = QApplication::desktop();
    if(curX >= desk->screenGeometry().right() )
    {
        curX = desk->screenGeometry().left();
    }
    if(curY >= desk->screenGeometry().bottom() )
    {
        curY = desk->screenGeometry().top();
    }
    move(curX,curY);
}

void BBFlay::paintEvent(QPaintEvent *ev)
{
    Q_UNUSED(ev);
    //将01图片画出来
    QPainter P(this);
    P.drawPixmap(rect(),m_pixmap);

}
//会启动定时器
void BBFlay::timerEvent(QTimerEvent *ev)
{
    Q_UNUSED(ev);
    //调用移动函数
    fly(10,30);
}

void BBFlay::mousePressEvent(QMouseEvent *ev)
{
    //当鼠标左键按下 //获取按压的点
    if(ev->button() == Qt::LeftButton)
    {
        //使用 全局坐标globalPos
        m_pt = ev->globalPos()-this->geometry().topLeft(); //计算点击的点与左上角的距离
    }
}

void BBFlay::mouseMoveEvent(QMouseEvent *ev)
{
    //当鼠标左键按下 //buttons是个持续的状态
    if(ev->buttons() == Qt::LeftButton)
    {
        this->move(ev->globalPos()-m_pt); //将鼠标移动的点减去差点，让其会到左上角正确的位置
    }
}

void BBFlay::enterEvent(QEvent *ev)
{
    Q_UNUSED(ev);
    //移动的不够远解决方案
    fly(-200,200);
}
