/********************************************************************************
** Form generated from reading UI file 'helloworld.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLOWORLD_H
#define UI_HELLOWORLD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_helloworld
{
public:
    QLabel *label;

    void setupUi(QDialog *helloworld)
    {
        if (helloworld->objectName().isEmpty())
            helloworld->setObjectName("helloworld");
        helloworld->resize(496, 295);
        label = new QLabel(helloworld);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 50, 351, 271));
        label->setTextFormat(Qt::MarkdownText);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        retranslateUi(helloworld);

        QMetaObject::connectSlotsByName(helloworld);
    } // setupUi

    void retranslateUi(QDialog *helloworld)
    {
        helloworld->setWindowTitle(QCoreApplication::translate("helloworld", "helloworld", nullptr));
        label->setText(QCoreApplication::translate("helloworld", "# \347\223\266\345\255\220\347\232\204\350\267\213\346\266\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class helloworld: public Ui_helloworld {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLOWORLD_H
