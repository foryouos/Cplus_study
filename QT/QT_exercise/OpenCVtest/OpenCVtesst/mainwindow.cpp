#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cameraThread = new CameraThread(this);
    connect(cameraThread, &CameraThread::imageReady, this, &MainWindow::onImageReady);
    cameraThread->start();
    qDebug()<<cameraThread->currentThread();
    setCentralWidget(ui->camera);
}

MainWindow::~MainWindow() {
    cameraThread->requestInterruption();
    cameraThread->wait();
}

void MainWindow::onImageReady(cv::Mat image)
{

    if (image.empty()) {
        // 处理摄像头读取失败的情况
        return;
    }
    // 将OpenCV的Mat类型转换Qt的QImage 类型
    //QImage qImage((const uchar*)image.data, image.cols, image.rows, QImage::Format_RGB888);
    QImage qImg(image.data, image.cols, image.rows, static_cast<int>(image.step), QImage::Format_RGB888);
    // 将 QImage 显示在 QLabel 中
    cv::cvtColor(image, image, CV_BGR2RGB);

    ui->camera->setPixmap(QPixmap::fromImage(qImg));


}



