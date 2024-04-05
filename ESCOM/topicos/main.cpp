#include <iostream>
#include <fstream>
#include "rules.h"
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    //Rules
    rules r(3,3,2,3);

    //Arbol
    vector< int *> arbol;
    int aux = 0x02000000;
    arbol.reserve(aux);

    int i,j;
    int *edo = new int[2];
    int tam = 3;
    int iniMatriz=0x00000000;
    int llenado;

    //Matrices
    bool **M1;
    bool **M2;
    M1 = new bool *[tam];
    M2 = new bool *[tam];

    for(i=0;i<tam;i++){
        M1[i] = new bool [tam];
        M2[i] = new bool [tam];
    }
    ofstream hol("Matriz 4x4.txt");  // objeto de la clase ofstream

    while(iniMatriz<= 0x00010000){

        llenado=0x00020000;

        //Llenado de la matriz
        while(llenado!=0){
            aux = (int)(log2(llenado));
            i = aux/tam;
            j = aux%tam;
            M1[i][j]= ((iniMatriz & llenado)==0)?false:true;
            //M2[i][j]= false;
            llenado = llenado>>1;
        }

        //Game of life

        edo[0] = iniMatriz;
        edo[1] = r.game(M1,M2,tam);
        arbol.push_back(edo);
        hol << edo[0]<< "," << edo[1] << endl;
        iniMatriz++;
    }
    hol.close();
    /*vector<int*>::iterator itera;
    for(itera=arbol.begin( );itera!=arbol.end( );itera++){
        cout<< *itera[0] << ","<< *itera[1] <<",";
    }
    cout<<endl;*/
}

