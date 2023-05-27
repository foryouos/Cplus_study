#include "mainwindow.h"

#include <mainwindow.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<cv::Mat>("cv::Mat");

    //文件存在启动主程序
    MainWindow *w = new MainWindow;
    w->show();






    return a.exec();
}


