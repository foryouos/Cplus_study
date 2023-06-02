#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = nullptr);
    ~MyDialog();

private slots:
    void on_AcceptBtn_clicked();

    void on_RejectBtn_clicked();

    void on_DoneBtn_clicked();

private:
    Ui::MyDialog *ui;
};

#endif // MYDIALOG_H
