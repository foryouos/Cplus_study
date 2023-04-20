#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    PIE();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::PIE()
{
    // 创建一个QPieSeries对象并添加数据
        QPieSeries *series = new QPieSeries();
        series->append("Java", 20);
        series->append("Python", 15);
        series->append("C++", 10);

        // 创建一个QChart对象，并将QPieSeries对象添加到图表中
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Programming Languages");

        // 创建一个QChartView对象并设置图表
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        // 将QChartView对象转换为QPixmap对象
        QPixmap pixmap = chartView->grab();

        // 将QPixmap对象显示到QLabel中
        ui->label->setPixmap(pixmap);
}
