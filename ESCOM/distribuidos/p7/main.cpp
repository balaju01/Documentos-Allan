#include <iostream>
#include <vector>
#include "primo.h"

using namespace std;

int main()
{
    int numeros, m,ot_aux;
    vector<primo> arreglo;
    primo aux;
    cout << "Los primos menores a que numero desea conocer?\n";
    cin >>numeros;
    arreglo.reserve(numeros);
    for(int i=2;i<=numeros;i++)
    {
            aux.numer(i);
            arreglo.push_back(aux);
            //cout << aux.dameNum();
    }
    vector<primo>::iterator x;
    vector<primo>::iterator o_y;

    for(x =arreglo.begin( ); x != arreglo.end( ); x++)
    {

            if(x->dameIndic())
            {

                m = x->dameNum();
                for(o_y = x; o_y != arreglo.end(); o_y++)
                {
                    ot_aux = o_y->dameNum()%m;
                    if(ot_aux == 0 && o_y->dameNum() != m)
                    {
                        o_y->idicador(false);
                    }
                }
            }
        }
    cout << "Los primos son:";
    for(x =arreglo.begin( ); x != arreglo.end( ); x++)
    {
        if(x->dameIndic())
        {
            cout << (x->dameNum()) << ",";
        }
    }
    cout << "\n";
    return 0;
}

