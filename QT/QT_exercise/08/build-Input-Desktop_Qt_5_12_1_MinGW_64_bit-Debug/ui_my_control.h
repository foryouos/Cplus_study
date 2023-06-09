/********************************************************************************
** Form generated from reading UI file 'my_control.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MY_CONTROL_H
#define UI_MY_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_My_control
{
public:
    QSlider *horizontalSlider;
    QSpinBox *spinBox;

    void setupUi(QWidget *My_control)
    {
        if (My_control->objectName().isEmpty())
            My_control->setObjectName(QString::fromUtf8("My_control"));
        My_control->resize(278, 59);
        horizontalSlider = new QSlider(My_control);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(100, 20, 160, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        spinBox = new QSpinBox(My_control);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(20, 20, 46, 22));

        retranslateUi(My_control);

        QMetaObject::connectSlotsByName(My_control);
    } // setupUi

    void retranslateUi(QWidget *My_control)
    {
        My_control->setWindowTitle(QApplication::translate("My_control", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class My_control: public Ui_My_control {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MY_CONTROL_H
