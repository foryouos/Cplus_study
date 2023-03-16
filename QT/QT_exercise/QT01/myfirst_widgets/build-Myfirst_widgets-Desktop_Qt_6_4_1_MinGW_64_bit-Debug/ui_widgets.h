/********************************************************************************
** Form generated from reading UI file 'widgets.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETS_H
#define UI_WIDGETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widgets
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *widgets)
    {
        if (widgets->objectName().isEmpty())
            widgets->setObjectName("widgets");
        widgets->resize(753, 437);
        label = new QLabel(widgets);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 120, 291, 61));
        label->setTextFormat(Qt::MarkdownText);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        pushButton = new QPushButton(widgets);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 230, 121, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        font.setPointSize(8);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(widgets);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(440, 240, 91, 41));
        QFont font1;
        font1.setPointSize(11);
        pushButton_2->setFont(font1);

        retranslateUi(widgets);
        QObject::connect(pushButton_2, &QPushButton::clicked, widgets, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(widgets);
    } // setupUi

    void retranslateUi(QWidget *widgets)
    {
        widgets->setWindowTitle(QCoreApplication::translate("widgets", "widgets", nullptr));
        label->setText(QCoreApplication::translate("widgets", "# \347\223\266\345\255\220\347\232\204\350\267\213\346\266\211", nullptr));
        pushButton->setText(QCoreApplication::translate("widgets", "I love you,YU", nullptr));
        pushButton_2->setText(QCoreApplication::translate("widgets", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widgets: public Ui_widgets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETS_H
