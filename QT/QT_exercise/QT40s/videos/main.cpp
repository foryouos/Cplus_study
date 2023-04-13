#include "video.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    video w;
    w.show();

    return a.exec();
}
