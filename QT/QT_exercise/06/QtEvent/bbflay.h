#ifndef BBFLAY_H
#define BBFLAY_H

#include <QWidget>
#include <QPixmap>
class BBFlay : public QWidget
{
    Q_OBJECT
public:
    explicit BBFlay(QWidget *parent = nullptr);

    //封装移动函数
    void fly(int min,int max);
protected:
    //定义绘画的事件
    void paintEvent(QPaintEvent* ev);
    void timerEvent(QTimerEvent *ev);

    //处理鼠标单机之后的移动
    void mousePressEvent(QMouseEvent* ev);
    void mouseMoveEvent(QMouseEvent* ev);

    //添加鼠标闪避的功能
    void enterEvent(QEvent* ev);

signals:

public slots:

private:
    //图片载体类
    QPixmap m_pixmap;
    int m_index;
    QPoint m_pt;
};

#endif // BBFLAY_H
