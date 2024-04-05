#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qfiledialog.h>
#include <stdio.h>
#include <stdlib.h>
#include <qdebug.h>
#include "fstream"

using namespace std;

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

void MainWindow::on_pushButton_2_clicked()
{

    //QString filename=QFileDialog::getOpenFileName(this,tr("Open File"),"/home","All files (*.*)",);
    QFileDialog *pr = new QFileDialog(this);
    QStringList fileName;
    int num;
    QString mensage;
    pr->setDirectory(QDir::homePath());
    pr->setFileMode(QFileDialog::ExistingFiles);
    pr->setNameFilter("All files (*.*)");
    if ( pr->exec() == QDialog::Accepted ){
        fileName = pr->selectedFiles();}
    ui->eSpera->addItems(fileName);
    this->pen=this->pen+fileName;
    num=ui->eSpera->count();
    mensage=QString::number(num);
    ui->statusBar->showMessage("Archivos pendientes: "+mensage);
    this->NoarchPen=num;
}

void MainWindow::on_eSpera_itemSelectionChanged()
{
    QList<QListWidgetItem *> ok;
    QString va,mensaj;
    int n;
    ok=ui->eSpera->selectedItems();
    n=ok.count();
    this->selecCion.clear();
    for(int i=0;i<n;i++)
    {
        va=ok[i]->text();
        this->selecCion<<va;
        qDebug()<<va<<" "<<i<<" "<<n<<" "<<(this->selecCion.count());
    }
    mensaj="Archivos pendientes: "+(QString::number(this->NoarchPen))+" Archivos Seleccionados para envio: "+(QString::number(n));
    ui->statusBar->showMessage(mensaj);
}

void MainWindow::on_pushButton_clicked()
{
    fstream archivo;
    archivo.open((((this->selecCion[0]).toStdString()).c_str()),ios::in);
    char f[100];
    if(!archivo)
        qDebug()<<"no se pudo quesque dice que no lo encuentra";
    else
    {
        archivo.getline(f,15);
        qDebug()<<f;
    }
}
