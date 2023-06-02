#include "mainwindow.h"
#include <QMessageBox>
#include "ui_mainwindow.h"
#include <QDebug>
#include "mydialog.h"
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <QPainter>
#include <QInputDialog>
#include <QProgressDialog>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置窗口最大尺寸,不计算标题栏
    //setMaximumSize(600,600);
    //设置窗口最小尺寸
    //setMinimumSize(300,300);
    //设置窗口固定尺寸
    //setFixedSize(300,300);
    //设置窗口标题
    setWindowTitle("QWidget");
    //给显示的窗口设置图标
    setWindowIcon(QIcon("e:\\ico.png"));


    //当用户修改图标之后，connect对信号进行处理,title是window改变之后，会传递的titile
    connect(this,&MainWindow::windowTitleChanged,this,[](const QString &title){
        qDebug()<<"新的标题"<<title;
    });
    //当用户修改图标之后，connect对信号进行处理,title是window改变之后，会传递的titile
    connect(this,&MainWindow::windowIconChanged,this,[](const QIcon &icon){
        qDebug()<<"图标被改变";
    });

    //设置窗口右键菜单
    //设置右键菜单策略
    setContextMenuPolicy(Qt::CustomContextMenu);//点击了窗口之后，会发射一个信号，参数是CustomContextMenu
    //连接一下被点击之后的事件,参数为鼠标按下去的点
    connect(this,&MainWindow::customContextMenuRequested,this,[](const QPoint &pos)
    {
        //创建菜单对象
        QMenu menu;
        //添加参加项
        menu.addAction("西红柿");
        menu.addAction("黄瓜");
        menu.addAction("茄子");
        //显示菜单,以及显示菜单的位置，即用到上面传递的参数
        menu.exec(QCursor::pos());
    });

    //添加connect操作，当用户点击窗口之后，做出相关的操作
    connect(ui->save_action,&QAction::triggered,this,[=]()
    {
       QMessageBox::information(this,"clicked","你不要通过保存文件调戏我...");
    });
    connect(ui->open_action,&QAction::triggered,this,[=]()
    {
       QMessageBox::information(this,"clicked","你不要通过打开文件调戏我...");
    });
    //给当前的工具栏添加按钮和单行的输入框
    //添加输入框
    QLineEdit* edit = new QLineEdit;
    edit->setMaximumWidth(200); //设置它的最大宽度
    ui->toolBar->addWidget(edit);
    ui->toolBar->addWidget(new QPushButton("搜索"));

    //添加第二个工具栏
    QToolBar* toolbar = new QToolBar("toolbar");
    this->addToolBar(Qt::LeftToolBarArea,toolbar);
    //状态栏添加子控件‘
    ui->statusBar->showMessage("...........我是状态栏....",3000); //显示3秒
    //按钮
    QPushButton* button = new QPushButton("按钮");
    ui->statusBar->addWidget(button);
    //标签
    QLabel* label = new QLabel("hello word");
    ui->statusBar->addWidget(label);
    //也可在状态栏显示对应的文本信息,会和上面的信息叠加，若放到上面会覆盖创建的
    //ui->statusBar->showMessage("...........我是状态栏....");
    //根据时间让我是状态栏关闭，然后显示出按钮和label
    QTimer::singleShot(5000,this,[=]() //5秒之后再显示出来
    {
        button->show();
        label->show();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_moverButtion_clicked()
{

    //得到左上角的坐标
    QRect rect = this->frameGeometry();
    //移动窗口 ,从当前的左上角左面，移动x右10，y下20
    move(rect.topLeft()+QPoint(10,20));
}

void MainWindow::on_positionButton_clicked()
{
    //获取当前窗体的位置信息
    QRect rect = this->frameGeometry();
    qDebug() <<"左上角"<<rect.topLeft()
             << "右上角: " << rect.topRight()
             << "左下角: " << rect.bottomLeft()
             << "右下角: " << rect.bottomRight()
             << "宽度: " << rect.width()
             << "高度: " << rect.height();
}

void MainWindow::on_geometryButton_clicked()
{
    int x = 100 + rand() % 500;
    int y = 100 + rand() % 500;
    int width= this->width()+10;
    int height = this->height()+10;
    //设置当前窗口的位置以及长度和宽度
    setGeometry(x,y,width,height);


}

void MainWindow::on_modifbtn_clicked()
{
    //修改图标
    setWindowTitle("你好，世界");
    //修改图标
    setWindowIcon(QIcon("e:\\avatar.jpg"));
}
//点击窗体显示mydialog的模块对话框
void MainWindow::on_modelDlg_clicked()
{
    //顶级对话框
    MyDialog dlg;
    connect(&dlg,&MyDialog::finished,this,[=](int res) //finish会传递一个int值
    {
        qDebug()<<"result"<<res;
    });
    connect(&dlg,&MyDialog::accepted,this,[=]() //finish会传递一个int值
    {
        qDebug()<<"accepted 信号被发射...";
    });
    connect(&dlg,&MyDialog::rejected,this,[=]() //finish会传递一个int值
    {
        qDebug()<<"rejected 信号被发射...";
    });
    int ret = dlg.exec();
    //根据不同点击，传递的不同值
    if(ret == QDialog::Accepted)
    {
        qDebug()<<"accept button clicked ...";
    }
    else if (ret == QDialog::Rejected) {
        qDebug()<<"reject button clicked ...";
    }
    else {
        qDebug()<<"done button clicked";
    }

}

void MainWindow::on_msgbox_clicked()
{
    QMessageBox::about(this, "about",  "这是一个简单的消息提示框!!!");
   QMessageBox::critical(this, "critical", "这是一个错误对话框-critical...");
   int ret = QMessageBox::question(this, "question",
            "你要保存修改的文件内容吗???",
             QMessageBox::Save|QMessageBox::Cancel,
             QMessageBox::Cancel);
   if(ret == QMessageBox::Save)  //根据不同的点击值，返回不同的值
   {
       QMessageBox::information(this, "information", "恭喜你保存成功了, o(*￣︶￣*)o!!!");
   }
   else if(ret == QMessageBox::Cancel)
   {
       QMessageBox::warning(this, "warning", "你放弃了保存, ┭┮﹏┭┮ !!!");
   }

}
//获取文件
void MainWindow::on_QFiledialogbtn_clicked()
{
    //打开已经存在的目录，e:\\temp"起始
    QString dirName = QFileDialog::getExistingDirectory(this, "打开目录", "e:\\");
    QMessageBox::information(this, "打开目录", "您选择的目录是: " + dirName);

    //打开txt文件
//    QString arg("Text files (*.txt)");
//    QString fileName = QFileDialog::getOpenFileName(
//             this, "Open File", "e:\\temp",
//             "Images (*.png *.jpg);;Text files (*.txt)", &arg);
//    QMessageBox::information(this, "打开文件", "您选择的文件是: " + fileName);

    //打开多个本地文件
//    QStringList fileNames = QFileDialog::getOpenFileNames(
//                 this, "Open File", "e:\\temp",
//                 "Images (*.png *.jpg);;Text files (*.txt)");
//    QString names;
//    for(int i=0; i<fileNames.size(); ++i)
//    {
//        names += fileNames.at(i) + " ";
//    }
//    QMessageBox::information(this, "打开文件(s)", "您选择的文件是: " + names);

    //打开保存文件对话框,将文件报错到选中的文件中
    //QString fileName = QFileDialog::getSaveFileName(this, "保存文件", "e:\\temp");
    //QMessageBox::information(this, "保存文件", "您指定的保存数据的文件是: " + fileName);
}

void MainWindow::on_fontdlg_clicked()
{
    //弹出字体对话框
#if 1
    // 方式1
    bool ok; //变量传参， //ok为返回值，修改后，为True
    //初始化字体，默认字体，我们可以自己修改
    //this父对象
    //
    QFont ft = QFontDialog::getFont(
                &ok, QFont("微软雅黑", 12, QFont::Bold), this, "选择字体");
    qDebug() << "ok value is: " << ok;
#else
    // 方式2
    QFont ft = QFontDialog::getFont(NULL);
#endif
    // 将选择的字体设置给当前窗口对象
    //将 设置的字体应用到选定的ui对象上
    ui->fontlabel->setFont(ft);
    //设置全局
    //this->setFont(ft);


}
//设置当颜色点击后
void MainWindow::on_colordlg_clicked()
{
    //调用 QColor的静态函数，参数有默认值
   QColor color = QColorDialog::getColor();
   //Qt绘图操作
   QBrush brush(color);
   QRect rect(0, 0, ui->color->width(), ui->color->height());
   QPixmap pix(rect.width(), rect.height());
   QPainter p(&pix);
   p.fillRect(rect, brush);
   ui->color->setPixmap(pix);
   QString text = QString("red: %1, green: %2, blue: %3, 透明度: %4")
           .arg(color.red()).arg(color.green()).arg(color.blue()).arg(color.alpha());
   ui->colorlabel->setText(text);
}
//点击进入输入框
void MainWindow::on_inputdlg_clicked()
{
    //getInt
    //年龄标题
    //你的当前年龄:窗口信息
    //10为默认整形数
    //1为最小值，100为最大值，2为步长
//    int ret = QInputDialog::getInt(this, "年龄", "您的当前年龄: ", 10, 1, 100, 2);
//    QMessageBox::information(this, "年龄", "您的当前年龄: " + QString::number(ret));
    //getDouble 2为精度，还有个步长的重载
//    double ret = QInputDialog::getDouble(this, "工资", "您的工资: ", 2000, 1000, 6000, 2);
//    QMessageBox::information(this, "工资", "您的当前工资: " + QString::number(ret));
    //getItem
//    QStringList items; //字符串列表，动态 字符串数组
//    items << "苹果" << "橙子" << "橘子" << "葡萄" << "香蕉" << "哈密瓜";
//    //items指定下拉选择框，1默认选择第一个(QStringList以0开始)，false为数据不可修改，true数据可以修改
//    QString item = QInputDialog::getItem(this, "请选择你喜欢的水果", "你最喜欢的水果:", items, 1, false);
//    QMessageBox::information(this, "水果", "您最喜欢的水果是: " + item);

    //password以密码的形式输入时显示小圆点
//    QString text = QInputDialog::getText(this,"密码","请输入密码",QLineEdit::Password,"helloword");
//    QMessageBox::information(this, "密码", "您输入的密码是: " + text);
    //输入多行信息
    QString info = QInputDialog::getMultiLineText(this, "表白", "您最想对漂亮小姐姐说什么呢?", "呦吼吼...");
    QMessageBox::information(this, "知心姐姐", "您最想对小姐姐说: " + info);


}
//设置进度条
void MainWindow::on_processdlg_clicked()
{
    //1,创建进度条的对话框窗口对象
    //this当前窗口的父对象初始化和现实窗口
    QProgressDialog* progress = new QProgressDialog(
                "正在拷贝数据....","取消拷贝",0,100,this);
    //2,初始化并显示进度条窗口
    progress->setWindowTitle("请稍后...");
    //设置模态显示，在显示进度条时，是否可以点击主窗口
    //在显示进度条窗口时，不可以控制主窗口
    progress->setWindowModality(Qt::WindowModal);

    //3，展示当前窗口
    progress->show();
    //4，更新进度条
    QTimer* timer = new QTimer(this);

    static int value =0;
    connect(timer,&QTimer::timeout,this,[=]()
    {
        progress->setValue(value);
        value++;
        if(value > progress->maximum())
        {
            timer->stop();
            value = 0;
        }
    });
    //当进度条点击取消之后，取消时间进程以及进度条
    connect(progress, &QProgressDialog::canceled, this, [=]()
    {
        timer->stop();
        value = 0;
        delete progress;
        delete timer;
    });
    timer->start(50);
    //进度条每隔50毫秒更新一次
}
