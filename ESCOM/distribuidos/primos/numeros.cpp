#include "numeros.h"

numeros::numeros()
{
    num = 0;
    pri = true;
}

numeros::numeros(int x):num(x),pri(true)
{
}

int numeros::getNum()
{
    return num;
}

bool numeros::getEdo()
{
    return pri;
}

void numeros::setEdo(bool x)
{
    pri = x;
}

void numeros::setNum(int x)
{
    num = x;
}
