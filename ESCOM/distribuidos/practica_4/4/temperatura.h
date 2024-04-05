#ifndef TEMPERATURA_H
#define TEMPERATURA_H

class Temperatura
{
private:
    float g_Kelvin;
public:
    Temperatura(float n);
    void setTempKelvin(float a);
    void impKelvin();
    void setTempFahrenheint(float a);
    void impFahrenheit();
    void setTempCelsius(float a);
    void impCelsius();
};

#endif // TEMPERATURA_H
