#include "mybutton.h"

mybutton::mybutton(QWidget *parent) : QWidget(parent)
{

}
//传参数并存入到本地
void mybutton::setImage(QString normal, QString hover, QString pressed)
{
    // 加载图片
    m_normal.load(normal);
    m_hover.load(hover);
    m_press.load(pressed);
    m_current = m_normal;
    // 设置按钮和图片大小一致
    setFixedSize(m_normal.size());
}

void mybutton::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
    // 鼠标被按下, 发射这个自定义信号
    emit clicked();
    m_current = m_press; //当前的图片编程按压的图片
    update();
}

void mybutton::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
    m_current = m_normal;
    update();
}

void mybutton::enterEvent(QEvent *ev)
{
    Q_UNUSED(ev);
    m_current = m_hover;
    update();
}

void mybutton::leaveEvent(QEvent *ev)
{
    Q_UNUSED(ev);
    m_current = m_normal;
    update();
}

void mybutton::paintEvent(QPaintEvent *ev)
{
    Q_UNUSED(ev);
    QPainter p(this);
    p.drawPixmap(rect(), m_current);
}
