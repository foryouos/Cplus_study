/********************************************************************************
** Form generated from reading UI file 'mydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *AcceptBtn;
    QPushButton *RejectBtn;
    QPushButton *DoneBtn;

    void setupUi(QDialog *MyDialog)
    {
        if (MyDialog->objectName().isEmpty())
            MyDialog->setObjectName(QString::fromUtf8("MyDialog"));
        MyDialog->resize(782, 551);
        widget = new QWidget(MyDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(130, 80, 481, 381));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        AcceptBtn = new QPushButton(widget);
        AcceptBtn->setObjectName(QString::fromUtf8("AcceptBtn"));

        verticalLayout->addWidget(AcceptBtn);

        RejectBtn = new QPushButton(widget);
        RejectBtn->setObjectName(QString::fromUtf8("RejectBtn"));

        verticalLayout->addWidget(RejectBtn);

        DoneBtn = new QPushButton(widget);
        DoneBtn->setObjectName(QString::fromUtf8("DoneBtn"));

        verticalLayout->addWidget(DoneBtn);


        retranslateUi(MyDialog);

        QMetaObject::connectSlotsByName(MyDialog);
    } // setupUi

    void retranslateUi(QDialog *MyDialog)
    {
        MyDialog->setWindowTitle(QApplication::translate("MyDialog", "Dialog", nullptr));
        AcceptBtn->setText(QApplication::translate("MyDialog", "Accept", nullptr));
        RejectBtn->setText(QApplication::translate("MyDialog", "Reject", nullptr));
        DoneBtn->setText(QApplication::translate("MyDialog", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyDialog: public Ui_MyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H
