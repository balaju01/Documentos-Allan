#include <iostream>
#include <fstream>
#include "sha256.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>


using namespace std;


int main()
{
    FILE *archivo;
    srand(time(NULL));
    archivo=fopen("/home/allan/Dropbox/Allan/TT/prueba 1/Correo1.txt","r");
    char linea[128],p;
    int c=0,n=0;
    string input = "grape";
    string output1;
    stringstream output2;
    n=10;
    char keyy[n];
    //long contador = 0L;


        while(!(feof(archivo)))
        {

            p=fgetc(archivo);
            linea[c]=p;

            c++;

        }
        cout << linea << "\n" << endl;
        fclose(archivo);

   for(int i=0;i<n;i++)
   {
       keyy[i]=(char)((rand())%100);
   }
    output2<<keyy;
    output2>>input;
    input=string(keyy);
    cout << "tamaño: " << n << " palabra: " << keyy << ".        ." << input << ".\n";
    output1=sha256(input);
    cout << "sha256('"<< input << "'):" << output1 << endl;


    return 0;
}

