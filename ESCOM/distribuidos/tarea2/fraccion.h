#ifndef FRACCION_H
#define FRACCION_H

class Fraccion
{
private:
    int num;
    int den;
    int euclides(int x, int y);
public:
    Fraccion();
    Fraccion(int x, int y);
    int getNumerador();
    int getDenominador();
    void setNumerador(int x);
    void setDenominador(int y);
    double getIracional();
    void minimaExp();
    void imprimir();
};

#endif // FRACCION_H
