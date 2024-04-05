#include <stdio.h>

int main(int argc, char const *argv[])
{	char in[14]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
	char par[7][14];
	int str[7]={0,0,0,0,0,0,0},i,c=0;
	printf("1.- Nombre\t2.- Primer Apeido\t3.- Segundo Apeido\n4.- Edad\t5.- Sexo\t6.- Semestre\t7.-Boleta\n8.-CURP");
	printf("Intro dusca el numero o numeros segun los criterios con los que quiera hacer la busqueda en la base de datos.\nSi es mas de un parametro introdusca los numeros separados por una coma. \nejemplo: 1,2,3\n");
	gets(in);
	printf("%s\n",in );
	for (i = 0; i < 14; ++i)
	{
		if ((in[i]!='0')&&(in[i]!=','))
		{
			str[c]=in[i]-48;
			printf("%d\n", str[c]);
			c=c+1;
		}
		//printf("%c\n",in[i] );
	}
	c=0;
	while(str[c]!=-48)
	{
		if (str[c]==1)
		{
			printf("Introdusca el nombre que quiere buscar\n");
			gets(par[c]);
		}
		else if (str[c]==2)
		{
			printf("Introdusca el Primer Apeido que quiere buscar\n");
			gets(par[c]);
		}
		else if (str[c]==3)
		{
			printf("Introdusca el Segundo Apeido que quiere buscar\n");
			gets(par[c]);
		}
		else if (str[c]==4)
		{
			printf("Introdusca el Edad que quiere buscar\n");
			gets(par[c]);
		}
		else if (str[c]==5)
		{
			printf("Introdusca el Sexo que quiere buscar\n");
			gets(par[c]);
		}
		else if (str[c]==6)
		{
			printf("Introdusca el Semestre que quiere buscar\n");
			gets(par[c]);
		}
		else if (str[c]==7)
		{
			printf("Introdusca la Boleta que quiere buscar\n");
			gets(par[c]);
		}
		else if (str[c]==8)
		{
			printf("Introdusca el CURP que quiere buscar\n");
			gets(par[c]);
		}
		//printf("%d\n",c );
		c++;
	}
	c++;
	
	// variables a usar str: tiene el numero de el parametro, par: el valor del parametro, c: el numero de elementos
	return 0;
}