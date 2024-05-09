// #ifndef LC_ALL
// #define LC_ALL 0
// #endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#define MAX 8

typedef struct
{
  int numContenedor;
} Contenedor;

typedef struct
{
  Contenedor pilaContenedores[MAX];
  int tope;
} tPila;

tPila pila;

void iniciarPrograma();
void menu();
void mostrarMenu();
void ingresarDatos();

void crearPilaVacia();
bool pilaVacia(tPila pPila);
bool pilaLlena(tPila pPila);
void apilar(Contenedor pContenedor);
void desapilar();
Contenedor cima(tPila pPila);
void visualizarElementos(tPila pPila);

int main()
{
  iniciarPrograma();
  return 0;
}

void iniciarPrograma()
{
  setlocale(LC_ALL, "spanish");
  crearPilaVacia();
  mostrarMenu();
};

void menu()
{
  printf("\t\t\tMENÚ");
  printf("\n\t1. Registrar numero de identificacion de contendor.");
  printf("\n\t2. Despachar contenedor de la pila del puerto.");
  printf("\n\t0. Salir.");
  printf("\n\n\tSeleccione una opcion: ");
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
      ingresarDatos();
      printf("\n\n");
      system("pause");
      break;
    case 2:
      desapilar();
      printf("\n\n");
      system("pause");
      break;
    case 0:
      printf("Saliendo del programa...\n");
      printf("\n\n");
      system("pause");
    default:
      printf("\n\t\t---OPCIÓN INCORRECTA. DIGITE SOLO LAS OPCIONES DADAS EN EL MENÚ---");
      printf("\n\n");
      system("pause");
      break;
    }
    system("cls");
  } while (opcion != 0);
};

void ingresarDatos()
{
  if (pilaLlena(pila))
    printf("\t\n\nLa pila del puente se encuentra llena. No se pueden apilar mas contenedores por el momento.");
  Contenedor nuevoContenedor;
  printf("\t\nIngrese el numero de identificacion del contenedor: ");
  scanf("%d", &nuevoContenedor.numContenedor);
  apilar(nuevoContenedor);
};

void crearPilaVacia()
{
  pila.tope = -1;
};

bool pilaVacia(tPila pPila)
{
  return pPila.tope == -1;
};

bool pilaLlena(tPila pPila)
{
  return pPila.tope == (MAX - 1);
};

void apilar(Contenedor pContenedor)
{
  if (!pilaLlena(pila))
  {
    pila.tope++;
    pila.pilaContenedores[pila.tope] = pContenedor;
    printf("\t\nContenedor agregado a la pila del puerto con exito.");
  }
  else
  {
    printf("\t\nNo se pudo agregar el contenedor. La pila del puenta esta llena.");
  }
};

void desapilar()
{
  pilaVacia(pila) ? printf("\nPila vacía.") : (pila.tope--, printf("\nTelevisor quitado de la pila con éxito."));
};

Contenedor cima(tPila pPila)
{
  if (pilaVacia(pila))
    printf("\t\nNo hay contenedores en la pila del puerto.");
  return pPila.pilaContenedores[pPila.tope];
}
