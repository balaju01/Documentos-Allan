#ifndef FRACCION_H
#define FRACCION_H

class fraccion
{
private:
    int num;
    int den;
public:
    fraccion();
    double divicion();
    void minimaExpre();
    int euclides(int,int);
    void darNum(int);
    void darDen(int);
};

#endif // FRACCION_H
