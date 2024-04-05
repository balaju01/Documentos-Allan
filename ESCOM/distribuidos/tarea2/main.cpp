#include <iostream>
#include "fraccion.h"

using namespace std;

int main()
{
    int numerador, denominador;
    cout << "Ingrese el numerador de su fraccion: " ;
    cin >> numerador;
    cout << "Ingrese el denominador de su fraccion: ";
    cin >> denominador;
    Fraccion x0(numerador,denominador);
    cout << "El numero original ingresado es: ";
    x0.imprimir();
    cout << "su reduccion es: ";
    x0.minimaExp();
    return 0;
}

