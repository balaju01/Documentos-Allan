#include "temperatura.h"
#include <iostream>

using namespace std;

Temperatura::Temperatura(float n)
{
    this->g_Kelvin=n;
}

void Temperatura::impKelvin()
{
    cout<<"La temperatura en grados kelvin es: "<< this->g_Kelvin <<endl;
}

void Temperatura::setTempKelvin(float a)
{
    this->g_Kelvin=a;
}

void Temperatura::setTempFahrenheint(float a)
{
    this->g_Kelvin=(((a-32)/1.8000)+273.15);
}

void Temperatura::impFahrenheit()
{
    float aux=(((this->g_Kelvin)-273.15)*1.8000)+32.00;
    cout<<"La temperatura en grados Fahrenheit es: "<< aux <<endl;
}

void Temperatura::setTempCelsius(float a)
{
    this->g_Kelvin=(a-273.15);
}

void Temperatura::impCelsius()
{
    float aux=((this->g_Kelvin)+273.15);
    cout<<"La temperatura en grados Celsius es: "<< aux <<endl;
}
