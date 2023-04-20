#include "custompiechart.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CustomPieChart w;
    w.show();

    return a.exec();
}
