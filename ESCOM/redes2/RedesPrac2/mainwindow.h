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


private slots:
    void on_pushButton_2_clicked();


    void on_eSpera_itemSelectionChanged();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QStringList pen,selecCion;
    int NoarchPen;
};

#endif // MAINWINDOW_H
