#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *archivo1, *archivo2;
	char caracter;

	archivo1 = fopen("archivo1.txt","r"); //archivo de lectura
	archivo2 = fopen ( "archivo2.txt","w+"); //archivo que se crea y reescribe

	if (archivo1 == NULL)
	{
		printf("\nError de apertura del archivo. \n\n");
    }
    else
    {
	    while (feof(archivo1) == 0)
	    {
			caracter = fgetc(archivo1);
			printf("%c",caracter);
			if(caracter!=' ')
			{
				caracter = caracter+1-32;				
			}
			//fprintf(archivo1,caracter); --> me manda error
			printf(">");
			printf("%c",caracter);
			fprintf(archivo2,"%c",caracter);
			printf("\n");
	    }
    }
        fclose(archivo1);
        fclose(archivo2);
	return 0;
}