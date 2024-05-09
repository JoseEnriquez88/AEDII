#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

#define MAX_DISCOS 12

typedef int tArrayEnteros[MAX_DISCOS];

typedef struct
{
	tArrayEnteros listaEnteros;
	int tope;
} tPila;

tPila pila;

void iniciarPrograma();
void menu();
void mostrarMenu();

void crearPilaVacia();
void cargarPila();
void listarPesos();
void quitarDisco();
void discoEnElTope();
void mostrarCantidad();
void calcularPromedio();

int main()
{
	setlocale(LC_ALL, "spanish");
	iniciarPrograma();
	return 0;
};

void menu()
{
	printf("\t\tMenu:\n");
	printf("\t1. Cargar la pila con los pesos de los discos\n");
	printf("\t2. Listar los pesos de los discos apilados\n");
	printf("\t3. Quitar un disco de la pila\n");
	printf("\t4. Mostrar el disco que se encuentra en el tope\n");
	printf("\t5. Mostrar la cantidad de discos apilados\n");
	printf("\t6. Calcular el promedio de pesos de los discos en la pila\n");
	printf("\t0. Salir\n");
	printf("\n\tSeleccione una opción: ");
};

void iniciarPrograma()
{
	crearPilaVacia();
	mostrarMenu();
};

void mostrarMenu()
{
	int opcion;
	do
	{
		menu();
		scanf("%d", &opcion);
		switch (opcion)
		{
		case 1:
			cargarPila();
			printf("\n\n");
			// system("pause");
			break;
		case 2:
			listarPesos();
			printf("\n\n");
			// system("pause");
			break;
		case 3:
			quitarDisco();
			printf("\n\n");
			// system("pause");
			break;
		case 4:
			discoEnElTope();
			printf("\n\n");
			// system("pause");
			break;
		case 5:
			mostrarCantidad();
			printf("\n\n");
			// system("pause");
			break;
		case 6:
			calcularPromedio();
			printf("\n\n");
			// system("pause");
			break;
		case 0:
			printf("Saliendo del programa...\n");
			printf("\n\n");
			// system("pause");
			break;
		default:
			printf("\n\t\t---OPCIÓN INCORRECTA. DIGITE SOLO LAS OPCIONES DADAS EN EL MENÚ---");
			printf("\n\n");
			// system("pause");
			break;
		}
		// system("cls");
	} while (opcion != 0);
};

void crearPilaVacia()
{
	pila.tope = -1;
};

void cargarPila()
{
	if (pila.tope == MAX_DISCOS - 1)
	{
		printf("La pila está llena. No se pueden agregar más discos.\n");
		return;
	}

	float peso;
	printf("Ingrese el peso del disco a agregar: ");
	scanf("%f", &peso);

	pila.tope++;
	pila.listaEnteros[pila.tope] = peso;

	printf("\nDisco agregado exitosamente a la pila.\n");
};

void listarPesos()
{
	int i;
	printf("Pesos de los discos apilados:\n");
	for (i = 0; i <= pila.tope; i++)
	{
		printf("%d ", pila.listaEnteros[i]);
	}
	printf("\n");
};

void quitarDisco()
{
	if (pila.tope == -1)
	{
		printf("La pila esta vacía. No se pueden quitar discos.\n");
		return;
	}

	printf("Disco quitado de la pila con peso %d.\n", pila.listaEnteros[pila.tope]);
	pila.listaEnteros[pila.tope] = 0;
	pila.tope--;
};

void discoEnElTope()
{
	if (pila.tope == -1)
	{
		printf("La pila esta vacia. No hay discos en el tope.\n");
		return;
	}

	printf("El disco en el tope de la pila tiene un peso de %d Kg.\n", pila.listaEnteros[pila.tope]);
};

void mostrarCantidad()
{
	printf("Cantidad de discos apilados: %d\n", pila.tope + 1);
};

void calcularPromedio()
{
	if (pila.tope == -1)
	{
		printf("La pila esta vacía. No se puede calcular el promedio de pesos.\n");
		return;
	}
	int i;
	int suma = 0;
	for (i = 0; i <= pila.tope; i++)
	{
		suma += pila.listaEnteros[i];
	}

	float promedio = (float)suma / (pila.tope + 1);
	printf("El promedio de pesos de los discos en la pila es: %.2f Kg.\n", promedio);
};
