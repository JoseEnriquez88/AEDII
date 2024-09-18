// En una librería, al no tener más lugar en los estantes, se van acomodando los libros en pilas de hasta 30
// libros como máximo. Escribir un programa que permita:
// ▪ ingresar los ISBN, título y editorial de los libros
// ▪ listar los últimos 5 libros apilados
// ▪ eliminar de la pila los libros a medida que se solicitan
// ▪ detectar cuál es el libro que está en el TOPE

// #ifndef LC_ALL
// #define LC_ALL 0
// #endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#define MAX 30

typedef char tString[30];

typedef struct
{
  tString ISBN;
  tString titulo;
  tString editorial;
} Libros;

typedef struct
{
  Libros pilaLibros[MAX];
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
void apilar(Libros pLibros);
void desapilar();
Libros cima(tPila pPila);
void visualizarElementos(tPila pPila);

int main()
{
  iniciarPrograma();
  return 0;
};

void iniciarPrograma()
{
  setlocale(LC_ALL, "spanish");
  crearPilaVacia();
  mostrarMenu();
};

void menu()
{
  printf("\t\t\tMENÚ");
  printf("\n\t1. Registrar los datos del libro y apilar.");
  printf("\n\t2. Listar los ultimos 5 libros apilados.");
  printf("\n\t3. Solicitar libro para quitar de la pila.");
  printf("\n\t4. Mostrar libro que se encuentra en el tope de la pila.");
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
      printf("\n\n");
      system("pause");
      break;
    case 3:
      printf("\n\n");
      system("pause");
      break;
    case 4:
      cima(pila);
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
    printf("\t\n\nLa pila de libros se encuentra llena. No se pueden apilar mas libros por el momento.");
  Libros nuevoLibro;
  printf("\n\tIngrese el ISBN del libro: ");
  scanf('%[^\n]', &nuevoLibro.ISBN);
  printf("\n\tIngrese el titulo del libro: ");
  scanf('%[^\n]', &nuevoLibro.titulo);
  printf("\n\tIngrese la editorial del libro: ");
  scanf('%[^\n]', &nuevoLibro.editorial);
  apilar(nuevoLibro);
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

void apilar(Libros pLibros)
{
  if (!pilaLlena(pila))
  {
    pila.tope++;
    pila.pilaLibros[pila.tope] = pLibros;
    printf("\t\nLibro agregado a la pila con exito.");
  }
  else
  {
    printf("\t\nNo se pudo agregar el libro a la pila. La pila de libro se encuentra llena");
  }
};

void desapilar()
{
  pilaVacia(pila) ? printf("\nPila vacía.") : (pila.tope--, printf("\nLibro quitado de la pila con éxito."));
};

Libros cima(tPila pPila)
{
  if (pilaVacia(pila))
    printf("\t\nNo hay libros apilados.");
  return pPila.pilaLibros[pPila.tope];
};

void visualizarElementos(tPila pPila) {};
