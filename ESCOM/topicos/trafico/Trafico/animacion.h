#ifndef ANIMACION_H
#define ANIMACION_H
#include "carro.h"
#include <QWidget>

class animacion : public QWidget
{
    Q_OBJECT
public:
    explicit animacion(QWidget *parent = 0, int t=0);
    void mover(int x,int y);
    void dar_d(carro []);

protected:
    void paintEvent(QPaintEvent *event);

private:
    int x, y,tt;
    carro *d;
signals:

public slots:

};

#endif // ANIMACION_H
