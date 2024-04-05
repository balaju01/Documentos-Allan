#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * concatenar(char *a, char *b){ 
	int i;
	int longA = strlen(a);
	int longB = strlen(b);

	if (longA<=0 && longB > 0)
	{
		return b;
	}else if (longB<=0 && longA > 0)
	{
		return a;
	}else{ 
		return "";
	}
	int longC = longA + longB;
	char *c = (char *)malloc(sizeof(char)*longC);
	for (i = 0; i <longC ; ++i)
	{
		printf("%s\n", a[i]);
		if (i<longA)
		{
			c[i]=a[i];
		}else{ 
			c[i]=b[i-longA];
		}
	}
	return c;
}

char* crearquery(int dat[], char **value, int tam){ 
	char *query = "Select * from persona where ";
	char *aux2;
	char *aux3="";
	char *aux4="";
	int aux=0;
	int i;
	char *srtAux;
	//printf("%s\n", value[7]);
	for (i = 0; i < tam; ++i)
	{
		switch(dat[i]){ 
			case 1:
				if(aux != 0){ 
					srtAux = "and nombre='";
				}else{ 
					srtAux = "nombre='";
					aux=1;
				}
				break;
			case 2:
				if(aux != 0){ 
					srtAux = "and apPaterno='";
				}else{ 
					srtAux = "apPaterno='";
					aux=1;
				}
				break;
			case 3:
				if(aux != 0){ 
					srtAux = "and apMaterno='";
				}else{ 
					srtAux = "apMaterno='";
					aux=1;
				}
				break;
			case 4:
				if(aux != 0){ 
					srtAux = "and edad='";
				}else{ 
					srtAux = "edad='";
					aux=1;
				}
				break;
			case 5:
				if(aux != 0){ 
					srtAux = "and genero='";
				}else{ 
					srtAux = "genero='";
					aux=1;
				}
				break;
			case 6:
				if(aux != 0){ 
					srtAux = "and semestre='";
				}else{ 
					srtAux = "semestre='";
					aux=1;
				}
				break;
			case 7:
				if(aux != 0){ 
					srtAux = "and boleta='";
				}else{ 
					srtAux = "boleta='";
					aux=1;
				}
				break;
			case 8:
				if(aux != 0){ 
					srtAux = "and curp='";
				}else{ 
					srtAux = "curp='";
					aux=1;
				}
				break;
		}
		aux2 = concatenar(aux4, srtAux);
		printf("value: %s\n", value[i]);
		aux3 = concatenar(aux2,value[i]);
		printf("Aux2: %s\n", aux3);
		aux4 = concatenar(aux3,"' ");
		printf("Aux3: %s\n", aux4);
	}
	aux2 = concatenar(query,aux3);
	return aux2;
}

int main()
{
char in[14]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
	char **par;
	par=(char **)malloc(sizeof(char *)*8);
	int i=0;
	for (i = 0; i < 8; ++i)
	{
		par[i]=(char *)malloc(sizeof(char)*25);
	}
	int str[7]={0,0,0,0,0,0,0},c=0;
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
	char *res= crearquery(str,par,c);
	printf("Query a la base de datos: %s\n", res);
    return 0;
}

