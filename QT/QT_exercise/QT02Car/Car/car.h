#ifndef CAR_H
#define CAR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Car; }
QT_END_NAMESPACE

class Car : public QMainWindow
{
    Q_OBJECT

public:
    Car(QWidget *parent = nullptr);
    ~Car();

private:
    Ui::Car *ui;
};
#endif // CAR_H
