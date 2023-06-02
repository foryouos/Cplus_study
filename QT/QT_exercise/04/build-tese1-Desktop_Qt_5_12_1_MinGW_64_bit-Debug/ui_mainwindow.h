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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *open_action;
    QAction *save_action;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *modifbtn;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QPushButton *QFiledialogbtn;
    QSpacerItem *verticalSpacer_2;
    QPushButton *processdlg;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QPushButton *moverButtion;
    QPushButton *positionButton;
    QPushButton *geometryButton;
    QGroupBox *groupBox_3;
    QPushButton *inputdlg;
    QPushButton *modelDlg;
    QPushButton *msgbox;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QPushButton *fontdlg;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_4;
    QLabel *fontlabel;
    QSpacerItem *verticalSpacer_5;
    QGroupBox *groupBox_2;
    QPushButton *colordlg;
    QLabel *colorlabel;
    QLabel *color;
    QMenuBar *menuBar;
    QMenu *menu_QT;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1087, 692);
        open_action = new QAction(MainWindow);
        open_action->setObjectName(QString::fromUtf8("open_action"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../ico.png"), QSize(), QIcon::Normal, QIcon::Off);
        open_action->setIcon(icon);
        save_action = new QAction(MainWindow);
        save_action->setObjectName(QString::fromUtf8("save_action"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../../../avatar.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        save_action->setIcon(icon1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 2, 1, 1);

        modifbtn = new QPushButton(centralWidget);
        modifbtn->setObjectName(QString::fromUtf8("modifbtn"));

        gridLayout->addWidget(modifbtn, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);

        QFiledialogbtn = new QPushButton(centralWidget);
        QFiledialogbtn->setObjectName(QString::fromUtf8("QFiledialogbtn"));

        gridLayout->addWidget(QFiledialogbtn, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 8, 1, 1, 1);

        processdlg = new QPushButton(centralWidget);
        processdlg->setObjectName(QString::fromUtf8("processdlg"));

        gridLayout->addWidget(processdlg, 2, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        moverButtion = new QPushButton(centralWidget);
        moverButtion->setObjectName(QString::fromUtf8("moverButtion"));

        verticalLayout->addWidget(moverButtion);

        positionButton = new QPushButton(centralWidget);
        positionButton->setObjectName(QString::fromUtf8("positionButton"));

        verticalLayout->addWidget(positionButton);

        geometryButton = new QPushButton(centralWidget);
        geometryButton->setObjectName(QString::fromUtf8("geometryButton"));
        geometryButton->setIconSize(QSize(53, 53));

        verticalLayout->addWidget(geometryButton);


        gridLayout->addLayout(verticalLayout, 4, 1, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(0, 176));
        inputdlg = new QPushButton(groupBox_3);
        inputdlg->setObjectName(QString::fromUtf8("inputdlg"));
        inputdlg->setGeometry(QRect(70, 60, 131, 31));

        gridLayout->addWidget(groupBox_3, 3, 0, 1, 1);

        modelDlg = new QPushButton(centralWidget);
        modelDlg->setObjectName(QString::fromUtf8("modelDlg"));

        gridLayout->addWidget(modelDlg, 6, 2, 1, 1);

        msgbox = new QPushButton(centralWidget);
        msgbox->setObjectName(QString::fromUtf8("msgbox"));

        gridLayout->addWidget(msgbox, 5, 2, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        fontdlg = new QPushButton(groupBox);
        fontdlg->setObjectName(QString::fromUtf8("fontdlg"));

        verticalLayout_2->addWidget(fontdlg);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        fontlabel = new QLabel(groupBox);
        fontlabel->setObjectName(QString::fromUtf8("fontlabel"));
        fontlabel->setScaledContents(false);
        fontlabel->setTextInteractionFlags(Qt::TextBrowserInteraction);

        verticalLayout_2->addWidget(fontlabel);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);


        gridLayout->addWidget(groupBox, 8, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        colordlg = new QPushButton(groupBox_2);
        colordlg->setObjectName(QString::fromUtf8("colordlg"));
        colordlg->setGeometry(QRect(60, 70, 161, 31));
        colorlabel = new QLabel(groupBox_2);
        colorlabel->setObjectName(QString::fromUtf8("colorlabel"));
        colorlabel->setGeometry(QRect(60, 180, 351, 61));
        color = new QLabel(groupBox_2);
        color->setObjectName(QString::fromUtf8("color"));
        color->setGeometry(QRect(280, 70, 121, 31));

        gridLayout->addWidget(groupBox_2, 7, 2, 2, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1087, 26));
        menu_QT = new QMenu(menuBar);
        menu_QT->setObjectName(QString::fromUtf8("menu_QT"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        dockWidget_2 = new QDockWidget(MainWindow);
        dockWidget_2->setObjectName(QString::fromUtf8("dockWidget_2"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        dockWidgetContents_2->setContextMenuPolicy(Qt::DefaultContextMenu);
        dockWidget_2->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_2);

        menuBar->addAction(menu_QT->menuAction());
        menuBar->addAction(menu->menuAction());
        menu->addAction(open_action);
        menu->addSeparator();
        menu->addAction(save_action);
        toolBar->addAction(open_action);
        toolBar->addAction(save_action);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        open_action->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
#ifndef QT_NO_TOOLTIP
        open_action->setToolTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
#endif // QT_NO_TOOLTIP
        save_action->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#ifndef QT_NO_TOOLTIP
        save_action->setToolTip(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
#endif // QT_NO_TOOLTIP
        modifbtn->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\346\240\207\351\242\230\345\222\214\345\233\276\346\240\207", nullptr));
        QFiledialogbtn->setText(QApplication::translate("MainWindow", "QFIleDialog", nullptr));
        processdlg->setText(QApplication::translate("MainWindow", "\350\277\233\345\272\246\346\235\241", nullptr));
        moverButtion->setText(QApplication::translate("MainWindow", "\347\247\273\345\212\250\347\252\227\345\217\243", nullptr));
        positionButton->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\344\275\215\347\275\256\344\277\241\346\201\257", nullptr));
        geometryButton->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\347\252\227\345\217\243\344\275\215\347\275\256\345\222\214\345\260\272\345\257\270\344\277\241\346\201\257", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256\350\276\223\345\205\245\346\241\206", nullptr));
        inputdlg->setText(QApplication::translate("MainWindow", "QInputDialog", nullptr));
        modelDlg->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\346\250\241\345\235\227\345\257\271\350\257\235\346\241\206", nullptr));
        msgbox->setText(QApplication::translate("MainWindow", "QMessageBox", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\345\255\227\344\275\223\351\200\211\346\213\251", nullptr));
        fontdlg->setText(QApplication::translate("MainWindow", "QFontDialog", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\351\242\234\350\211\262", nullptr));
        fontlabel->setText(QApplication::translate("MainWindow", "\351\242\234\350\211\262\345\217\230\345\214\226", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\351\242\234\350\211\262\351\200\211\346\213\251", nullptr));
        colordlg->setText(QApplication::translate("MainWindow", "QColorDialog", nullptr));
        colorlabel->setText(QString());
        color->setText(QString());
        menu_QT->setTitle(QApplication::translate("MainWindow", "\345\255\246\344\271\240QT", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
