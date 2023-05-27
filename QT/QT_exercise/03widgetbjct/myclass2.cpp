#include "myclass2.h"

MyClass2::MyClass2(QObject *parent) : QObject(parent)
{

}

void MyClass2::MySlot()
{
    //调用MySignal槽函数实现
    qDebug()<<"调用了MysSignal槽函数";
}

void MyClass2::NumSlot(int& num)
{
    num ++;
    qDebug()<<"num: "<<num;
}
