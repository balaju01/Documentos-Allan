#include "animacion.h"
#include <QPainter>

animacion::animacion(QWidget *parent) :
    QWidget(parent)
{
    x = y = 0;
}

void animacion::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setBrush(Qt::white);
    painter.drawRect(0,0,width() -1,height() -1);

    painter.setBrush(Qt::blue);
    painter.drawEllipse(x,y,20,20);
    painter.drawText(8,15,"1");
}

void animacion::mover(int x, int y)
{
    this->x += x;
    this->y += y;
    update();
}

