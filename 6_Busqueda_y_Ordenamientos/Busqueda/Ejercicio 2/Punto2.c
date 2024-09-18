/*Escribir una funci�n que permita encontrar un valor en un arreglo de n�meros reales,
seg�n el m�todo de b�squeda binaria.
La funci�n debe devolver true en el caso que el elemento a buscar
exista dentro del arreglo y false en caso contrario.
Probar la funci�n en el bloque principal de un programa C.
*/

#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#define MAX 5

typedef float tVector[MAX];

void cargarVector(tVector);
bool busquedaBinaria(tVector, float);
void ingresarElemBuscar();
void mostrarVector(tVector);

void iniciarPrograma();

tVector vector;

int main()
{
	iniciarPrograma();
	return 0;
}

void cargarVector(tVector pVector)
{
	pVector[0] = 10.2;
	pVector[1] = 12.7;
	pVector[2] = 26.8;
	pVector[3] = 85.2;
	pVector[4] = 89.9;
}

bool busquedaBinaria(tVector pVector, float pElem)
{
	int exInf = 0;
	int extSup = MAX;
	int posMed;

	bool elemento = false;

	while ((!elemento) && (extSup >= exInf))
	{
		posMed = (extSup + exInf) / 2;
		if (pElem == pVector[posMed])
		{
			elemento = true;
		}
		else
		{
			if (pElem > pVector[posMed])
			{
				exInf = posMed + 1;
			}
			else
			{
				extSup = posMed - 1;
			}
		}
	}

	return elemento;
}

void ingresarElemBuscar()
{
	float buscar;
	printf("\nDigite el elemento a buscar: ");
	scanf("%f", &buscar);
	printf("\n\nExiste 1, NO existe 0: %d", busquedaBinaria(vector, buscar));
}

void mostrarVector(tVector pVector)
{
	int i;
	printf("Elementos en el vector:\n");
	for (i = 0; i < MAX; i++)
	{
		printf("%.2f\n", pVector[i]);
	}
	printf("\n");
}

void iniciarPrograma()
{
	setlocale(LC_ALL, "spanish");
	cargarVector(vector);
	ingresarElemBuscar();
	printf("\n\n");
	mostrarVector(vector);
}
