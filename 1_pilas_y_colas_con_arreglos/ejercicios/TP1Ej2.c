// #ifndef LC_ALL
// #define LC_ALL 0
// #endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#define MAX 20

typedef char tString[20];

typedef struct
{
  float pulgadas;
  tString marcaTV;
} Televisor;

typedef struct
{
  Televisor pilaTelevisores[MAX];
  int tope;
} tPila;

tPila pila;

void iniciarPrograma();
void menu();
void mostrarMenu();
void ingresarDatos();
void buscarPorPulgada();

void crearPilaVacia();
bool pilaVacia(tPila pPila);
bool pilaLlena(tPila pPila);
void apilar(Televisor pTelevisor);
void desapilar();
Televisor cima(tPila pPila);
void visualizarElementos(tPila pPila);

//! Función principal
int main()
{
  setlocale(LC_ALL, "");
  iniciarPrograma();
  return 0;
};

void iniciarPrograma()
{
  crearPilaVacia();
  mostrarMenu();
};

void menu()
{
  printf("\t\t\tMENÚ:\n");
  printf("\t1. Cargar la pila con los datos de los televisores\n");
  printf("\t2. Listar los datos de los televisores apilados\n");
  printf("\t3. Quitar un televisor de la pila\n");
  printf("\t4. Mostrar el televisor que se encuentra en el tope\n");
  printf("\t5. Buscar televisores por pulgada\n");
  printf("\t0. Salir\n");
  printf("\n\tSeleccione una opción: ");
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
      visualizarElementos(pila);
      printf("\n\n");
      system("pause");
      break;
    case 3:
      desapilar();
      printf("\n\n");
      system("pause");
      break;
    case 4:
      cima(pila);
      printf("\n\n");
      system("pause");
      break;
    case 5:
      buscarPorPulgada();
      printf("\n\n");
      system("pause");
      break;
    case 0:
      printf("Saliendo del programa...\n");
      printf("\n\n");
      system("pause");
      break;
    default:
      printf("\n\t\t---OPCIÓN INCORRECTA. DIGITE SOLO LAS OPCIONES DADAS EN EL MENÚ---");
      printf("\n\n");
      system("pause");
      break;
    }
    system("cls");
  } while (opcion != 0);
}

void ingresarDatos()
{
  if (pila.tope == MAX - 1)
  {
    printf("\t\n\nLa pila está llena. No se pueden agregar más datos de televisores.");
  }
  Televisor nuevoTelevisor;
  printf("\t\nIngrese las pulgadas del televisor: ");
  scanf("%f", &nuevoTelevisor.pulgadas);
  printf("\t\nIngrese la marca del televisor: ");
  fflush(stdin);
  scanf("%[^\n]", nuevoTelevisor.marcaTV);
  apilar(nuevoTelevisor);
};

void buscarPorPulgada()
{
  if (pilaVacia(pila))
  {
    printf("\n\tLa pila esta vacía. No hay televisores para mostrar.");
  }
  float pulgadas;
  int cantidadTelevisores = 0;

  printf("\t\nIngrese las pulgadas para buscar el televisor: ");
  scanf("%f", &pulgadas);
  int i;
  for (i = 0; i <= pila.tope; i++)
  {
    if (pila.pilaTelevisores[i].pulgadas > pulgadas)
    {
      cantidadTelevisores++;
    }
  }
  printf("\t\nCantidad de televisores con más de %.2f pulgadas: %d\n", pulgadas, cantidadTelevisores);
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

void apilar(Televisor pTelevisor)
{
  if (!pilaLlena(pila))
  {
    pila.tope++;
    pila.pilaTelevisores[pila.tope] = pTelevisor;
    printf("\t\nTelevisor agregado a la pila con éxito.");
  }
  else
  {
    printf("\t\nNo se puede agregar el televisor. La pila está llena.");
  }
};

void desapilar()
{
  pilaVacia(pila) ? printf("\nPila vacía.") : (pila.tope--, printf("\nTelevisor quitado de la pila con éxito."));
};

Televisor cima(tPila pPila)
{
  if (pilaVacia(pila))
  {
    printf("\t\nNo hay televisores en la pila\n");
  }
  return pPila.pilaTelevisores[pPila.tope];
};

void visualizarElementos(tPila pPila)
{
  if (pilaVacia(pila))
  {
    printf("\t\nNo hay televisores en la pila\n");
  }
  printf("\t\nTelevisores en la pila: \n");
  int i;
  for (i = 0; i <= pPila.tope; i++)
  {
    printf("\t\nPulgadas: %.2f.\nMarca: %c. \n", pPila.pilaTelevisores[i].pulgadas, pPila.pilaTelevisores[i].marcaTV);
  }
};
