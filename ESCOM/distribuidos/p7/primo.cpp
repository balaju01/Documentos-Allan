#include "primo.h"

primo::primo()
{
    indic=true;
    numero=1;
}

void primo::idicador(bool a)
{
    this->indic=a;
}

void primo::numer(int a)
{
    this->numero=a;
}

int primo::dameNum()
{
    return this->numero;
}

bool primo::dameIndic()
{
    return this->indic;
}
