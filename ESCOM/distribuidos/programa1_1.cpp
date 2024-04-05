#include<iostream>
using namespace std;

int main()
{
	int numeroDeLenguajes;
	
	cout <<"!!!Hola!!!.\n" << "Bienvenido a C++. \n";
	cout <<"Cuantos lenguajes de programacion dominas? ";
	cin >> numeroDeLenguajes;

	if (numeroDeLenguajes < 1)
		cout << "Seria recomendable aprender antes un lenguaje mas sencillo...\n" << "por ejemplo C, aunque nada es imposible.\n";
	else
		cout << "Este curso sera sencillo para ti.\n";
	return 0;
}
