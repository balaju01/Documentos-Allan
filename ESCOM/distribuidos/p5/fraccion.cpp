#include "fraccion.h"
#include <iostream>

using namespace std;

fraccion::fraccion()
{
    this->den=0;
    this->num=0;
}

double fraccion::divicion()
{
    if (this->den!=0)
    {
        double aux=((double)(this->num))/((double)(this->den));
        return aux;
    }
    else
    {
        return this->num;
    }
}

void fraccion::minimaExpre()
{
    int div;
    if (this->den!=0)
    {
        div = euclides(this->num,this->den);
        cout << "La minima exprecion es:\n";
        cout << (this->num/div) << "/" << (this->den/div) << "\n";
    }
    else
    {
        cout << "La minima exprecion es:\n";
        cout << (this->num) << "/" << (0) << "\n";
    }
}

int fraccion::euclides(int a, int b)
{
    int rew;
    rew=a%b;
    if(rew==0)
    {
        return b;
    }
    else
    {
        return euclides(b,rew);
    }
}

void fraccion::darNum(int n)
{
    this->num=n;
}

void fraccion::darDen(int d)
{
    this->den=d;
}
