#include <iostream>
#include <vector>
#include "numeros.h"

using namespace std;

int main()
{
    numeros x;
    vector<numeros> bus;
    int N, i, aux;
    cout << "Indique un numero N para buscar los primos antes de ese numero N: ";
    cin >> N;
    bus.reserve(N);
    for(i=2;i<=N;i++){
        x.setNum(i);
        bus.push_back(x);
    }
    vector<numeros>::iterator ir;
    vector<numeros>::iterator j;
    cout << "Numeros primos: "<< endl;
    for(ir =bus.begin( ); ir != bus.end( ); ir++){
        if(ir->getEdo()){
            cout << ir->getNum() << ", ";
            i = ir->getNum();
            for(j = ir; j != bus.end(); j++){
                aux = j->getNum()%i;
                if(aux == 0 && j->getNum() != i){
                    j->setEdo(false);
                }
            }
        }
    }
    return 0;
}

