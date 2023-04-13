#ifndef VIDEO_H
#define VIDEO_H

//QCamera ：打开摄像头设备
//QCameraInfo :和摄像头有关的信息和属性
//QCameraViewfinder:用于显示摄像头捕获的画面
//QCameraImageCapture：用于摄像头截图

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>

#include <QCamera>
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QFileDialog>
namespace Ui {
class video;
}

class video : public QMainWindow
{
    Q_OBJECT

public:
    explicit video(QWidget *parent = nullptr);
    ~video();

private slots:
    void on_fileopen_clicked();

    void on_video_start_clicked();

    void on_video_pause_clicked();

    void on_video_stop_clicked();

    void Get_Duration();
    void Slider_Changed();

    void on_camera_take_clicked();

private:
    Ui::video *ui;
    //音频文件对象
    QMediaPlayer *player;
    //视频文件对象
    QVideoWidget *videowidget;
    QString fileName;
    int pos;


    //创建摄像头对象
    QCamera *camera;
    //显示摄像头的指针
    QCameraViewfinder *viemfinder;
    //捕获图片,操作用于捕获的对象
    QCameraImageCapture *imageCapture;
};

#endif // VIDEO_H
