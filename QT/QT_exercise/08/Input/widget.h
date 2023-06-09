#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void mousePressEvent(QMouseEvent* event);//鼠标点击事件
    void mouseReleaseEvent(QMouseEvent* event); //鼠标释放事件
    void mouseDoubleClickEvent(QMouseEvent* event); //鼠标双击事件
    void mouseMoveEvent(QMouseEvent* event); //鼠标移动 //实现移动窗口的效果
    //滚轮方法输入的文字
    void wheelEvent(QWheelEvent *event);

private:
    Ui::Widget *ui;
    QPoint pos;
};

#endif // WIDGET_H
