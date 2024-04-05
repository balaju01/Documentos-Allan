#include <iostream>

using namespace std;

double raiz(double n, double x){
    double aux;
    aux = (((n/x)+x)/2);
    if(aux==x){
        return x;
    }else{
        raiz(n,aux);
    }
}

int main(){
    double n, res;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);
    cout<< "Hola, prodias darme un número para obtener su raiz cuadrada?? \n";
    cin>>n;
    res = raiz(n, 1);
    cout<< "La raiz cuadrada de "<< n << " es: " << res << "\n";
}

