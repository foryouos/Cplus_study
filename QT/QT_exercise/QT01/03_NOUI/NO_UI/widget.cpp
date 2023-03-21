#include "widget.h"
#include <QLabel>
#include <QPushButton>
#include "qmyclass.h" //引用刚才自己创建的类
//对象树//窗口部件的销毁也会相应销毁子部件label等内容申请的空间
//所以只需申请new而无需delete
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //让其窗口隶属于父类1,2,3
    //请求Qlabel空间
    QLabel *label = new QLabel(this); //3,直接带参数，直接隶属于其父类
    //设立text文件
    label->setText("I Love You,XinXin");
    //设置位置
    label->move(150,100);

    //c创建按钮,但并未有操作功能
    QPushButton *button = new QPushButton(this);
    button->setText("Close");
    button->move(150,180);

    //当窗口被关闭后，QMyClass的析构函数也被自动调用
    //只需写new，无需再手动写含delete的内容
    QMyClass *myclass = new QMyClass(this);


    //1,此形式呈现会呈现在独立的窗口
    //label->show();

    //2,让label隶属于其父类
    //label->setParent(this);

    //指定窗体的大小
    resize(400,300);
    //锁定大小,不可改变
    //setFixedSize(400,300);

    setWindowTitle("My First No UI");

}

Widget::~Widget()
{
    //

}

