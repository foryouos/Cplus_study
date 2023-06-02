#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
class mybutton : public QWidget
{
    Q_OBJECT
public:
    explicit mybutton(QWidget *parent = nullptr);

    void setImage(QString normal, QString hover, QString pressed);

protected:
    void mousePressEvent(QMouseEvent* ev);
    void mouseReleaseEvent(QMouseEvent* ev);
    void enterEvent(QEvent* ev);
    void leaveEvent(QEvent* ev);
    void paintEvent(QPaintEvent* ev);


signals:
    void clicked();

private:
    //图片类
    QPixmap m_normal;
    QPixmap m_press;
    QPixmap m_hover;
    QPixmap m_current;
};

#endif // MYBUTTON_H
