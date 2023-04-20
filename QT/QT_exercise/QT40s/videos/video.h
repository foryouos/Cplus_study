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
#include <QDateTime>
#include <QtGui/QScreen>


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
    //摄像头初始化
    void camera_Init();
    //打开视频文件初始化
    void video_Init();



    void on_fileopen_clicked();

    void on_video_start_clicked();

    void on_video_pause_clicked();


    void Get_Duration();
    void Slider_Changed();
    void On_Position_Changed(qint64 position);

    void on_camera_take_clicked();

    void on_camera_button_clicked();




private:
    Ui::video *ui;
    //音频文件对象
    QMediaPlayer *player;
    //视频文件对象
    QVideoWidget *videowidget;
    QString fileName;
    int pos;
    //视频帧截屏
    QPixmap pixmap;


    //创建摄像头对象
    QCamera *camera;
    //显示摄像头的指针
    QCameraViewfinder *viemfinder;
    //捕获图片,操作用于捕获的对象
    QCameraImageCapture *imageCapture;

    //判断视频是否暂停
    bool cameraPaused = false;
};

#endif // VIDEO_H
