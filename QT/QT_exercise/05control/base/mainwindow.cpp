#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //普通按钮没有checked属性
    ui->normalBtn->setText("我是屌丝!!");
    //图片路径
    ui->normalBtn->setIcon(QIcon(":/avatar.jpg"));
    ui->normalBtn->setIconSize(QSize(30,30));
    connect(ui->normalBtn,&QPushButton::clicked,this,[=]()
    {
        qDebug()<<"我是一个屌丝!!";
    });
    //有check属性的按钮(默认是没有check属性的
    ui->checkbtn->setCheckable(true);
    //当按钮被选中之后
    connect(ui->checkbtn,&QPushButton::toggled,this,[=](bool bl)
    {
        qDebug()<<"我是被选中的 屌丝！！当前的状态:"<<bl;
    });
    //让当前按钮与菜单关联
    ui->menuBtn->setText("你喜欢那种女孩?");
    QMenu* menu = new QMenu;
    QAction* act = menu->addAction("可爱的");
    menu->addAction("粘人的");
    menu->addAction("年轻的");
    //点击当前按钮会生成下拉菜单
    ui->menuBtn->setMenu(menu);
    connect(act,&QAction::triggered,this,[=]()
    {
        qDebug()<<"选中可爱的";
    });
    QAction* actBtn = new QAction(QIcon(":/avatar.jpg"),"奥利给");
    ui->actBtn->setDefaultAction(actBtn);//action和当前的actbtn关联到一起
    connect(ui->actBtn,&QToolButton::triggered,this,[=](QAction* act)
    {
        act->setText("我是修改后的...");
        act->setIcon(QIcon(":/avatar.jpg"));
    });
    ui->actBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);//文本信息显示到图标的下面

    //在按钮上绘制指向某个方向上的箭头
    //设置箭头的方向
    ui->arrowbtn->setArrowType(Qt::UpArrow);
    //设置显示的文本信息(QToolButton默认是不显示文本信息的)
    ui->arrowbtn->setText("向上");
    //让其显示文本信息
    ui->arrowbtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    //对popemenu的相关操作
    //默认延时显示(长点击一会)
    ui->popmenu->setMenu(menu); //将上面的menu与popmenu进行关联
    /*
    弹出菜单的弹出模式是一个枚举类型: QToolButton::ToolButtonPopupMode, 取值如下:
      - QToolButton::DelayedPopup:
          - 延时弹出, 按压工具按钮一段时间后才能弹出, 比如:浏览器的返回按钮
          - 长按按钮菜单弹出, 但是按钮的 clicked 信号不会被发射
      - QToolButton::MenuButtonPopup:
          - 在这种模式下，工具按钮会显示一个特殊的箭头，表示有菜单。(菜单会单独显示)
      - 当按下按钮的箭头部分时，将显示菜单。按下按钮部分发射 clicked 信号
      - QToolButton::InstantPopup:
          - 当按下工具按钮时，菜单立即显示出来。
          - 在这种模式下，按钮本身的动作不会被触发(不会发射clicked信号
    */
    //设置显示模式
    ui->popmenu->setPopupMode(QToolButton::DelayedPopup); //延时弹出
    connect(ui->popmenu,&QToolButton::clicked,this,[=]()
    {
        qDebug()<<"我是popMenu按钮，好痒...";
    });

    //设置默认喜欢C++为选中
    ui->radioButton_9->setChecked(true);

    //设置复选框操作
    // 设置根节点的三态属性
       ui->wives->setTristate(true);
       // 处理根节点的鼠标点击事件
       connect(ui->wives, &QCheckBox::clicked, this, [=](bool bl)
       {
           if(bl)
           {
               // 子节点全部设置为选中状态

               ui->fangyi->setChecked(true);
               ui->longer->setChecked(true);

               ui->mujianping->setChecked(true);

               ui->ake->setChecked(true);
           }
           else
           {
               // 子节点全部设置为非选中状态

               ui->fangyi->setChecked(false);
               ui->longer->setChecked(false);

               ui->mujianping->setChecked(false);

               ui->ake->setChecked(false);
           }
       });
       // 处理子节点的状态变化, 对应的槽函数相同
      connect(ui->fangyi, &QCheckBox::stateChanged, this, &MainWindow::statusChanged);
      connect(ui->longer, &QCheckBox::stateChanged, this, &MainWindow::statusChanged);
      connect(ui->mujianping, &QCheckBox::stateChanged, this, &MainWindow::statusChanged);
      connect(ui->ake, &QCheckBox::stateChanged, this, &MainWindow::statusChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioButton_13_clicked()
{
     qDebug() << "C++";
}

void MainWindow::on_radioButton_11_clicked()
{
    qDebug() << "GO";
}

void MainWindow::on_radioButton_12_clicked()
{
    qDebug() << "Python";
}

void MainWindow::on_radioButton_10_clicked()
{
    qDebug() << "Java";
}

void MainWindow::on_checkBox_14_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        //
        qDebug()<<"C++";
    }
    else {
        qDebug()<<"取消C++";
    }
}

void MainWindow::on_checkBox_5_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        //
        qDebug()<<"Go";

    }
    else {
        qDebug()<<"取消Go";
    }
}

void MainWindow::on_checkBox_6_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        //
        qDebug()<<"Python";

    }
    else{
        qDebug()<<"取消Python";
    }
}

void MainWindow::on_checkBox_7_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        //
        qDebug()<<"Java";

    }
    else {
        qDebug()<<"取消Java";
    }
}

// 槽函数
void MainWindow::statusChanged(int state)
{
    if(state == Qt::Checked)
    {
        m_number ++;	// 选中一个子节点, 计数器加1
    }
    else
    {
        m_number --;   // 取消选中一个子节点, 计数器减1
    }

    // 根据计数器值判断根节点是否需要做状态的更新
    if(m_number == 7)
    {
        ui->wives->setCheckState(Qt::Checked);
    }
    else if(m_number == 0)
    {
        ui->wives->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->wives->setCheckState(Qt::PartiallyChecked);
    }
}
