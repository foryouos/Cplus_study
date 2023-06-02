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
    void on_moverButtion_clicked();

    void on_positionButton_clicked();

    void on_geometryButton_clicked();

    void on_modifbtn_clicked();

    void on_modelDlg_clicked();

    void on_msgbox_clicked();

    void on_QFiledialogbtn_clicked();

    void on_fontdlg_clicked();

    void on_colordlg_clicked();

    void on_inputdlg_clicked();

    void on_processdlg_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
