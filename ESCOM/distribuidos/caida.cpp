#include <iostream>

using namespace std;

int main(){

    double h, t;
    cout << "introduce el tiempo que tardo la pelota de tenis en llegar al piso\n";

    cin >> t;
    h = ((9.81*(t*t))/2);
    cout << "La altura del edificio desde donde arrojaste la pelota de tenis es: "<< h <<"\n";

}
