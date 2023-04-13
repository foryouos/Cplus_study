#include "video.h"
#include "ui_video.h"
#include "QFileDialog"
#include <QDebug>

video::video(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::video)
{
    ui->setupUi(this);
    //初始化
    player = new QMediaPlayer(this);
    //显示的窗体
    videowidget = new QVideoWidget(this);
    videowidget->resize(600,300);
    //播放视频
    player->setVideoOutput(videowidget);   //设置输出到哪里
    connect(player,&QMediaPlayer::durationChanged,this,&video::Get_Duration);
    //让滑动与视频时长产生关联
    connect(ui->horizontalSlider,&QSlider::valueChanged,this,&video::Slider_Changed);

    //输出所有摄像头信息
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    if(cameras.count() > 0)
    {
        foreach (const QCameraInfo &cameraInfo, cameras)
            qDebug() << cameraInfo.deviceName();
        camera = new QCamera(cameras.at(0));  //编号为第几个摄像头
    }
    viemfinder = new QCameraViewfinder(ui->camera); //创建显示的区域
    camera->setViewfinder(viemfinder);  //显示出摄像头捕获的画面
    //设置摄像头显示的大小
    viemfinder->resize(600,300);
    //用户摄像头截图
    imageCapture = new QCameraImageCapture(camera);


    camera->start();  //让摄像头开始工作


}








video::~video()
{
    delete ui;
}

//打开文件
void video::on_fileopen_clicked()
{
    //Open File为打开窗体名称
    fileName = QFileDialog::getOpenFileName(this,"Open File","..\\"); //打开文件(当前文件夹)放到fileName
    //将打开的文件作为视频播放的来源
    player->setMedia(QUrl::fromLocalFile(fileName)); //作为player的来源
    //获取视频时长
    // qDebug()<<player->duration(); //持续时间


    player->play();  //播放

}
//视频播放
void video::on_video_start_clicked()
{
    player->play(); //播放
}
//暂停

void video::on_video_pause_clicked()
{
    player->pause(); //暂停
}
//停止
void video::on_video_stop_clicked()
{
    player->stop();  //停止
}

void video::Get_Duration()
{
    //获取视频时长
    //qDebug()<<player->duration(); //持续时间
    //设置进度条最大值
    ui->horizontalSlider->setMaximum(int(player->duration()));
}

void video::Slider_Changed()
{
    pos = ui->horizontalSlider->value(); //获取当前的值
    player->setPosition(pos);  //改变播放位置


}

//画面捕获，拍照
void video::on_camera_take_clicked()
{
    camera->setCaptureMode(QCamera::CaptureStillImage);  //捕获图片
    //弹出标准对话框
    QString fileName = QFileDialog::getSaveFileName(); //保存的文件名字
    //开始进行捕获
    imageCapture->capture(fileName);  //捕获图片，保存到要保存的目录为上面对话框设定的目录

}
