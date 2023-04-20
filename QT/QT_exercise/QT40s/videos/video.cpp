#include "video.h"
#include "ui_video.h"
#include "QFileDialog"
#include <QDebug>

video::video(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::video)
{
    ui->setupUi(this);
    //播放视频初始化
    video_Init();
    //调用摄像头初始化
    camera_Init();
    //默认使用摄像头工作
    viemfinder->setVisible(true); //显示摄像头显示区域
    camera->start();  //让摄像头开始工作


}




video::~video()
{
    delete ui;
}

void video::video_Init()
{
    //本地视频播放初始化
    //初始化
    player = new QMediaPlayer(this);
    //显示的窗体
    videowidget = new QVideoWidget(this);
//    videowidget->resize(500,250);
    videowidget->setGeometry(20, 10, 500, 282); //设置窗口位置和大小
    //播放视频
    player->setVideoOutput(videowidget);   //设置输出到哪里


    //获取视频总时长
    connect(player,&QMediaPlayer::durationChanged,this,&video::Get_Duration);

    connect(player, &QMediaPlayer::positionChanged, this, &video::On_Position_Changed);
    //Open File为打开窗体名称

    //让滑动与视频时长产生关联
    connect(ui->horizontalSlider,&QSlider::valueChanged,this,&video::Slider_Changed);
}

void video::camera_Init()
{
    //摄像头初始化
    //输出所有摄像头信息
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    if(cameras.count() > 0)
    {
        foreach (const QCameraInfo &cameraInfo, cameras)
            qDebug() << cameraInfo.deviceName();
        camera = new QCamera(cameras.at(0));  //编号为第几个摄像头
    }
    viemfinder = new QCameraViewfinder(this); //创建显示的区域
    camera->setViewfinder(viemfinder);  //显示出摄像头捕获的画面
    //设置摄像头显示的大小
    //viemfinder->resize(500,260);
    viemfinder->setGeometry(10, 10, 500, 250); //设置窗口位置和大小
    //用户摄像头截图
    imageCapture = new QCameraImageCapture(camera);
}

//打开文件
void video::on_fileopen_clicked()
{


    //判断摄像头是否工作
    //判断摄像头是否初始化

        // camera已经被定义
    if(camera->state() == QCamera::ActiveState)
    {
        camera->stop(); //停止摄像头
        viemfinder->setVisible(false); //隐藏摄像头显示区域
        player->setVideoOutput(videowidget);//将显示区域设置为文件播放的QVideoWidget
        //delete_video_Init();
        videowidget->setVisible(true); //隐藏文件播放的QVideoWidget
    }
    fileName = QFileDialog::getOpenFileName(this,"选择播放的视频文件","..\\"); //打开文件(当前文件夹)放到fileName
    //将打开的文件作为视频播放的来源
    player->setMedia(QUrl::fromLocalFile(fileName)); //作为player的来源
    //获取视频时长
    player->play();  //播放

}
//视频播放
void video::on_video_start_clicked()
{
//    qDebug()<<camera->state();
    if((camera->state() == QCamera::LoadedState) &&(cameraPaused == true) )
    {
        camera->start(); //摄像头开启
        cameraPaused = false;
    }
    else
    {
        player->play(); //视频播放
    }

}
//暂停

void video::on_video_pause_clicked()
{
    if(camera->state() == QCamera::ActiveState)
    {
        camera->stop(); //摄像头暂停
        cameraPaused = true; //设置状态变量为真
    }
    else
    {
        player->pause(); //视频播放暂停
    }

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
void video::On_Position_Changed(qint64 position)
{
    ui->horizontalSlider->setValue(int(position)); // 更新进度条的值
}

//画面捕获，拍照
void video::on_camera_take_clicked()
{
    //如果摄像头播放
    if(camera->state() == QCamera::ActiveState)
    {
        camera->setCaptureMode(QCamera::CaptureStillImage);  //捕获图片
        //弹出标准对话框
        QString fileName = QFileDialog::getSaveFileName(nullptr, QString(), QString(), QString(), nullptr, QFileDialog::DontConfirmOverwrite); //保存的文件名字
        //开始进行捕获
        imageCapture->capture(fileName);  //捕获图片，保存到要保存的目录为上面对话框设定的目录

        qDebug()<<fileName;




    }
    //如果视频播放
    else
    {

        // 保存整个屏幕为QPixmap
            QScreen *screen = QGuiApplication::primaryScreen();
            //QString filePathName = QFileDialog::getSaveFileName(); //保存的文件名字
            QString filePathName = "cut-";
            filePathName += QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss-zzz");
            filePathName += ".png";
            pixmap = screen->grabWindow(0);
//            if(!pixmap.save(filePathName,"png"))
//            {
//                qDebug()<<"cut save png failed"<<endl;
//            }

            // 计算视频的位置和大小
            qDebug()<<"Full pixmap width: "<<pixmap.width()<<" height: "<<pixmap.height()<<endl;
            QRect geo = this->geometry();
            QRect appGeo = geo; // 整个应用程序在图片中的位置。
            qDebug()<<"App x: "<<geo.x()<<" y: "<<geo.y()<<" width: "<<geo.width()<<" height: "<<geo.height()<<endl;

            geo = videowidget->geometry(); // 播放视频在图片中的位置。
            qDebug()<<"VW x: "<<geo.x()<<" y: "<<geo.y()<<" width: "<<geo.width()<<" height: "<<geo.height()<<endl;

            QWidget *centerWidget = centralWidget(); // QMainWindow在应用程序的位置
            QRect centerRect = centerWidget->geometry();
            qDebug()<<"center x: "<<centerRect.x()<<" y: "<<centerRect.y()<<" width: "<<centerRect.width()<<" height: "<<centerRect.height()<<endl;

            QRect copyGeo;
            copyGeo.setX(geo.x() + appGeo.x() + centerRect.x()); // x=三个x相加
            copyGeo.setY(geo.y() + appGeo.y() + centerRect.y());
            copyGeo.setWidth(geo.width());
            copyGeo.setHeight(geo.height());
            qDebug()<<"VW1 x: "<<copyGeo.x()<<" y: "<<copyGeo.y()<<" width: "<<copyGeo.width()<<" height: "<<copyGeo.height()<<endl;

            QPixmap pixmapCopy = pixmap.copy(copyGeo); // copy图片
            filePathName.prepend("Copy+");

            QString fileName = QFileDialog::getSaveFileName(); //保存的文件名字
            if(!pixmapCopy.save(fileName,"png"))
            {
                qDebug()<<"copy cut save png failed"<<endl;
            }
            else {
                qDebug()<<"copy cut save png successfull "<<endl;
            }

    }

}


//点击摄像头后，摄像头开始工作
void video::on_camera_button_clicked()
{

    if(player->state() == QMediaPlayer::PlayingState)
    {
        player->stop(); //停止播放文件
        videowidget->setVisible(false); //隐藏文件播放的QVideoWidget
        camera->setViewfinder(viemfinder); //将显示区域设置为摄像头捕获的QCameraViewfinder
    }
    viemfinder->setVisible(true); //显示摄像头显示区域
    camera->start();  //让摄像头开始工作
}
