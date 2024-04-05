#include "rules.h"
#include <iostream>
#include <stdlib.h>


using namespace std;
rules::rules(int Bmn, int Bmx, int Smn, int Smx):Bmin(Bmn),Bmax(Bmx),Smin(Smn),Smax(Smx)
{

}

void rules::setrules(int Bmn, int Bmx, int Smn, int Smx)
{
    this->Bmax = Bmx;
    this->Bmin = Bmn;
    this->Smax = Smx;
    this->Smin = Smn;
}

int rules::game(bool **a, bool **b, int tam)
{
    int life;
    int aux1=0;
    int aux2=0;
    int i,j,k,l;
    int mask = 0x00000001;
    int conf = 0;
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            life = 0;
            for(k=-1;k<2;k++){
                for(l=-1;l<2;l++){
                    aux1 = ((i+k)+tam)%tam;
                    aux2 = ((j+l)+tam)%tam;
                    if(a[aux1][aux2] && !((aux1==i) && (aux2== j))){
                        life++;
                    }
                }
            }
            if(!a[i][j]){
                if(life>=Bmin && life<=Bmax){
                    b[i][j]=true;
                    conf += mask;
                }else{
                    b[i][j]=false;
                }
            }else{
                if(life>=Smin && life<=Smax){
                    b[i][j]=true;
                    conf += mask;
                }else{
                    b[i][j]=false;
                }
            }
            mask = mask<<1;
        }
    }
    cout << "Matriz A"<< endl;
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
           cout<< a[i][j]  <<",";
        }
        cout << endl;
    }
    cout << "Matriz B"<< endl;
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
           cout<< b[i][j]  <<",";
        }
        cout << endl;
    }
    /*swap = a;
    a = b;
    b = swap;*/
    return conf;
}
