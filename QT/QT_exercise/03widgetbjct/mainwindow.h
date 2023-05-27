#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myclass.h"
#include "myclass2.h"
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
    void on_num_clicked();

    void on_close_num_clicked();

private:
    Ui::MainWindow *ui;
    MyClass * mc1;
    MyClass2 * mc2;
    int num =0;

};

#endif // MAINWINDOW_H
