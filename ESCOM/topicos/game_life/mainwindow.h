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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void regla();

private slots:
    void on_difucion_clicked();

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_arboles_clicked();

private:
    Ui::MainWindow *ui;
    int x,y,z,w;
    double dif;


};

#endif // MAINWINDOW_H
