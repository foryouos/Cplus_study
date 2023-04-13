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
    QLabel *camera;
    QPushButton *fileopen;
    QPushButton *video_stop;
    QPushButton *video_pause;
    QPushButton *camera_button;

    void setupUi(QMainWindow *video)
    {
        if (video->objectName().isEmpty())
            video->setObjectName(QString::fromUtf8("video"));
        video->resize(1204, 596);
        centralWidget = new QWidget(video);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(100, 320, 441, 41));
        horizontalSlider->setOrientation(Qt::Horizontal);
        video_start = new QPushButton(centralWidget);
        video_start->setObjectName(QString::fromUtf8("video_start"));
        video_start->setGeometry(QRect(100, 520, 101, 51));
        camera_take = new QPushButton(centralWidget);
        camera_take->setObjectName(QString::fromUtf8("camera_take"));
        camera_take->setGeometry(QRect(790, 390, 91, 51));
        camera = new QLabel(centralWidget);
        camera->setObjectName(QString::fromUtf8("camera"));
        camera->setGeometry(QRect(560, 20, 631, 321));
        fileopen = new QPushButton(centralWidget);
        fileopen->setObjectName(QString::fromUtf8("fileopen"));
        fileopen->setGeometry(QRect(130, 400, 91, 51));
        video_stop = new QPushButton(centralWidget);
        video_stop->setObjectName(QString::fromUtf8("video_stop"));
        video_stop->setGeometry(QRect(260, 520, 91, 51));
        video_pause = new QPushButton(centralWidget);
        video_pause->setObjectName(QString::fromUtf8("video_pause"));
        video_pause->setGeometry(QRect(420, 510, 101, 51));
        camera_button = new QPushButton(centralWidget);
        camera_button->setObjectName(QString::fromUtf8("camera_button"));
        camera_button->setGeometry(QRect(640, 390, 91, 51));
        video->setCentralWidget(centralWidget);

        retranslateUi(video);

        QMetaObject::connectSlotsByName(video);
    } // setupUi

    void retranslateUi(QMainWindow *video)
    {
        video->setWindowTitle(QApplication::translate("video", "video", nullptr));
        video_start->setText(QApplication::translate("video", "\346\222\255\346\224\276", nullptr));
        camera_take->setText(QApplication::translate("video", "\346\213\215\347\205\247", nullptr));
        camera->setText(QString());
        fileopen->setText(QApplication::translate("video", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        video_stop->setText(QApplication::translate("video", "\345\201\234\346\255\242", nullptr));
        video_pause->setText(QApplication::translate("video", "\346\232\202\345\201\234", nullptr));
        camera_button->setText(QApplication::translate("video", "\346\221\204\345\203\217\345\244\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class video: public Ui_video {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEO_H
