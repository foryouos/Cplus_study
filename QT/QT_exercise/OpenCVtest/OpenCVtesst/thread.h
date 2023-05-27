#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QMainWindow>
#include <QThread>
#include <opencv2/opencv.hpp>
#include <QDebug>
#include "ui_mainwindow.h"

class CameraThread : public QThread {
    Q_OBJECT
public:
    CameraThread(QObject *parent = nullptr) : QThread(parent) {}
signals:
    void imageReady(cv::Mat image);
protected:
    void run() override {
        cv::VideoCapture cap(0);
        if (!cap.isOpened()) {
            emit imageReady(cv::Mat());
            return;
        }
        while (!isInterruptionRequested()) {
            cv::Mat frame;
            if (!cap.read(frame)) {
                emit imageReady(cv::Mat());
                break;
            }
            emit imageReady(frame);
        }
    }
};




#endif // THREAD_H
