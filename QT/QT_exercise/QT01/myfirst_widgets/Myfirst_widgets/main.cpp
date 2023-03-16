#include "widgets.h"

#include <QApplication>  //qt的标准应用程序，QT必须有得

int main(int argc, char *argv[])
{
    //a为当前QT的应用程序的对象
    QApplication a(argc, argv);
    //widgets创建w对象
    widgets w;
    //w调用show方法，显示窗体
    w.show();
    //a为qt的应用程序，返回让qt执行起来
    return a.exec();
}
