#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "animacion.h"
#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Calculo();
    int carrCercano(int);
    void cambio(carro []);
    void propagacion();


private slots:
    void on_Dibujar_clicked();
    void animar();

    void on_Propagacion_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_spinBox_valueChanged(int arg1);

    void on_limpia_clicked();

private:
    Ui::MainWindow *ui;
    animacion *panimacion;
    carro *carr;
    int c,propa;
    int p;
    int vmax;
    int vv;
    QTimer *cronometro;
};

#endif // MAINWINDOW_H
