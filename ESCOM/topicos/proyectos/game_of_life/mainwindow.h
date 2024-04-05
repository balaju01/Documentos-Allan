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
    void propagacions();
    void evaluar(int,int,int,int);
    ~MainWindow();


private slots:
    void on_ini_pau_clicked();

    void on_life_pressed();

    void on_Diffussion_pressed();



    void on_personal_pressed();

    void on_propagacion_valueChanged(int );

    void on_comboX_currentIndexChanged(int index);

    void on_comboY_currentIndexChanged(int index);

    void on_comboW_currentIndexChanged(int index);

    void on_comboZ_currentIndexChanged(int index);

    void on_limpia_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap i;
    int regla;
    int Xx;
    int Yy;
    int W;
    int Z;
    float propa;
    int control;
};

#endif // MAINWINDOW_H
