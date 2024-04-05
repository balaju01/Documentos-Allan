#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <qdebug.h>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //qDebug()<<"si jala";
    return a.exec();
}
