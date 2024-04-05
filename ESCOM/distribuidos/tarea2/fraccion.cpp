#include "fraccion.h"
#include <iostream>

using namespace std;

Fraccion::Fraccion():num(0),den(1)
{
}

Fraccion::Fraccion(int x, int y):num(x)
{
    if(y != 0){
        den = y;
    }else{
        y = 1;
    }
}

int Fraccion::getNumerador()
{
    return num;
}

int Fraccion::getDenominador()
{
    return den;
}

void Fraccion::setNumerador(int x)
{
     num = x;
}

void Fraccion::setDenominador(int y)
{
    den = y;
}

double Fraccion::getIracional()
{
    double res = num/den;
    return res;
}

void Fraccion::minimaExp()
{
    int eucli = euclides(num,den);
    cout<< (num/eucli) << "/" << (den/eucli) << endl;
}

void Fraccion::imprimir()
{
    cout<< num << "/" << den << endl;
}

int Fraccion::euclides(int x, int y)
{
    int residuo = x%y;
    if(residuo == 0){
        return y;
    }else{
        return euclides(y,residuo);
    }
}
