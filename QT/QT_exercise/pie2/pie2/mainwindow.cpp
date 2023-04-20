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
    // 创建一个QPieSeries对象并添加数据//为每个分块设置颜色
    series = new QPieSeries();
    series->append("预约数", 20);
    series->append("入库数", 15)->setColor("#FFA500");
    series->append("剩余数", 180);
    series->setHoleSize(0.3); //设置中间 空洞大小
    series->pieSize();


    //为每个分块设置标签文字
    for(int i = 0;i<=2;i++)
    {
        slice = series->slices().at(i); //获取分块
        slice->setLabel(slice->label()+QString::asprintf(":%.0f,%.1f%%",slice->value(),slice->percentage()*100));
        connect(slice,SIGNAL(hovered(bool)),this,SLOT(on_PieSliceHighlight(bool)));

    }
    slice->setExploded(true); //最后一个设置为exploded
    series->setLabelsVisible(true);

    // 创建一个QChart对象，并将QPieSeries对象添加到图表中
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("停车场车位");
    chart->legend()->setVisible(false);//图例
    chart->legend()->setAlignment(Qt::AlignBottom);


    // 创建一个QChartView对象并设置图表
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(500,400);

    // 将QChartView对象转换为QPixmap对象
    QPixmap pixmap = chartView->grab();

    // 将QPixmap对象显示到QLabel中
    ui->label_pie->setPixmap(pixmap);
}

void MainWindow::on_PieSliceHighlight(bool show)
{
    //鼠标移入，移出时发射hovered()信号，动态设置exploed效果
    QPieSlice* slice = static_cast<QPieSlice *>(sender());
    slice->setExploded(show);
}

