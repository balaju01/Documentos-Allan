
#include <iostream>

 using namespace std;

int main(){

    int h,m,s;
    int aux;
    int tiempo;
    cout << "introdusca el timepo en segundos";

    cin >> tiempo;
    h = tiempo/3600;
    aux = tiempo%3600;
    m = aux/60;
    s = aux%60;
    cout << "El valor "<< tiempo << " equivale a "<<h<<" horas, "<<m<<" minutos y "<<s<<" segundos.\n";
}
