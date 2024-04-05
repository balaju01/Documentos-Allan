#include "animacion.h"
#include <QPainter>
#include <qdebug.h>

animacion::animacion(QWidget *parent, int t) :
    QWidget(parent)
{
    x = y = 0;
    tt=t;
    d=new carro[t];
}

void animacion::paintEvent(QPaintEvent *)
{
    QString a;
    QPainter painter(this);
    painter.setBrush(Qt::white);
    painter.drawRect(0,0,width() -1,height() -1);

   for(int i=0;i<tt;i++)
   {
        //qDebug()<<this->d[i].res_V();
       if((this->d[i].res_V())==-1)
       {
           painter.setBrush(Qt::white);
           painter.setPen(Qt::black);
           painter.drawEllipse((i*20),0,20,20);
           a="";
           painter.drawText((i*20)+8,15,a);
       }
       else
       {
           if((this->d[i].res_V())==0)
           {
               painter.setBrush(Qt::red);
               painter.setPen(Qt::black);
               painter.drawEllipse((i*20),0,20,20);
               a=QString::number(this->d[i].res_X());
               painter.drawText((i*20)+8,15,a);
           }
           else
           {
               painter.setBrush(Qt::green);
               painter.setPen(Qt::black);
               painter.drawEllipse((i*20),0,20,20);
               a=QString::number(this->d[i].res_X());
               painter.drawText((i*20)+8,15,a);
           }
       }
   }
}
void animacion::mover(int x, int y)
{
    this->x += x;
    this->y += y;
    update();
}

void animacion::dar_d(carro v[])
{
    for(int i=0;i<tt;i++)
    {
        this->d[i]=v[i];
    }
}
