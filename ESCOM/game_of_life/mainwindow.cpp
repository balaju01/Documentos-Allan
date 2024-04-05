#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QImage a(1000,1000,QImage::Format_ARGB32);
    QRgb b;
    int i,j;
    b=qRgb(255,255,255);
    for(i=0;i<1000;i++)
    {
        for (j = 0; j < 1000; ++j)
        {
            a.setPixel(i,j,b);
        }
    }

    this->i=this->i.fromImage(a);
    this->regla=0;
    this->control=0;
    //ui->imagen->setPixmap(this->i);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ini_pau_clicked()
{

    int x,y,z,w;


    if(this->regla==1)
    {
        x=2;
        y=3;
        w=3;
        z=3;
    }
    else if (this->regla==2)
    {
        x=7;
        y=7;
        w=2;
        z=2;
    }
    else if (this->regla==3)
    {
        x=this->Xx;
        y=this->Yy;
        w=this->W;
        z=this->Z;
    }
    if(this->control==0)
    {
        this->propagacions();
        this->control=1;
        ui->imagen->setPixmap(this->i);
    }
    else if(this->control==1)
    {
        for (int i = 0; i < 10; ++i) {
            this->evaluar(x,y,w,z);
            sleep(1);
            ui->imagen->setPixmap(this->i);
        }
        this->control=0;
    }
}

void MainWindow::evaluar(int x,int y, int w, int z)
{
    int v1x,v1y,v2x,v2y,v3x,v3y,v4x,v4y,v5x,v5y,v6x,v6y,v7x,v7y,v8x,v8y,v=0;
    QRgb ba=qRgb(0,0,0);
    QRgb bb=qRgb(255,255,255);
    QImage a=this->i.toImage();
    QImage b=a;

    for(int yy=0;yy<1000;yy++)
    {
        for(int xx=0;xx<1000;xx++)
        {
            v1x=xx-1;
            if(v1x<0)
            {
                v1x=1000-1;
            }
            v4x=v1x;
            v6x=v1x;
            v1y=yy-1;
            if(v1y<0)
            {
                v1y=1000-1;
            }
            v2y=v1y;
            v3y=v1y;
            v3x=(xx+1)%1000;
            v5x=v3x;
            v8x=v3x;
            v6y=(yy+1)%1000;
            v7y=v6y;
            v8y=v6y;
            v2x=xx;
            v7x=v2x;
            v4y=yy;
            v5y=v4y;
            //qDebug("v1 %d %d v2 %d %d v3 %d %d v4 %d %d v5 %d %d v6 %d %d v7 %d %d v8 %d %d",v1x,v1y,v2x,v2y,v3x,v3y,v4x,v4y,v5x,v5y,v6x,v6y,v7x,v7y,v8x,v8y);

            if((a.pixel(v1x,v1y))==ba)
            {
                v=v+1;
            }
            if((a.pixel(v2x,v2y))==ba)
            {
                v=v+1;
            }
            if((a.pixel(v3x,v3y))==ba)
            {
                v=v+1;
            }
            if((a.pixel(v4x,v4y))==ba)
            {
                v=v+1;
            }
            if((a.pixel(v5x,v5y))==ba)
            {
                v=v+1;
            }
            if((a.pixel(v6x,v6y))==ba)
            {
                v=v+1;
            }
            if((a.pixel(v7x,v7y))==ba)
            {
                v=v+1;
            }
            if((a.pixel(v8x,v8y))==ba)
            {
                v=v+1;
            }

            if((a.pixel(xx,yy))==ba)
            {
                if(v>=x&&v<=y)
                {
                    b.setPixel(xx,yy,ba);
                }
                else
                {
                    b.setPixel(xx,yy,bb);
                }
            }
            else if ((a.pixel(xx,yy)==bb))
            {
                if(v>=w&&v<=z)
                {
                    b.setPixel(xx,yy,ba);
                }
                else
                {
                    b.setPixel(xx,yy,bb);
                }

            }
            v=0;
        }
    }
    //qDebug("v%d\n",v);
    this->i=this->i.fromImage(b);
}

void MainWindow::propagacions()
{
    QImage a=this->i.toImage();
    QRgb n=qRgb(0,0,0);
    int c=0,x=0,y=0;
    float mx=(((float)this->i.width())*((float)this->i.height()))*this->propa;
    //qDebug("los pixeles a propagar son: %4.2f \n",mx);
    for(c=0;c<((int)mx);c++)
    {
        x=(rand()%1000);
        y=(rand()%1000);
        while ((a.pixel(x,y))==n) {
            x=rand()%1000;
            y=rand()%1000;
        }
        a.setPixel(x,y,n);

    }

    this->i=this->i.fromImage(a);
    ui->imagen->setPixmap(this->i);
}

void MainWindow::on_life_pressed()
{
    this->regla=1;
}

void MainWindow::on_Diffussion_pressed()
{
    this->regla=2;
}

void MainWindow::on_personal_pressed()
{
    this->regla=3;
}

void MainWindow::on_propagacion_valueChanged(int pr)
{
    this->propa=((float)pr/100);
    //qDebug("la propagacion %4.2f \n",this->propa);
}

void MainWindow::on_comboX_currentIndexChanged(int index)
{
    this->Xx=index;
}

void MainWindow::on_comboY_currentIndexChanged(int index)
{
    this->Yy=index;
}

void MainWindow::on_comboW_currentIndexChanged(int index)
{
    this->W=index;
}

void MainWindow::on_comboZ_currentIndexChanged(int index)
{
    this->Z=index;
}

void MainWindow::on_limpia_clicked()
{
    QImage a=this->i.toImage();
    QRgb b;
    int i,j;
    b=qRgb(255,255,255);
    for(i=0;i<1000;i++)
    {
        for (j = 0; j < 1000; ++j)
        {
            a.setPixel(i,j,b);
        }
    }
    this->control=0;
    this->i=this->i.fromImage(a);
    ui->imagen->setPixmap(this->i);
}
