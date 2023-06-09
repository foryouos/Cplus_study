#include "my_control.h"
#include "ui_my_control.h"

My_control::My_control(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::My_control)
{
    ui->setupUi(this);
    //让两个基础控件进行关联
    //spinBox与horizontalSlider关联
    void(QSpinBox:: *sbp)(int) = &QSpinBox::valueChanged;  //QSpinBox有函数重载，函数指针指向int重载
    connect(ui->spinBox,sbp,ui->horizontalSlider,&QSlider::setValue);
    //让horizontalSlider与spinBox关联
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);



}

My_control::~My_control()
{
    delete ui;
}

int My_control::getValue()
{
    return ui->spinBox->value();
}
