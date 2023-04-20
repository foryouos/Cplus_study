#include <QCoreApplication>
#include <opencv2/opencv.hpp>
#include "include/easypr.h"
#include <QDebug>

using namespace easypr;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"加载断点";
    // 1. 加载车牌识别模型
    CPlateRecognize pr;
    pr.LoadSVM("E://Cstudy//QT//QT_exercise//easyPR//easypr2//model//svm_hist.xml");
    qDebug()<<"AVM";
    pr.LoadANN("E://Cstudy//QT//QT_exercise//easyPR//easypr2//model//ann.xml");
    qDebug()<<"ANN";
    pr.LoadChineseANN("E://Cstudy//QT//QT_exercise//easyPR//easypr2//model//ann_chinese.xml");
    qDebug()<<"ChineseANN";

    // new in v1.6
    pr.LoadGrayChANN("E://Cstudy//QT//QT_exercise//easyPR//easypr2//model//annCh.xml");
    pr.LoadChineseMapping("E://Cstudy//QT//QT_exercise//easyPR//easypr2//model//province_mapping");
    // 2. 读入待识别的车牌图片
    cv::Mat src = cv::imread("D://car.png");

    // 3. 车牌识别
    std::vector<CPlate> plates;

    pr.plateRecognize(src, plates);

    // 4. 输出识别结果
    for (auto plate : plates) {
        std::cout << "plate: " << plate.getPlateStr() << std::endl;
    }

    return a.exec();
}
