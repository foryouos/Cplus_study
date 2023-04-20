#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// 添加下面这行头文件包含语句
#include <QChart>
#include <QPieSeries>
#include <QChartView>
//添头文件
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QChart *qchart;
    QPieSeries *series;
    QChartView *chartView;
    void PIE();

};

#endif // MAINWINDOW_H
