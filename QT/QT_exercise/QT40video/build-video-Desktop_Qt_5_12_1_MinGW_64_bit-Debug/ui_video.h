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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_video
{
public:
    QAction *actionhei;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QScrollBar *horizontalScrollBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *video)
    {
        if (video->objectName().isEmpty())
            video->setObjectName(QString::fromUtf8("video"));
        video->resize(587, 556);
        actionhei = new QAction(video);
        actionhei->setObjectName(QString::fromUtf8("actionhei"));
        centralWidget = new QWidget(video);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 340, 91, 51));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 340, 101, 51));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(280, 340, 101, 51));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(420, 340, 91, 51));
        horizontalScrollBar = new QScrollBar(centralWidget);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(90, 440, 401, 16));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        video->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(video);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 587, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        video->setMenuBar(menuBar);
        mainToolBar = new QToolBar(video);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        video->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(video);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        video->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());

        retranslateUi(video);

        QMetaObject::connectSlotsByName(video);
    } // setupUi

    void retranslateUi(QMainWindow *video)
    {
        video->setWindowTitle(QApplication::translate("video", "video", nullptr));
        actionhei->setText(QApplication::translate("video", "hei", nullptr));
        pushButton->setText(QApplication::translate("video", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        pushButton_2->setText(QApplication::translate("video", "\346\222\255\346\224\276", nullptr));
        pushButton_3->setText(QApplication::translate("video", "\346\232\202\345\201\234", nullptr));
        pushButton_4->setText(QApplication::translate("video", "\345\201\234\346\255\242", nullptr));
        menu->setTitle(QApplication::translate("video", "\346\222\255\346\224\276\350\247\206\351\242\221", nullptr));
        menu_2->setTitle(QApplication::translate("video", "\347\254\254\344\272\214\344\270\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class video: public Ui_video {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEO_H
