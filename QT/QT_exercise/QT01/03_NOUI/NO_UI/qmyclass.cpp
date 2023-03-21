#include "qmyclass.h"
#include <QDebug>  //输出内容头文件
QMyClass::QMyClass(QWidget *parent)
    : QWidget{parent}
{

}
QMyClass::~QMyClass()
{
    //QT打印内容,qDebug输出内容
    qDebug() << "delete myclass"; //当手动关系窗口，析构函数被调用
}
