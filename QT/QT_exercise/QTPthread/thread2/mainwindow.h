#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:

    //设置开始的信号，用于给子线程传递
    void starting(int num);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
