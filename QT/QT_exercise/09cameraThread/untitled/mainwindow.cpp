#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //固定当前窗口
    this->setFixedSize(this->size());
    this->setWindowTitle("多线程摄像头OpenCV");
    //获得当前的摄像头数量
    for(int i=0;i<Camera::getCameraCount();)
        //将摄像头数量呈现到comboBox里面
        ui->comboBox->addItem("摄像头:  "+QString::number(++i));


    camera=new Camera();
    camera->moveToThread(&thread); //将camera对象放在子线程，不推荐放在主线程执行。
    //信号与槽
    //向主函数的选择的摄像头编号，传递给子函数
    connect(this, SIGNAL(cameraOperate(int)), camera, SLOT(Operate(int))); //camera的槽函数将在thread所在的线程执行
    //将camera线程的信号传递过来的QImage，传递给主线程
    connect(camera, SIGNAL(updateImage(QImage)), this, SLOT(updateImage(QImage))); //将采集的图像传入主线程（UI线程）
    connect(camera, SIGNAL(updateImage(QImage)), this, SLOT(updateImage2(QImage))); //将采集的图像传入主线程（UI线程）
    //默认启动进程
    thread.start(); //来时运行线程
    emit cameraOperate(ui->comboBox->currentIndex()); //运行选中的摄像头编号


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() //打开相机或关闭相机
{
    if(ui->pushButton->text()=="Open")
    {
        ui->pushButton->setText("Close");
        thread.start(); //来时运行线程
        emit cameraOperate(ui->comboBox->currentIndex()); //运行选中的摄像头编号
    }
    else{
        ui->pushButton->setText("Open");
        thread.terminate(); //关闭当前线程
        camera->close();
    }
}

void MainWindow::on_pushButton_2_clicked() //截图，并显示在主界面上
{
    QImage image=camera->Mat2QImage(camera->matnow).scaled(ui->label_2->width(),ui->label_2->height(),Qt::KeepAspectRatio);
    ui->label_2->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::updateImage(QImage image)
{
    //将子线程传递过来的图片呈现到label上面
    ui->label->setPixmap(QPixmap::fromImage(image));
}



void MainWindow::closeEvent(QCloseEvent *event) //在关闭事件中退出子线程，并关闭相机，结束应用程序
{
    int ret=QMessageBox::information(this,"System Quit","If you want to quit?",QMessageBox::Yes|QMessageBox::No);
    if(ret==QMessageBox::Yes){
        thread.terminate();
        camera->close();
        event->accept();
        qApp->exit();
    }
    else
        event->ignore();
}
//保存图片到本地
//void MainWindow::on_pushButton_3_clicked()
//{
//    //获取保存的文件
//    QString filename=QFileDialog::getSaveFileName(this,tr("Save Image"),QDir::homePath(),tr("(*.jpg)\n(*.bmp)\n(*.png)"));
//    //输出保存的目录
//    qDebug()<<""<<filename;
//    //
//    if(!filename.isEmpty() && !camera->Mat2QImage(camera->matnow).isNull()){
//        camera->Mat2QImage(camera->matnow).save(filename);
//        ui->statusBar->showMessage(tr("Save Image Success!"),3000);
//    }
//    else{
//        ui->statusBar->showMessage(tr("Save Image Cancel!"),3000);
//    }
//}
