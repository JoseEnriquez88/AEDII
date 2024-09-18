#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

typedef float reales[5];

typedef struct
{
	char sexo;
	int edad;
	reales peso;
	reales altura;
} tDatos;

typedef struct nodo
{
	tDatos dato;
	struct nodo *siguiente;
} tLista;

tLista *listaPaciente;
tDatos pacientes;

void iniciarLista();
bool listaVacia(tLista *);
void insertarPaciente(tDato);
void eliminarPaciente();
void mostrarPacientes(tLista *);
void insertarAdelante(tDato, tLista *);

void iniciarPrograma();
void opcionesMenu();
void menu();
void agregarDatosPaciente();
bool calcularIMC(int, int);
void menoresPesoBajo(tDato);
void datoSobrepeso(tDato);

int main()
{

	return 0;
}

void iniciarLista()
{
	lista = NULL;
}

bool listaVacia(tLista *pListaPaciente)
{
	return pListaPacientes == NULL;
}

void insertarPaciente(tDato pDato)
{
	tLista *nuevoNodo;
	nuevoNodo = malloc(sizeof(tLista));
	nuevoNodo->dato = pDato;
	nuevoNodo->siguiente = lista;
	lista = nuevoNodo;
	printf("\nPaciente agregado a la lista.\n");
}

void eliminarPaciente()
{
	tLista *nodoSuprimir;
	lista = lista->siguiente;
	free(nodoSuprimir);
	nodoSuprimir = NULL;
	printf("\nPaciente eliminado.\n");
}

void mostrarPacientes(tLista pLista)
{
	tLista *aux;
	aux = pLista;
	int pacientes = 0;

	if (!listaVacia(pLista))
	{
		printf("\nPacientes en la lista:\n\n");
		while (aux != NULL)
		{
			pacientes++;
			printf("")
		}
	}
}

void insertarAdelante(tDato pDato, tLista *tPacientes)
{
}

void iniciarPrograma()
{
	setlocale(LC_ALL, "spanish");
	iniciarLista();
	menu();
}

void opcionesMenu()
{
}

void menu()
{
}

void agregarDatosPaciente()
{
	tDatos pacientes;
	int menor = 0, media = 0, mayor = 0;
	int pesoBajo = 0, pesoNormal = 0, sobrepeso = 0;
	int encuestados = 0,

		printf("\nDigite su sexo (m-masculino.f-femenino): ");
	fflush(stdin);
	scanf("%c", &pacientes.sexo);

	printf("\nDigite su codigo de edad\1. Menor de 15 a�os.\n2.Entre 15 y 30 a�os\n3.M�s de 30 a�os: ");
	scanf("%d", &pacientes.edad);

	printf("\nDigite su peso: ");
	scanf("%f", &pacientes.peso);

	printf("\nDigite su altura: ");
	scanf("%f", &pacientes.altura);
	encuestados++;
	menoresPesoBajo(pacientes);
	datoSobrepeso(pacientes)
}

bool calcularIMC(int pPesoBajo, int pMenor)
{
	return (float)pPesoBajo / pMenor;
}

void menoresPesoBajo(tDato tDato)
{
	int menorPesoBajo = 0;
	if ((< 20) && (pacientes.edad < 15))
	{
		menorPesoBajo++;
	}
}

void datoSobrepeso(tDato pDato)
{
	if (pDato)
}
