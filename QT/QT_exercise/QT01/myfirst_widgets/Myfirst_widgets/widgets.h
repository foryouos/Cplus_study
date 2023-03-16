#ifndef WIDGETS_H
#define WIDGETS_H

#include <QWidget>

QT_BEGIN_NAMESPACE
//命名空间Ui里面的widgets类
namespace Ui { class widgets; }
QT_END_NAMESPACE
//此widgets与上面命名空间的ui里的widgets不同，在不同的命名空间
class widgets : public QWidget //来自Qwidget基类
{
    //宏，使用QT的信号与槽都要使用到此宏
    Q_OBJECT

public:
    //构造函数和析构函数
    widgets(QWidget *parent = nullptr);
    ~widgets();

private:
    //私有成员ui命名空间里面的widgets
    Ui::widgets *ui;
};
#endif // WIDGETS_H
