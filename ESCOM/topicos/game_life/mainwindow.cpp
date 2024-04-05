#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::regla()
{

}

void MainWindow::on_difucion_clicked()
{
    
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    this->dif=arg1;
}

void MainWindow::on_arboles_clicked()
{
    QGraphicsEllipseItem **ot;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsEllipseItem *rectangle;
    QGraphicsEllipseItem *text;
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QBrush brush(Qt::red);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);

    rectangle = scene->addEllipse(-450, -250, 60, 60, outlinePen, blueBrush);

    // addEllipse(x,y,w,h,pen,brush)
    ellipse = scene->addEllipse(-350, -250, 60, 60, outlinePen, greenBrush);

    text = scene->addEllipse(0, 0, 60, 60, outlinePen, brush);
        // movable text
    text->setFlag(QGraphicsItem::ItemIsMovable);
}
