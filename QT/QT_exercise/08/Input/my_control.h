#ifndef MY_CONTROL_H
#define MY_CONTROL_H

#include <QWidget>

namespace Ui {
class My_control;
}

class My_control : public QWidget
{
    Q_OBJECT

public:
    explicit My_control(QWidget *parent = nullptr);
    ~My_control();

    int getValue();

private:
    Ui::My_control *ui;
};

#endif // MY_CONTROL_H
