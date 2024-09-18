/*Luego escriba un programa para probar dicha libreria (TDA) que permita el ingreso de dos valores enteros
y mediante la utilizacion de las funciones del TDA permita visualizar cual es el mayor valor, cual es el menor,
o si los valores son iguales.
Por ultimo, utilice la funcion para intercambiar y verifique que los valores se intercambien.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "operacionesConDosValores.h"

void ingresarDatos();
void iniciarPrograma();
void menu();
void mostrarMenu();

int ent1, ent2;

int main()
{
	iniciarPrograma();
	return 0;
}

void ingresarDatos()
{
	printf("\nDigite un n�mero para la primer variable: ");
	scanf("%d", &ent1);
	printf("Digite un n�mero para la segunda variable: ");
	scanf("%d", &ent2);

	calcularMayorValor(ent1, ent2);
	calcularMenorValor(ent1, ent2);
	calcularValoresEnteros(ent1, ent2);
	intercambioDeValores(ent1, ent2);
}

void iniciarPrograma()
{
	setlocale(LC_ALL, "spanish");
	mostrarMenu();
}

void menu()
{
	printf("\t\tMENU");
	printf("\n1.Ingresar variables.\n2.Mostrar variable de mayor valor.\n3.Mostrar variable de menor valor.\n");
	printf("4.Determinar si los valores son iguales.\n5.Intercambiar los valores.\n6.Salir del men�.\n\nDigite una opci�n: ");
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
			printf("\nLa variable de mayor valor es: %d", calcularMayorValor(ent1, ent2));
			printf("\n\n");
			system("pause");
			break;
		case 3:
			printf("\nLa variable de menor valor es: %d", calcularMenorValor(ent1, ent2));
			printf("\n\n");
			system("pause");
			break;
		case 4:
			printf("%d", calcularValoresEnteros(ent1, ent2));
			printf("\n\n");
			system("pause");
			break;
		case 5:
			printf("\nValor de la primer variable: %d.\nValor de la segunda variable: %d.", ent1, ent2);
			printf("\n\n");
			system("pause");
			break;
		case 6:
			printf("\n\t\t---SALIENDO DEL MENU---");
			printf("\n\n");
			system("pause");
			break;
		default:
			printf("\n\t\tOPCION INCORRECTA. DIGITE SOLO LAS OPCIONES DADAS EN EL MENU.");
			printf("\n\n");
			system("pause");
			break;
		}
		system("cls");
	} while (opc != 6);
}
