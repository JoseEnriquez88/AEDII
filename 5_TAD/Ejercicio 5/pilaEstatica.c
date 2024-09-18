/*Escribir un TDA para cargar y mostrar los elementos de una pila est�tica de elementos
de tipo cadena de caracteres. Luego desarrolle un programa para probar dicho TDA.*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include "pilaEstatica.h"

void iniciarPrograma();
void menu();
void mostrarMenu();
void ingresarDatos();

int main()
{
	iniciarPrograma();
	return 0;
}

void iniciarPrograma()
{
	setlocale(LC_ALL, "spanish");
	crearPila();
	mostrarMenu();
}

void menu()
{
	printf("\t\tMENU");
	printf("\n1.Cargar elementos.\n2.Mostrar elementos.\n3.Salir del men�.\n\nDigite una opci�n: ");
}

void mostrarMenu()
{
	int opc = 0;
	do
	{
		menu();
		scanf("%d", &opc);

		switch (opc)
		{
		case 1:
			ingresarDatos();
			printf("\n\n");
			system("pause");
			break;
		case 2:
			mostrarElementos(pila);
			printf("\n\n");
			system("pause");
			break;
		case 3:
			printf("\n\t\t---SALIENDO DEL MEN�---");
			printf("\n.....____________________ , ,__");
			printf("\n....../ `---___________----_____|] - - - - - - - - � ����D ");
			printf("\n...../_==o;;;;;;;;_______.:/");
			printf("\n.....), ---.(_(__) /");
			printf("\n....// (..) ), ----");
			printf("\n...//___//");
			printf("\n..//___//");
			printf("\n.//___//");
			printf("\n\n");
			system("pause");
			break;
		default:
			printf("\nOPCI�N INCORRECTA. DIGITE SOLO LAS OPCIONES QUE SE MUESTRAN EN EL MEN�");
			printf("\n\n");
			system("pause");
			break;
		}
		system("cls");
	} while (opc != 3);
}
void ingresarDatos()
{
	char[80] palabra;
	printf("\nDigite una palabra cualquiera: ");
	fflush(stdin);
	scanf("%[^\n]s", &palabra);
	apilar(palabra);
}
