/*Escribir un programa que permita crear un �rbol binario de b�squeda,
el contenido de los nodos debe ser de tipo real.
Incluir los procedimientos para insertar, devolver el n�mero de nodos y recorrer el �rbol.

a) El procedimiento Insertar debe emitir una leyenda 'Es un hijo izquierdo' o 'Es un hijo derecho',
seg�n corresponda.
b) Escribir la funci�n que devuelva el n�mero de nodos del �rbol binario.
c) El procedimiento Recorrer debe mostrar el contenido del nodo, siguiendo alg�n recorrido en profundidad.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

typedef float tElem;

typedef struct nodoArbol
{
	tElem contenido;
	struct nodoArbol *hijoIzdo;
	struct nodoArbol *hijoDcho;
} tArbol;

tArbol *arbol;
float elemento;

void crearArbol(tArbol *);
bool arbolVacio(tArbol *);
tArbol *subIzq(tArbol *);
tArbol *subDcho(tArbol *);
void inOrden(tArbol *);
void insertar(tArbol **, float);

void ingresarDatos();
void iniciarPrograma();
void mostrarMenu();
void menu();
int consultarNumNodos(tArbol *);

int main()
{
	iniciarPrograma();
	return 0;
}

void crearArbol(tArbol *pArbol)
{
	pArbol = NULL;
}

bool arbolVacio(tArbol *pArbol)
{
	return pArbol == NULL;
}

tArbol *subIzq(tArbol *pArbol)
{
	return pArbol->hijoIzdo;
}

tArbol *subDcho(tArbol *pArbol)
{
	return pArbol->hijoDcho;
}
void inOrden(tArbol *pArbol)
{
	if (pArbol != NULL)
	{
		inOrden(pArbol->hijoIzdo);
		printf("%d ", pArbol->contenido);
		inOrden(pArbol->hijoDcho);
	}
}

void insertar(tArbol **pArbol, float pNum)
{
	if (arbolVacio(*pArbol))
	{
		(*pArbol) = malloc(sizeof(tArbol));
		if ((*pArbol) != NULL)
		{
			(*pArbol)->contenido = pNum;
			(*pArbol)->hijoIzdo = NULL;
			(*pArbol)->hijoDcho = NULL;
		}
		else
		{
			printf("No hay memoria disponile.\n", pNum);
		}
	}
	else
	{
		if (pNum < (*pArbol)->contenido)
		{
			insertar(&((*pArbol)->hijoIzdo), pNum);
		}
		else
		{
			if (pNum > (*pArbol)->contenido)
			{
				insertar(&((*pArbol)->hijoDcho), pNum);
			}
			else
			{
				printf("Valor duplicado!\n");
			}
		}
	}
}

void ingresarDatos()
{

	int opc;
	/*	do{*/
	printf("\nDigite un n�mero real: ");
	scanf("%f", &elemento);
	insertar(&arbol, elemento);
	/*		printf("\nDesea agregar otro n�mero? (1-so/2-no): ");
			scanf("%d", &opc);
		}while(opc != 2);*/
}
void iniciarPrograma()
{
	setlocale(LC_ALL, "spanish");
	crearArbol(arbol);
	mostrarMenu();
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
			consultarNumNodos(arbol);
			printf("\n\n");
			system("pause");
			break;
		case 3:
			inOrden(arbol);
			printf("\n\n");
			system("pause");
			break;
		case 4:
			printf("\n\t\t---SALIENDO DEL MEN�---");
			printf("\n\n");
			system("pause");
			break;
		default:
			printf("\n\n\t\t---OPCI�N INCORRECTA. DIGITE SOLO LAS OPCIONES DADAS EN EL MEN�---");
			printf("\n\n");
			system("pause");
			break;
		}
		system("cls");
	} while (opcion != 4);
}

void menu()
{
	printf("\t\tMEN�");
	printf("\n\t\t1.Insertar elemento.\n\t\t2.Consultar n�mero de nodos del �rbol.\n\t\t3.Recorrer �rbol.\n\t\t4.Salir del men�.");
	printf("\n\n\t\tDigite una opci�n: ");
}

int consultarNumNodos(tArbol *pArbol)
{
	if (!arbolVacio(pArbol))
	{
		return consultarNumNodos(pArbol->hijoIzdo) + 1 + consultarNumNodos(pArbol->hijoDcho);
	}
}
