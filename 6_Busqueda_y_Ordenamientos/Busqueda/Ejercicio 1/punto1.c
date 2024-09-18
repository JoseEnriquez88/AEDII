/*Escribir un program a que permita determinar si un n�mero entero ingresado por teclado,
existe en un vector.
Para ello ser� necesario, disponer de lo siguiente:
a) Una funci�n que permita cargar elementos en un vector de n�meros enteros.
b) Una funci�n que permita visualizar los elementos almacenados en el vector.
c) Una funci�n que devuelva verdadero en el caso que el elemento a buscar exista en el vector,
y falso en caso contrario.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 5

typedef int tVector[MAX];

void cargarVector(tVector);
void mostrarElementos(tVector);
bool buscarElemento(tVector, int);
void ingresarElemABuscar();

void iniciarPrograma();

tVector vector;

int main()
{
	iniciarPrograma();

	return 0;
}

void cargarVector(tVector pVector)
{
	pVector[0] = 26;
	pVector[1] = 28;
	pVector[2] = 55;
	pVector[3] = 100;
	pVector[4] = 202;
}

void mostrarElementos(tVector pVector)
{
	int i;
	printf("\nElementos en el vector:\n\n");
	for (i = 0; i < MAX; i++)
	{
		printf("%d ", pVector[i]);
	}
	printf("\n\n");
}

bool buscarElemento(tVector pVector, int pElem)
{
	int i = 0;
	bool resultado = false;
	while ((pVector[i] < pElem) && (i <= MAX))
	{
		i++;
	}

	if (pVector[i] == pElem)
	{
		resultado = true;
	}

	return resultado;
}

void ingresarElemABuscar()
{
	int buscar;
	printf("\nDigite el n�mero a buscar: ");
	scanf("%d", &buscar);
	printf("\n\nExiste 1, NO existe 0: %d", buscarElemento(vector, buscar));
}

void iniciarPrograma()
{
	setlocale(LC_ALL, "spanish");
	cargarVector(vector);
	mostrarElementos(vector);
	ingresarElemABuscar();
}
