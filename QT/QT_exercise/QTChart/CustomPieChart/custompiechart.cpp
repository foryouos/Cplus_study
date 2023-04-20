#include "custompiechart.h"
#include <QDebug>
#include <QFontMetrics>
#include <qmath.h>

#define  SUPERPLUS_H       10   //悬浮状态超出高度
#define  BLANK_W           1    //各个value 间间隔
#define  DEFAULT_FONT_SIZE 40   //默认字体大小
CustomPieChart::CustomPieChart(QWidget *parent)
    : QWidget(parent), ui(new Ui::CustomPieChart)
{

    setMouseTracking(true);
    m_pieChartView = new CustomPieChart(QSize(400, 400), this);
    QGridLayout* glayout = new QGridLayout(this);
    glayout->addWidget(m_pieChartView);

    QMap<QString, int> dataMap;
    dataMap.insert("a", 24);
    dataMap.insert("b", 40);
    dataMap.insert("c", 70);
    dataMap.insert("d", 30);
    dataMap.insert("e", 50);
    dataMap.insert("f", 90);
    dataMap.insert("g", 35);
    dataMap.insert("h", 35);

    QMap<QString, QColor> colorMap;
    colorMap.insert("a", QColor("#4EEE94"));
    colorMap.insert("b", QColor("#6495ED"));
    colorMap.insert("c", QColor("#8470FF"));
    colorMap.insert("d", QColor("#FFD700"));
    colorMap.insert("e", QColor("#EE6363"));
    colorMap.insert("f", QColor("#FF1493"));
    colorMap.insert("g", QColor("#EE2C2C"));
    colorMap.insert("h", QColor("#A020F0"));

    m_pieChartView->setData(dataMap);
    m_pieChartView->setValueColor(colorMap);
    setMouseTracking(true);
    m_radius = width()/2 - SUPERPLUS_H;  //大圆的半径
    m_midR = m_radius*2/3;               //中间圆的半径
    m_centerR = m_radius/2;              //中心圆的半径
    m_fontSize = DEFAULT_FONT_SIZE;      //字体默认大小
}


CustomPieChart::CustomPieChart(const QSize &size, QWidget *parent)
    :QWidget(parent)
{
    setMouseTracking(true);
    setFixedSize(size);
    m_radius = width()/2 - SUPERPLUS_H;
    m_midR = m_radius*2/3;
    m_centerR = m_radius/2;
    m_fontSize = DEFAULT_FONT_SIZE;

}

CustomPieChart::~CustomPieChart(){}


void CustomPieChart::setThisFixedSize(const QSize &size)
{
    setFixedSize(size);
    m_radius = width()/2 - 20;
    m_midR = m_radius*2/3;
    m_centerR = m_radius/2;
    update();
}
QSize CustomPieChart::thisSize()const
{
    return size();
}

void CustomPieChart::setData(const QMap<QString, int>& dataMap)
{
    m_valueStateMap.clear();
    m_colorMap.clear();
    m_anglePairMap.clear();
    m_valueMap = dataMap;
    auto iter = m_valueMap.begin();
    for(int index = 1;iter!=m_valueMap.end();iter++){
        m_total += iter.value();
        if(index % 2 !=0)
            m_colorMap.insert(iter.key(), QColor("#ee5b5b"));
        else
            m_colorMap.insert(iter.key(), QColor("#30c1d8"));
        if(index == 1)
            m_curKey = iter.key();
        bool state = (index == 1)?true:false;
        m_valueStateMap.insert(iter.key(), state);
        index++;
    }
    if(m_colorMap.size()>0 && m_valueMap.size()>0)
        update();
}

QMap<QString, int> CustomPieChart::data()const
{
    return m_valueMap;
}

void CustomPieChart::setValueColor(const QMap<QString, QColor> &colorMap)
{
    m_colorMap = colorMap;
    if(m_colorMap.size()>0 && m_valueMap.size()>0)
        update();
}

QMap<QString, QColor> CustomPieChart::valuesColor()const
{
    return m_colorMap;
}

void CustomPieChart::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.translate(width() >> 1, height() >> 1);
    painter.setPen(Qt::NoPen);
    drawValues(&painter);      //绘制每一个扇形值区域
    drawMidRound(&painter);    //绘制中部圆
    drawCenterRound(&painter); //绘制中心圆
    drawText(&painter);        //绘制占比
}

void CustomPieChart::drawValues(QPainter *painter)
{
    auto iter = m_valueMap.begin();
    QString key = "";
    qreal value = 0.0;
    qreal startAngle = 0.0;
    qreal angleLength = 0.0;
    for(;iter!=m_valueMap.end();iter++){
        key = iter.key();
        value = iter.value();
        angleLength = (value / m_total) * 360 - BLANK_W;
        gradientArc(painter, key, startAngle, angleLength, m_colorMap[key]);
        m_anglePairMap.insert(key, QPair<qreal, qreal>(startAngle, angleLength));
        startAngle += (angleLength + BLANK_W);
    }
}

void CustomPieChart::drawMidRound(QPainter *painter)
{
    if(m_total == 0)
        return;
    QLinearGradient linear(QPointF(0, 0), QPointF(150, 150));
    linear.setColorAt(0, QColor("#c5c5c5"));
    linear.setColorAt(1, QColor("#ffffff"));
    painter->setBrush(linear);
    painter->drawEllipse(QPointF(0, 0), m_midR, m_midR);
}

void CustomPieChart::drawCenterRound(QPainter *painter)
{
    if(m_total==0)
        return;
    painter->setBrush(Qt::white);
    painter->drawEllipse(QPointF(0, 0), m_centerR, m_centerR);
}

void CustomPieChart::drawText(QPainter *painter)
{
    if(m_total==0)
        return;
    QPen pen;
    pen.setColor(QColor("#26303c"));
    pen.setWidth(3);
    painter->setPen(pen);
    painter->setFont(QFont("Source Han Sans CN", m_fontSize));
    int value = qCeil((float)m_valueMap.value(m_curKey) / (float)m_total * 100.0);
    qreal w = QFontMetrics(painter->font()).width(QObject::tr("%1%").arg(value));
    painter->drawText(-(w/2), 10, QObject::tr("%1%").arg(value));

    painter->setFont(QFont("Source Han Sans CN", m_fontSize - 16));
    w = QFontMetrics(painter->font()).width(m_curKey);
    painter->drawText(-(w/2), 40, m_curKey);
}

void CustomPieChart::gradientArc(QPainter *painter, QString key, qreal startAngle, qreal angleLength, QColor color)
{
    qreal radius = m_valueStateMap.value(key)?m_radius+SUPERPLUS_H:m_radius;
    painter->setBrush(color);
    QRectF rectf(-radius, -radius, radius * 2, radius * 2);
    QPainterPath path;
    path.arcTo(rectf, startAngle, angleLength);
    painter->drawPath(path);
}

void CustomPieChart::leaveEvent(QEvent *event)
{
    return QWidget::leaveEvent(event);
}

void CustomPieChart::mouseMoveEvent(QMouseEvent *event)
{
    QPointF pos = event->pos();
    pos = QPointF(pos.x() - m_radius, m_radius - pos.y());
    qreal l = qSqrt(qPow(pos.x(), 2)+qPow(pos.y(), 2));
    //内圆
    if(l < m_radius/2){
        m_centerR = m_radius/2 + SUPERPLUS_H;
        m_fontSize = DEFAULT_FONT_SIZE + 2;
        update();
        return QWidget::mouseMoveEvent(event);
    }
    //外圈圆
    if(l > m_radius*2/3 && l<m_radius){
        m_centerR = m_radius/2;
        m_fontSize = DEFAULT_FONT_SIZE;
        qreal rangle = getPosInAngle(pos);
        auto iter = m_anglePairMap.begin();
        for(;iter!=m_anglePairMap.end();iter++){
            QPair<qreal, qreal> value = iter.value();
            if(rangle>=value.first && rangle<=(value.first + value.second)){
                m_valueStateMap[iter.key()] = true;
                m_curKey = iter.key();
            }
            else
                m_valueStateMap[iter.key()] = false;
        }
        update();
        return QWidget::mouseMoveEvent(event);
    }
    return QWidget::mouseMoveEvent(event);
}

float CustomPieChart::getPosInAngle(QPointF pos)
{
    qreal a = qAbs(pos.y());
    qreal c = qSqrt(qPow(pos.x(), 2) + qPow(pos.y(), 2));
    qreal radians = qAsin((float)a/(float)c);
    qreal rangle = 180.0 / M_PI * radians;
    if(pos.x()>0 && pos.y()>0)
        return rangle;
    if(pos.x()<0 && pos.y()>0)
        return 180.0 - rangle;
    if(pos.x()<0 && pos.y()<0)
        return 180.0 + rangle;
    if(pos.x()>0 && pos.y()<0)
        return 360.0 - rangle;
    else
        return 0.0;
}
