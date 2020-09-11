/* Este programa es para realizar la primera parte del laboratorio2 de Alse
  Autor:Mariana Herrera y  Karin Lugo 
  Licencia: Comercial
  Versión: 1.0
  */

/* inclusión de librerias */
#include<stdio.h>

typedef struct punto{
	float x;
	float y;
}punto;

void pedir_puntos ( punto *punto1, punto *punto2, char *bandera);
void hallar_pendiente ( punto *punto1, punto *punto2, punto *resultado, char *bandera);
void cruce_eje_y ( punto *punto1,punto *punto2, punto *resultado, char *bandera);
void ecuacion_completa (punto *punto1, punto *punto2, punto *resultado, char *bandera);

/* Código principal */
int main (void) // esta es la función principal
{   
	punto punto1, punto2, resultado;
	resultado.x = 0;
	resultado.y = 0;
	punto1.x = 0;
	punto1.y = 0;
	punto2.x = 0;
	punto2.y = 0;
	
	int opcion = 0;
	char bandera =0;
	
	do {
		printf("Bienvenido a este programa que te permitira realizar distintas opciones dados dos puntos\n");
		printf ("Selecciona la opcion que deseas realizar\n");
		printf("Menú\n");
		printf("1- Ingresar dos puntos\n");
		printf("2- Hallar la pendiente\n");
		printf("3- Hallar el corte con el eje y\n");
		printf("4- Hallar la ecuación\n");
		printf("5- Salir\n");
		
		do {
			scanf("%d",&opcion);
		}while ( opcion > 5 || opcion < 1);
		
		switch (opcion)
		{
			case 1 : 
					pedir_puntos( &punto1, &punto2, &bandera);
		
					break;
			case 2:
					hallar_pendiente ( &punto1, &punto2, &resultado, &bandera);
					break;
		
			case 3: 
					cruce_eje_y ( &punto1, &punto2, &resultado, &bandera);
					break;
		
			case 4:
					ecuacion_completa (&punto1, &punto2, &resultado, &bandera);
					break; 
			
		} 
	}while (opcion != 5);
	return 0; 	
	
}

void pedir_puntos ( punto *punto1, punto *punto2, char *bandera)
{ 
	
	*bandera = 1;
	printf ("ingrese los puntos\n");
	printf ("ingrese la cordenada x del punto1 \n" );
	scanf ( "%f", &(punto1-> x)); 
	printf ("ingrese la cordenada y del punto1 \n" );
	scanf ( "%f", &(punto1-> y));
	printf ("ingrese la cordenada x del punto2 \n" );
	scanf ( "%f", &(punto2-> x)); 
	printf ("ingrese la cordenada y del punto2 \n" );
	scanf ( "%f", &(punto2-> y));
	printf ("las coordenadas del puntos 1 son: %f\n", punto1 -> x);
	printf ("las coordenadas del puntos 1 son: %f\n", punto1 -> y);
	printf ("la coordenada x del puntos 2 es: %f\n", punto2 -> x);
	printf ("la coordenada y del puntos 2 es: %f\n", punto2 -> y);
	
} 


void hallar_pendiente ( punto *punto1, punto *punto2, punto *resultado, char *bandera)

{
	float p = 0;
	resultado -> x = punto2 -> x - punto1 -> x;
	resultado -> y = punto2 -> y - punto1 -> y;
	if (*bandera == 1)
	{
		if((punto1 -> y) == (punto2 -> y)) 
		{
		printf("La pendiente es igual a 0 \n");
		}
		else
		{
		p = resultado -> y / resultado -> x;
		printf("La pendiente es %fx \n", p);
		}
	}
	else
	{
		printf("error, no ha ingresado los puntos\n");
	}
	
}

void cruce_eje_y ( punto *punto1,punto *punto2, punto *resultado, char *bandera)

{
	float p = 0, cruce = 0;
	resultado -> x = punto2 -> x - punto1 -> x;
	resultado -> y = punto2 -> y - punto1 -> y;
	p = resultado -> x / resultado -> y;
	
	
    if (*bandera == 1)
	{
		cruce = punto1 -> y - punto1 -> x * p;
		printf("El cruce del eje y es %f\n", cruce);
	}
	else
	{
		printf("error, no ha ingresado los puntos\n");
		
	}
}


void ecuacion_completa (punto *punto1, punto *punto2, punto *resultado, char *bandera)
{
	float p = 0, cruce = 0;
	resultado -> x = punto2 -> x - punto1 -> x;
	resultado -> y = punto2 -> y - punto1 -> y;
	p = resultado -> x / resultado -> y;
	cruce = punto1 -> y - punto1 -> x * p;
	if (*bandera == 1)
	{
		
		printf("La ecuacion completa es : %fx + %f\n", p, cruce);
	}
	else
	{
		printf("error, no ha ingresado los puntos\n");
		
	}		
}

