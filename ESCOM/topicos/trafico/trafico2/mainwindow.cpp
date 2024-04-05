#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "carro.h"
#include <qdebug.h>

const int tam=67;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    carr = new carro*[tam];
    for(int j=0;j<tam;j++)
    {
        carr[j]=new carro[5];
    }
    panimacion = new animacion(this,tam);
    ui->areaDibujo->addWidget(panimacion);
    panimacion->dar_d(carr);
    c=0;
    propa=2;
    p=0;
    vmax=0;
    vv=1;
    /*carr[0].dar_V(0);
    carr[0].dar_X(1);
    carr[1].dar_V(0);
    carr[1].dar_X(2);
    carr[5].dar_V(2);
    carr[5].dar_X(3);*/
    cronometro=new QTimer(this);
    connect(cronometro,SIGNAL(timeout()),this,SLOT(animar()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Dibujar_clicked()
{
    if(cronometro->isActive())
    {
        cronometro->stop();
    }
    else
    {
        //qDebug()<<"activa cronometro";
        cronometro->start(vv);
    }
}

void MainWindow::Calculo()
{
    //qDebug()<<"entrando a calcular";
    int v=0,auxx=0,x,pr;
    carro **aux=new carro*[tam];
    for(int j=0;j<tam;j++)
    {
        aux[j]=new carro[5];
    }
    //qDebug()<<"variables listas";
    for(int o=0;o<tam;o++)
    {
        //qDebug()<<o;
        for(int oo=0;oo<5;oo++)
        {
            //qDebug()<<"    "<<oo;
            v=carr[o][oo].res_V();
            auxx=v;
            //p=1;
            if(v!=-1)
            {
                if((v+1)<vmax)
                {
                    v=v+1;
                }
                else
                {
                    v=vmax;
                }
                x=carrCercano(o,oo);
                //cout << "\n" << x <<"\n";

                if(x<v)
                {
                    v=x;
                }

                if(p!=0)
                {
                    pr=rand() % 100;
                    if(pr<=p)
                    {
                        if(v-1>0)
                        {
                            v=v-1;
                        }
                        else
                        {
                            v=0;
                        }
                    }
                }

                aux[(o+v)%tam][oo].dar_V(v);
                aux[(o+v)%tam][oo].dar_X((carr[o][oo].res_X()));
            }
        }
    }
    cambio(aux);
}

int MainWindow::carrCercano(int x,int y)
{
    //qDebug()<< x << " x \n";
    int c=(x+1)%tam;
    int d=0;
    //qDebug()<< c << " c\n";
    while((carr[c][y].res_V())==-1)
    {
        //qDebug()<< c << "," << v[c].res_V() << "distancia" << d <<"si entro \n";
        c=(c+1)%tam;
        d++;
    }
    //qDebug()<< c << "contiene" << v[c].res_V()<< "distancia" << d <<"\n";
    //qDebug()<<"distacia" << d << "\n";
    return d;
}

void MainWindow::cambio(carro **ax)
{
    for(int o=0;o<tam;o++)
    {
        for(int oo=0;oo<5;oo++)
        {
            carr[o][oo]=ax[o][oo];
            ax[o][oo].dar_V(-1);
            ax[o][oo].dar_X(0);
        }
    }
}

void MainWindow::animar()
{
    //panimacion->mover(10,10);

    if(c==0)
    {
        //qDebug()<<"anima antes de propagar";
        propagacion();
        //qDebug()<<"dibuja";
        panimacion->dar_d(carr);
        panimacion->repaint();
        c++;
    }
    else
    {
        //qDebug()<<"listos a calcular";
        Calculo();
        //qDebug()<<"dibujando";
        panimacion->dar_d(carr);
        panimacion->repaint();
    }
}

void MainWindow::on_Propagacion_valueChanged(int arg1)
{
    this->propa=arg1;
}

void MainWindow::propagacion()
{
    //qDebug()<<"propaga";
    float pip=tam*5;
    pip=pip/100;
    int de=pip*(this->propa);
    int c=0;
    int dd=0;
    int ax=de;
    qDebug()<<pip<<"  "<<this->propa<<"   "<<de;
    while(de!=0)
    {
        c=rand()%tam;
        dd=rand()%tam;
        if((carr[c][dd].res_V())==-1)
        {
            carr[c][dd].dar_V(0);
            carr[c][dd].dar_X((ax+1)-de);
            de--;
        }
    }
}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    this->p=arg1;
}

void MainWindow::on_spinBox_3_valueChanged(int arg1)
{
    this->vmax=arg1/27;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    this->vv=arg1;
}

void MainWindow::on_limpia_clicked()
{
    cronometro->stop();
    c=0;
    for(int i=0;i<tam;i++)
    {
        for(int j=0;j<5;j++)
        {
            carr[i][j].dar_V(-1);
            carr[i][j].dar_X(0);
        }
    }
    panimacion->dar_d(carr);
    panimacion->repaint();
}
