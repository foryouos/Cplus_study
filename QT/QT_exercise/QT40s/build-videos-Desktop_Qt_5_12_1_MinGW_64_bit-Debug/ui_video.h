/********************************************************************************
** Form generated from reading UI file 'video.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEO_H
#define UI_VIDEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_video
{
public:
    QWidget *centralWidget;
    QSlider *horizontalSlider;
    QPushButton *video_start;
    QPushButton *camera_take;
    QPushButton *fileopen;
    QPushButton *video_pause;
    QPushButton *camera_button;
    QLabel *screen_label;

    void setupUi(QMainWindow *video)
    {
        if (video->objectName().isEmpty())
            video->setObjectName(QString::fromUtf8("video"));
        video->resize(1204, 596);
        video->setCursor(QCursor(Qt::ArrowCursor));
        video->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralWidget = new QWidget(video);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(20, 300, 471, 17));
        horizontalSlider->setStyleSheet(QString::fromUtf8("/* \351\234\200\350\246\201\345\205\210\350\256\276\347\275\256groove\357\274\214\346\260\264\345\271\263\346\273\221\345\212\250\346\235\241*/\n"
"QSlider#customSlider::groove:horizontal {\n"
"    border: none;\n"
"    height: 6px;\n"
"    border-radius: 3px;\n"
"    background: lightgray;\n"
"}\n"
"QSlider#customSlider::handle:horizontal {\n"
"    border: none;\n"
"    margin: -5px 0px; /* \344\270\212\344\270\213\350\276\271\350\267\235\345\222\214\345\267\246\345\217\263\350\276\271\350\267\235*/\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    border-radius: 8px;\n"
"    background: #e83c3c;\n"
"    border-image: url(:/images/white.png);\n"
"}\n"
"/*\345\210\222\350\277\207\351\203\250\345\210\206*/\n"
"QSlider#customSlider::sub-page:horizontal {\n"
"    background: red;\n"
"    height: 4px;\n"
"    border-radius: 3px;\n"
"}\n"
"/*\346\234\252\345\210\222\350\277\207\351\203\250\345\210\206*/\n"
"QSlider#customSlider::add-page:horizontal {\n"
"    background: lightgray;\n"
"    height: 4px;\n"
"    bord"
                        "er-radius: 3px;\n"
"}\n"
""));
        horizontalSlider->setOrientation(Qt::Horizontal);
        video_start = new QPushButton(centralWidget);
        video_start->setObjectName(QString::fromUtf8("video_start"));
        video_start->setGeometry(QRect(400, 520, 101, 51));
        camera_take = new QPushButton(centralWidget);
        camera_take->setObjectName(QString::fromUtf8("camera_take"));
        camera_take->setGeometry(QRect(210, 520, 91, 51));
        fileopen = new QPushButton(centralWidget);
        fileopen->setObjectName(QString::fromUtf8("fileopen"));
        fileopen->setGeometry(QRect(30, 370, 91, 51));
        video_pause = new QPushButton(centralWidget);
        video_pause->setObjectName(QString::fromUtf8("video_pause"));
        video_pause->setGeometry(QRect(30, 520, 101, 51));
        camera_button = new QPushButton(centralWidget);
        camera_button->setObjectName(QString::fromUtf8("camera_button"));
        camera_button->setGeometry(QRect(400, 370, 91, 51));
        screen_label = new QLabel(centralWidget);
        screen_label->setObjectName(QString::fromUtf8("screen_label"));
        screen_label->setGeometry(QRect(160, 360, 211, 121));
        video->setCentralWidget(centralWidget);

        retranslateUi(video);

        QMetaObject::connectSlotsByName(video);
    } // setupUi

    void retranslateUi(QMainWindow *video)
    {
        video->setWindowTitle(QApplication::translate("video", "video", nullptr));
        video_start->setText(QApplication::translate("video", "\346\222\255\346\224\276", nullptr));
        camera_take->setText(QApplication::translate("video", "\346\210\252\345\217\226\347\205\247\347\211\207", nullptr));
        fileopen->setText(QApplication::translate("video", "\350\247\206\351\242\221", nullptr));
        video_pause->setText(QApplication::translate("video", "\346\232\202\345\201\234", nullptr));
        camera_button->setText(QApplication::translate("video", "\346\221\204\345\203\217\345\244\264", nullptr));
        screen_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class video: public Ui_video {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEO_H
