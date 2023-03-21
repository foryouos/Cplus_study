#ifndef QMYCLASS_H
#define QMYCLASS_H

#include <QWidget>

class QMyClass : public QWidget
{
    Q_OBJECT
public:
    explicit QMyClass(QWidget *parent = nullptr);
    ~QMyClass(); //作为判断析构函数是否被调用到
signals:

};

#endif // QMYCLASS_H
