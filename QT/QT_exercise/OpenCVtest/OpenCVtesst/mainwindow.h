#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <opencv2/opencv.hpp>
#include <QDebug>
#include "ui_mainwindow.h"
#include "thread.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
     ~MainWindow();
private slots:
     void onImageReady(cv::Mat image);
 private:
     Ui::MainWindow *ui;
     CameraThread *cameraThread;
     QLabel *label;
};

#endif // MAINWINDOW_H
