/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *start;
    QWidget *widget;
    QGroupBox *groupBox;
    QListWidget *randlist;
    QGroupBox *groupBox_2;
    QListWidget *bubblelist;
    QGroupBox *groupBox_3;
    QListWidget *quicklist;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(895, 688);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        start = new QPushButton(centralWidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(350, 550, 141, 71));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 0, 811, 501));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 211, 471));
        randlist = new QListWidget(groupBox);
        randlist->setObjectName(QString::fromUtf8("randlist"));
        randlist->setGeometry(QRect(10, 30, 181, 421));
        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(290, 10, 211, 471));
        bubblelist = new QListWidget(groupBox_2);
        bubblelist->setObjectName(QString::fromUtf8("bubblelist"));
        bubblelist->setGeometry(QRect(10, 40, 181, 421));
        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(570, 10, 211, 471));
        quicklist = new QListWidget(groupBox_3);
        quicklist->setObjectName(QString::fromUtf8("quicklist"));
        quicklist->setGeometry(QRect(20, 40, 181, 421));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 895, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(start, randlist);
        QWidget::setTabOrder(randlist, bubblelist);
        QWidget::setTabOrder(bubblelist, quicklist);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        start->setText(QApplication::translate("MainWindow", "\351\232\217\346\234\272", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\351\232\217\346\234\272\346\225\260", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\206\222\346\263\241\346\216\222\345\272\217", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\345\277\253\351\200\237\346\216\222\345\272\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
