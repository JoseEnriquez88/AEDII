/*Luego desarrolle un programa en “C” que a partir del ingreso de dos variables reales y el operador 
(+: suma, -: resta, *: multiplicación, /: división), 
invoque al TDA y muestre los resultados de la operación seleccionada.

OBJETIVO: 
	robarme una mina ajena
ESTRATEGIA:
implementar un menu que se seleccione, muestre e invoque las funciones con los calculos
*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include "operacionesBasicas.h"

void ingresarDatos();
void iniciarPrograma();
void menu();
void mostrarMenu();

float n1, n2;

int main(){
	iniciarPrograma();
	return 0;
}

void ingresarDatos(){
	printf("\nDigite un número para la primer variable: ");
	scanf("%f", &n1);
	printf("\nDigite un número para la segunda variable: ");
	scanf("%f", &n2);
	
	suma(n1, n2);
	resta(n1, n2);
	multiplicacion(n1, n2);
	division(n1, n2);
	
}

void iniciarPrograma(){
	setlocale(LC_ALL, "spanish");
	mostrarMenu();
}

void menu(){
	printf("\t\tMENU");
	printf("\n1.Ingresar números para las variables.\n2.Calcular suma.\n3.Calcular resta.\n4.Calcular multiplicación.\n5.Calcular división.\n6.Salir del menú");
	printf("\n\nDigite una opción: ");
}

void mostrarMenu(){
	int opcion=0;
	do{
		menu();
		scanf("%d", &opcion);
		
		switch(opcion){
			case 1:
		    		ingresarDatos();
		    		printf("\n\n");
		    		system("pause");
		    		break;
			case 2:
					printf("\nResultado: %.2f", suma(n1, n2));
		    		printf("\n\n");
		    		system("pause");
		    		break;
			case 3:
					printf("\nResultado: %.2f", resta(n1, n2));
		    		printf("\n\n");
		    		system("pause");
		    		break;
			case 4:
					printf("\nResultado: %.2f", multiplicacion(n1, n2));
		    		printf("\n\n");
		    		system("pause");
		    		break;
			case 5:
					printf("\nResultado: %.2f", division(n1, n2));
		    		printf("\n\n");
		    		system("pause");
		    		break;
			case 6:
					printf("\n\t\t---SALIENDO DEL MENU---");
		    		printf("\n\n");
		    		system("pause");
		    		break;
			default:
					printf("\n\t\tOPCION INCORRECTA. DIGITE SOLO LAS OPCIONES DADAS EN EL MENU");
		    		printf("\n\n");
		    		system("pause");
		    		break;		
		}
		system("cls");
	}while(opcion != 6);
}


