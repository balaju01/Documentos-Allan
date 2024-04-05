#include <iostream>
#include "fraccion.h"

using namespace std;

int main()
{
    fraccion a;
    int n,d;
    double des;
    cout << "introdusca el numerador\n";
    cin >> n;
    cout << "introdusca el denominador\n";
    cin >> d;
    a.darNum(n);
    a.darDen(d);
    cout << "tu fraccion es: " << n << "/" << d << "\n";
    des=a.divicion();
    cout << "Su forma decimal es:" << des << "\n";
    a.minimaExpre();
    cout  << endl;
    return 0;
}

