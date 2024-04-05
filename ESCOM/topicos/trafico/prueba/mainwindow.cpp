#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    panimacion = new animacion(this);
    ui->areaDibujo->addWidget(panimacion);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dibujar_clicked()
{
    panimacion->mover(10,10);
}
