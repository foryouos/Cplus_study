#include "mydialog.h"
#include "ui_mydialog.h"
MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_AcceptBtn_clicked()
{
    //解除当前模态对话框的阻塞，隐藏当前窗口
    this->accept();
}

void MyDialog::on_RejectBtn_clicked()
{
     //解除当前模态对话框的阻塞，隐藏当前窗口
    this->reject();

}

void MyDialog::on_DoneBtn_clicked()
{
    //关闭窗口，其值可以指定
    this->done(10);//此值为finished的返回值，一一对应
}
