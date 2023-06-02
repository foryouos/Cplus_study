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

private slots:
    void on_radioButton_13_clicked();

    void on_radioButton_11_clicked();

    void on_radioButton_12_clicked();

    void on_radioButton_10_clicked();

    void on_checkBox_14_stateChanged(int arg1);

    void on_checkBox_5_stateChanged(int arg1);

    void on_checkBox_6_stateChanged(int arg1);

    void on_checkBox_7_stateChanged(int arg1);
    // 添加槽函数, 处理复选框按钮状态变化
    void statusChanged(int state);

private:
    Ui::MainWindow *ui;
    int m_number = 0;    // 添加一个计数器, 记录有几个子节点被选中了
};

#endif // MAINWINDOW_H
