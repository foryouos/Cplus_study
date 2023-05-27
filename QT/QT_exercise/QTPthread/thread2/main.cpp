#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //注册模板函数，使其支持QVector<int>
    qRegisterMetaType<QVector<int>>("QVector<int>");
    //主线程动作
    MainWindow w;
    w.show();

    return a.exec();
}
