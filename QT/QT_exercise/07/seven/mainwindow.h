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
protected:
    //关闭窗口的事件
    void closeEvent(QCloseEvent* event);
private:
    Ui::MainWindow *ui;
    QStringList imageList;// 存储关闭页面的轮播照片
};

#endif // MAINWINDOW_H
