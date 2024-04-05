#include<iostream>

using namespace std;

int main( int argc, char* argv[] )
{
   double precio = 78.7;
   
   cout << "Sin formato:" << endl;
   cout << "Precio:" << precio << endl;   //Se imprime el valor de precio sin formato
   cout << "\nCon formato:" << endl;

   cout.setf(ios::fixed);        //formato de punto fijo
   cout.setf(ios::showpoint);    //uncluye punto decimal en numeros en coma flotante
   cout.precision(2);            //numero de numero despues del punto

   cout << "Precio:" << precio << endl;   //Se imprime el valor de precio con formato

   return 0;
}
