#include "mainwindow.h"
#include <QApplication>
#include "mydialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyDialog my;
    my.exec();

    MainWindow w;
    w.show();

    return a.exec();
}
