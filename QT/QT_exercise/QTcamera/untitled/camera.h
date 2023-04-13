#ifndef CAMERA_H
#define CAMERA_H

#include <QMainWindow>

namespace Ui {
class camera;
}

class camera : public QMainWindow
{
    Q_OBJECT

public:
    explicit camera(QWidget *parent = nullptr);
    ~camera();

private:
    Ui::camera *ui;
};

#endif // CAMERA_H
