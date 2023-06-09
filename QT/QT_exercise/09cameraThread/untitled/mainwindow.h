#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include <QFileDialog>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgproc/types_c.h"
#include "camera.h"
using namespace std;
using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
     ~MainWindow();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void updateImage(QImage);
    void updateImage2(QImage image);
private:
    Ui::MainWindow *ui;
protected:
    void closeEvent(QCloseEvent *event)  Q_DECL_OVERRIDE;
signals:
    void cameraOperate(int);  //运行摄像头信号
    Camera* camera;
    QThread thread;
};

#endif // MAINWINDOW_H

