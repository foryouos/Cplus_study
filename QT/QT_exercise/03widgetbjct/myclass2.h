#ifndef MYCLASS2_H
#define MYCLASS2_H
#include <QDebug>
#include <QObject>

class MyClass2 : public QObject
{
    Q_OBJECT
public:
    explicit MyClass2(QObject *parent = nullptr);

signals:

public slots:
    void MySlot(void); //槽函数，需要实现
    void NumSlot(int& num); //信号函数实现数值+
};

#endif // MYCLASS2_H
