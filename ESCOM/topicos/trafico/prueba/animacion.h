#ifndef ANIMACION_H
#define ANIMACION_H

#include <QWidget>

class animacion : public QWidget
{
    Q_OBJECT
public:
    explicit animacion(QWidget *parent = 0);
    void mover(int x,int y);

protected:
    void paintEvent(QPaintEvent *event);

private:
    int x, y;

signals:

public slots:

};

#endif // ANIMACION_H
