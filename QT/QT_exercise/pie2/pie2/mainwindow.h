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
private slots:
    //槽函数
    void on_PieSliceHighlight(bool show);

private:
    Ui::MainWindow *ui;
    QChart *qchart;
    QPieSeries *series;
    QChartView *chartView;
    //获取分块
    QPieSlice *slice;  //饼图分块
    void PIE();

};

#endif // MAINWINDOW_H
