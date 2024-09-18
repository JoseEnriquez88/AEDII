#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

typedef char tString[100];

typedef struct
{
	int libreta;
	tString nombreCom[100];
} tDato;

typedef struct nodo
{
	tDato dato;
	struct nodo *siguiente;
} tLista;

tLista *listaAlumnos;
tDato alumnos;

void iniciarLista();
bool listaVacia(tLista *);
void insertarAlumno(tDato);
void eliminarAlumno();
void mostrarAlumno(tLista *);
void insertarPrimero(tDato);
void insertarAdelante(tDato, tLista *);
void insertarK(int, tDato);
void eliminarK(int);

void iniciarPrograma();
void opcionesMenu();
void menu();
void agregarDatosAlumno();
void ingresarAlumnoEnCualquierPos();
void eliminarAlumnoEnCualquierPos();

int main()
{
	iniciarPrograma();
	return 0;
}

void iniciarLista()
{
	listaAlumnos == NULL;
}

bool listaVacia(tLista *pListaAlumnos)
{
	return pListaAlumnos == NULL;
}

void insertarAlumno(tDato pDato)
{
	if (listaVacia(listaAlumnos))
	{
		insertarPrimero(pDato);
	}
	else
	{
		insertarAdelante(pDato, listaAlumnos);
	}
}

void eliminarAlumno()
{
	if (!listaVacia(listaAlumnos))
	{
		tLista *nodoSuprimir;
		nodoSuprimir = listaAlumnos;
		listaAlumnos = listaAlumnos->siguiente;
		free(nodoSuprimir);
		nodoSuprimir = NULL;
		printf("\nSe elimin�:\nAlumno: %s\nLU: %d", nodoSuprimir->dato.nombreCom, nodoSuprimir->dato.libreta);
	}
	else
	{
		printf("\nNo hay alumnos en la lista.\n");
	}
}

void mostrarAlumno(tLista *pLista)
{
	tLista *aux;
	aux = pLista;
	int alumnos = 0;

	if (listaVacia(aux))
	{
		printf("\nNo hay alumnos en la lista.\n");
	}
	else
	{
		printf("\nAlumnos en la lista:\n\n");
		while (aux != NULL)
		{
			alumnos++;
			printf("LU: %d\nAlumno/a: %s\n\n", aux->dato.libreta, aux->dato.nombreCom);
			aux = aux->siguiente;
		}
		printf("\n\n");
	}
	void insertarPrimero(tDato pDato)
	{
		tLista *nuevoNodo;
		nuevoNodo = (tLista *)malloc(sizeof(tLista));
		nuevoNodo->dato = pDato;
		nuevoNodo->siguiente = NULL;
		listaAlumnos = nuevoNodo;
		printf("\nPrimer alumnno agregado.\n");
	}

	void insertarAdelante(tDato pDato, tLista * pLista)
	{
		tLista *nuevoNodo;
		nuevoNodo = (tLista *)malloc(sizeof(tLista));
		nuevoNodo->dato = pDato;
		nuevoNodo->siguiente = listaAlumnos;
		listaAlumnos = nuevoNodo;
		printf("\nAlumno agregado por delante.");
	}

	void insertarK(int k, tDato pDato)
	{
		tLista *nuevoNodo, *aux;
		int i;
		aux = listaAlumnos;

		if (listaVacia(listaAlumnos))
		{
			insertarPrimero(alumnos);
		}
		else if (k == 1)
		{
			insertarAdelante(pDato, listaAlumnos);
		}
		else
		{
			for (i = 1; i < k - 1; i++)
			{
				aux = aux->siguiente;
			}
		}

		nuevoNodo = (tLista *)malloc(sizeof(tLista));
		nuevoNodo->dato = pDato;
		nuevoNodo->siguiente = aux->siguiente;
		aux->siguiente = nuevoNodo;
		printf("\nAlumno agregado en la posicion %d\n\n", k);
	}

	void eliminarK(int k)
	{
		tLista *nodoSurpimir, *aux;
		int i;
		aux = listaAlumnos;

		if (!listaVacia(listaAlumnos))
		{
			for (i = 1; i < k - 1; i++)
			{
				aux = aux->siguiente;
			}
			nodoSurpimir = aux->siguiente;
			aux->siguiente = nodoSurpimir->siguiente;
			free(nodoSurpimir);
			nodoSurpimir = NULL;
			printf("\nAlumno de la posicion %d eliminado.\n\n");
		}
		else
		{
			printf("\nNo hay alumnos en la lista.\n");
		}
	}

	void iniciarPrograma()
	{
		setlocale(LC_ALL, "spanish");
		iniciarLista();
		menu();
	}

	void opcionesMenu()
	{
		printf("\t\tMENU");
		printf("\n1.Agregar alumnos a la lista/a.\n2.Eliminar alumnos de la lista/a.\n3.Insertar un alumnos en una determinada posici�n dentro de la lista.");
		printf("\n4.Eliminar un alumnos de una determinada posici�n de la lista.\n5.Mostrar alumnos de la lista.\n6.Salir del menu.\n\nDigite una opcion: ");
	}

	void menu()
	{
		int opcionMenu = 0;
		do
		{
			opcionesMenu();
			scanf("%d", &opcionMenu);

			switch (opcionMenu)
			{
			case 1:
				agregarDatosAlumno();
				insertarAlumno(alumnos);
				printf("\n\n");
				system("pause");
				break;
			case 2:
				eliminarAlumno();
				printf("\n\n");
				system("pause");
				break;
			case 3:
				ingresarAlumnoEnCualquierPos();
				printf("\n\n");
				system("pause");
				break;
			case 4:
				eliminarAlumnoEnCualquierPos();
				printf("\n\n");
				system("pause");
				break;
			case 5:
				mostrarAlumno(listaAlumnos);
				printf("\n\n");
				system("pause");
				break;
			case 6:
				printf("\nSaliendo del menu.\n");
				break;
			default:
				printf("\n***OPCION INCORRECTA. DIGITE SOLO LAS OPCIONES DADAS EN EL MENU***");
				break;
			}
			system("cls");
		} while (opcionMenu != 6);
	}

	void agregarDatosAlumno()
	{
		tDato alumnos;
		int opcionD = 0;

		printf("\nDigite numero de libreta: ");
		scanf("%d", &alumnos.libreta);
		printf("\nDigite nombre completo del alumno/a: ");
		fflush(stdin);
		scanf("%[^\n]s", &alumnos.nombreCom);

		/*printf("\nDesea ingresar otro alumno/a a lista? (1.si/2.no): ");
		scanf("%d", &opcionD);*/
	}

	void ingresarAlumnoEnCualquierPos()
	{
		tDato alumnos;
		int posK, opcionK = 0;
		do
		{
			agregarDatosAlumno();
			printf("\nDigite la posicion donde desea agregar el/la sangano/a: ");
			scanf("%d", &posK);
			insertarK(posK, alumnos);

			printf("\nDesea agregar otro alumnos/a en una determinada posicion? (1.si/2.no): ");
			scanf("%d", &opcionK);
		} while (opcionK != 2);
	}

	void eliminarAlumnoEnCualquierPos()
	{
		int posK, opcionE = 0;
		do
		{
			printf("\nDigite una posicion cualquiera para eliminar un alumno/a: ");
			scanf("%d", &posK);
			eliminarK(posK);
			printf("\nDesea eliminar otro alumno/a de una posicion cualquiera? (1.si/2.no): ");
			scanf("%d", &opcionE);
		} while (opcionE != 2);
	}
