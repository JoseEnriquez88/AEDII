#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef char tString[60];

typedef struct
{
	int codProducto;
	int codRubro;
	int cantidad;
	float precio;
	tString descripcion;
} tDatos;

typedef struct nodo
{
	tDatos dato;
	struct nodo *siguiente;
} tPila;

tDatos productos;
tPila *pila;
float suma;

void crearPila();
bool pilaVacia();
void apilar(tDatos);
void desapilar();
void visualizarElementos(tPila *);
tDatos cima();

void iniciarPrograma();
void mostrarMenu();
void menu();
void agregarProductos();
float montoRecaudado();
void monto();

int main()
{
	iniciarPrograma();
	return 0;
}

void crearPila()
{
	pila == NULL;
}

bool pilaVacia()
{
	return (pila == NULL);
}

void apilar(tDatos pDato)
{
	tPila *aux;
	aux = pila;

	pila = malloc(sizeof(tPila));

	pila->dato.codProducto = pDato.codProducto;
	pila->dato.codRubro = pDato.codRubro;
	pila->dato.cantidad = pDato.cantidad;
	pila->dato.precio = pDato.precio;
	strcpy(pila->dato.descripcion, pDato.descripcion);

	pila->siguiente = aux;

	printf("\nProducto insertado.\n");
}

void desapilar()
{
	if (!pilaVacia())
	{
		tPila *nodoSuprimir;
		nodoSuprimir = pila;
		pila = pila->siguiente;
		free(nodoSuprimir);
		printf("nProducto eliminado de la pila.\n");
	}
	else
	{
		printf("\nNo hay productos a eliminar.\n");
	}
}

void visualizarElementos(tPila *pPila)
{
	tPila *aux;
	aux = pila;

	if (!pilaVacia())
	{
		printf("\nProductos en la pila.\n\n");
		while (aux != NULL)
		{
			printf("Descripcion: %s\nPrecio: %f\nCantidad: %s\nCodigo de rubro: %d\nCodigo producto: %d\n\n", productos.descripcion, productos.precio, productos.cantidad, productos.codRubro, productos.codProducto);
			aux = aux->siguiente;
		}
	}
	else
	{
		printf("\nNo hay productos en la pila para mostrar.\n");
	}
}

tDatos cima()
{
	tDatos dato;
	if (pilaVacia() == true)
	{
		dato.codProducto = 0;
		dato.codRubro = 0;
		dato.cantidad = 0;
		strcpy(dato.descripcion, " ");
	}
	else
	{
		dato.codProducto = productos.codProducto;
		dato.codRubro = productos.codRubro;
		dato.cantidad = productos.cantidad;
		strcpy(dato.descripcion, productos.descripcion);
	}
	return dato;
}

void iniciarPrograma()
{
	setlocale(LC_ALL, "spanish");
	crearPila();
	menu();
}

void mostrarMenu()
{
	printf("\t\tMENU");
	printf("\n1.Ingresar producto.\n2.Eliminar producto.\n3.Mostrar productos.\n4.Mostrar Cima.\n5.Mostrar total recaudado.\n6.Salir del menu.");
	printf("\n\nDigite una opcion: ");
}

void menu()
{
	int opcion = 0;
	do
	{
		mostrarMenu();
		scanf("%d", &opcion);

		switch (opcion)
		{
		case 1:
			agregarProductos();
			apilar(productos);
			system("pause");
			break;
		case 2:
			desapilar();
			system("pause");
			break;
		case 3:
			visualizarElementos(pila);
			system("pause");
			break;
		case 4:
			cima();
			system("pause");
			break;
		case 5:
			monto();
			system("pause");
			break;
		case 6:
			printf("\nSaliendo del menu");
			system("pause");
			break;
		default:
			printf("\nOPCION INCORRECTA. DIGITE SOLO LAS OPCIONES DADAS EN EL MENU");
			break;
		}
		system("cls");
	} while (opcion != 6);
}

void agregarProductos()
{
	printf("\nDigite el codigo del producto: ");
	scanf("%d", &productos.codProducto);
	printf("\nDigite codigo del rubro: ");
	scanf("%d", &productos.codRubro);
	printf("\nDigite la cantidad de productos: ");
	scanf("%d", &productos.cantidad);
	printf("\nDigite el precio del producto: ");
	scanf("%f", &productos.precio);
	printf("\nDigite la descripcion del producto: ");
	fflush(stdin);
	scanf("%[^\n]s", &productos.descripcion);
}

float montoRecaudado()
{
	return (suma + (productos.precio * productos.cantidad));
}

void monto()
{
	printf("\nEl monto recaudado es de: %.2f\n", montoRecaudado());
}
