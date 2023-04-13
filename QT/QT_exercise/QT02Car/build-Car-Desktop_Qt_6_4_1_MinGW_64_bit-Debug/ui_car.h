/********************************************************************************
** Form generated from reading UI file 'car.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAR_H
#define UI_CAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Car
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Car)
    {
        if (Car->objectName().isEmpty())
            Car->setObjectName("Car");
        Car->resize(800, 600);
        centralwidget = new QWidget(Car);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(290, 10, 181, 71));
        QFont font;
        font.setPointSize(26);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        Car->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Car);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Car->setMenuBar(menubar);
        statusbar = new QStatusBar(Car);
        statusbar->setObjectName("statusbar");
        Car->setStatusBar(statusbar);

        retranslateUi(Car);

        QMetaObject::connectSlotsByName(Car);
    } // setupUi

    void retranslateUi(QMainWindow *Car)
    {
        Car->setWindowTitle(QCoreApplication::translate("Car", "Car", nullptr));
        label->setText(QCoreApplication::translate("Car", "\350\275\246\347\211\214\350\257\206\345\210\253", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Car: public Ui_Car {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAR_H
