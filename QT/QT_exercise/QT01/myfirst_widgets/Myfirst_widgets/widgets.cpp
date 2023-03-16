#include "widgets.h"
#include "ui_widgets.h"

widgets::widgets(QWidget *parent)
    : QWidget(parent), ui(new Ui::widgets) //开辟类内存空间
{
    //调用setupUi，
    ui->setupUi(this); //实现窗口的各种空间属性，信号与槽关联等
}

widgets::~widgets()
{
    // 析构函数释放new的空间
    delete ui;
}

