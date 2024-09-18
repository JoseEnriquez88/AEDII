/*Escribir un TDA para cargar y mostrar los elementos de una lista din�mica, en donde el nodo tenga
un campo identificador de tipo entero y un campo descripci�n de tipo cadena de caracteres.

Luego desarrolle un programa para probar dicho TDA.*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "ListaDinamica.h"

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
	crearLista();
	mostrarMenu();
}

void menu()
{
	printf("\t\tMENU");
	printf("\n\t\t1.Ingresar datos.\n\t\t2.Mostrar elementos.\n\t\t3.Salir del men�\n\n\t\tDigite un opci�n: ");
}

void mostrarMenu()
{
	int opcion = 0;
	do
	{
		menu();
		scanf("%d", &opcion);

		switch (opcion)
		{
		case 1:
			ingresarDatos();
			printf("\n\n");
			system("pause");
			break;
		case 2:
			mostrarElementos(lista);
			printf("\n\n");
			system("pause");
			break;
		case 3:
			printf("\n---SALIENDO DEL MEN�---");
			printf("\n\n");
			system("pause");
			break;
		default:
			printf("\nOPCI�N INCORRECTA. DIGITE SOLO LAS OPCIONES DADAS EN EL MEN�.");
			printf("\n\n");
			system("pause");
			break;
		}
		system("cls");
	} while (opcion != 3);
}

void ingresarDatos()
{
	tDatos datos;
	printf("\nDigite un n�mero cualquiera: ");
	scanf("%d", &datos.entero);
	printf("\nDigite un nombre cualquiera: ");
	fflush(stdin);
	scanf("%[^\n]s", &datos.cadena);
	insertarElemento(datos);
}
