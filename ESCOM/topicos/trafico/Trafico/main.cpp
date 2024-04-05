#include "mainwindow.h"
#include <QApplication>
#include <qdebug.h>
#include <iostream>
#include "carro.h"
const int tam=7;
const int p=0;

using namespace std;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

