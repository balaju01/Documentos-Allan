#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "animacion.h"
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

private slots:
    void on_dibujar_clicked();

private:
    Ui::MainWindow *ui;
    animacion *panimacion;

};

#endif // MAINWINDOW_H
