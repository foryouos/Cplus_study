/********************************************************************************
** Form generated from reading UI file 'custompiechart.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMPIECHART_H
#define UI_CUSTOMPIECHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomPieChart
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CustomPieChart)
    {
        if (CustomPieChart->objectName().isEmpty())
            CustomPieChart->setObjectName(QString::fromUtf8("CustomPieChart"));
        CustomPieChart->resize(799, 626);
        centralWidget = new QWidget(CustomPieChart);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        CustomPieChart->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CustomPieChart);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 799, 26));
        CustomPieChart->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CustomPieChart);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CustomPieChart->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CustomPieChart);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CustomPieChart->setStatusBar(statusBar);

        retranslateUi(CustomPieChart);

        QMetaObject::connectSlotsByName(CustomPieChart);
    } // setupUi

    void retranslateUi(QMainWindow *CustomPieChart)
    {
        CustomPieChart->setWindowTitle(QApplication::translate("CustomPieChart", "CustomPieChart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomPieChart: public Ui_CustomPieChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMPIECHART_H
