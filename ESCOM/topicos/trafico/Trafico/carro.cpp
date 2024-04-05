#include "carro.h"

carro::carro()
{
    x=0;
    v=-1;
}

void carro::dar_X(int x)
{
    this->x=x;
}

void carro::dar_V(int v)
{
    this->v=v;
}

int carro::res_V()
{
    return this->v;
}

int carro::res_X()
{
    return this->x;
}
