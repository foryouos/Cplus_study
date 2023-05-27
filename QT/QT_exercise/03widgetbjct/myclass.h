#ifndef MYCLASS_H
#define MYCLASS_H

#include <QMainWindow>
#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT
public:
    explicit MyClass(QObject *parent = nullptr);

signals: //信号，
    void MySignal(void); //不需要实现，调用信号使用emit 信号函数即可
    void Num(int& num); //信号函数实现数值+

public slots: //槽

};

#endif // MYCLASS_H
