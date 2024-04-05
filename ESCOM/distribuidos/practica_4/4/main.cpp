#include <iostream>
#include "temperatura.h"

using namespace std;

int main()
{
    Temperatura a(0);
    int c;
    float aux=0.0;
    cout << "En que formato quiere introducir la temperatura? \n";
    cout << "1.- Grados Kelvin \n";
    cout << "2.- Grados Fahrenheit \n";
    cout << "3.- Grados Celsius \n";
    cin >> c;
    switch(c)
    {
        case 1:
            cout << "introdusca la temperatura en grados Kelvin: \n";
            cin >> aux;
            a.setTempKelvin(aux);
            break;
        case 2:
            cout << "introdusca la temperatura en grados Fahrenheit: \n";
            cin >> aux;
            a.setTempFahrenheint(aux);
            break;
        case 3:
            cout << "introdusca la temperatura en grados Celsius: \n";
            cin >> aux;
            a.setTempCelsius(aux);
            break;
    }

    cout << "En que formato desea imprimir la temperatura \n";
    cout << "1.- Grados Kelvin \n";
    cout << "2.- Grados Fahrenheit \n";
    cout << "3.- Grados Celsius \n";
    cin >> c;

    switch (c)
    {

        case 1:
            a.impKelvin();
            break;
        case 2:
            a.impFahrenheit();
            break;
        case 3:
            a.impCelsius();
            break;

    }


    cout  << endl;
    return 0;
}

