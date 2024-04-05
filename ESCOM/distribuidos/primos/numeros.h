#ifndef NUMEROS_H
#define NUMEROS_H

class numeros
{
private:
    int num;
    bool pri;
public:
    numeros();
    numeros(int x);
    int getNum();
    bool getEdo();
    void setEdo(bool x);
    void setNum(int x);
};

#endif // NUMEROS_H
