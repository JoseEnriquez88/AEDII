#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
	long codProducto;
	char descripcion[80];
	float precioUnitario;
} tDato;

typedef struct nodo
{
	tDato datos;
	struct nodo *siguiente;
} tListaProductos;

tDato productos;
tListaProductos *listaProducto;

void crearLista();
bool listaVacia(tListaProductos *);
void insertarProducto(tDato);
void eliminarProducto();
void mostrarProducto(tListaProductos *);
void insertarPrimero(tDato);
void insertarAdelante(tDato, tListaProductos *);

void iniciarPrograma();
void menu();
void mostrarMenu();
void agregarDatosProductos();

int main()
{
	iniciarPrograma();
	return 0;
}

void crearLista()
{
	listaProducto = NULL;
}

bool listaVacia(tListaProductos *pListaProducto)
{
	return (pListaProducto == NULL);
}

void insertarProducto(tDato pDato)
{
	if (listaVacia(listaProducto))
	{
		insertarPrimero(pDato);
	}
	else
	{
		insertarAdelante(pDato, listaProducto);
	}
}

void eliminarProducto(); /*NO PIDE IMPLEMENTACION*/

void mostrarProducto(tListaProductos *pListaProductos)
{
	tListaProductos *aux;
	aux = pListaProductos;

	if (!listaVacia(aux))
	{
		printf("\n\t\t---PRODUCTOS EN LA LISTA---\n\n");
		while (aux != NULL)
		{
			printf("Codigo producto: %ld\nDescripci�n: %s\nPrecio: %.2f\n\n", aux->datos.codProducto, aux->datos.descripcion, aux->datos.precioUnitario);
			aux = aux->siguiente;
		}
	}
	else
	{
		printf("\n\t\tNO HAY PRODUCTOS EN LA LISTA.\n\n");
	}
	printf("\n\n");
}

void insertarPrimero(tDato pDato)
{
	tListaProductos *nuevoNodo;
	nuevoNodo = (tListaProductos *)malloc(sizeof(tListaProductos));
	nuevoNodo->datos = pDato;
	nuevoNodo->siguiente = listaProducto;
	listaProducto = nuevoNodo;
	printf("\nProducto agregado a la lista.\n\n");
}

void insertarAdelante(tDato pDato, tListaProductos *pListaProductos)
{
	tListaProductos *nuevoNodo;
	nuevoNodo = (tListaProductos *)malloc(sizeof(tListaProductos));
	nuevoNodo->datos = pDato;
	nuevoNodo->siguiente = listaProducto;
	listaProducto = nuevoNodo;
	printf("\nProducto agregado adelante de la lista.\n\n");
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
	printf("\n1.Agregar producto.\n2.Mostrar productos.\n3.Salir del menu.\n\nDigite una opci�n: ");
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
			agregarDatosProductos();
			printf("\n\n");
			system("pause");
			break;
		case 2:
			mostrarProducto(listaProducto);
			printf("\n\n");
			system("pause");
			break;
		case 3:
			printf("\n\t\tSALIENDO DEL MENU...");
			printf("\n\n");
			system("pause");
			break;
		default:
			printf("\n\t\t---OPCI�N INCORRECTA. DIGITE SOLO LAS OPCIONES DADAS EN EL MENU---");
			printf("\n\n");
			system("pause");
			break;
		}
		system("cls");
	} while (opcion != 3);
}

void agregarDatosProductos()
{
	tDato producto;

	printf("\nDigite codigo del producto: ");
	scanf("%ld", &producto.codProducto);
	printf("\nDigite descripci�n del producto: ");
	fflush(stdin);
	scanf("%[^\n]s", &producto.descripcion);
	printf("\nDigite precio del producto: ");
	scanf("%f", &producto.precioUnitario);
	insertarProducto(producto);
}
