#include "mainwindow.h"
#include <QApplication>
#include "connectionpool.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QSqlDatabase db=ConnectionPool::openConnection();
    db.exec();

    return a.exec();
}
