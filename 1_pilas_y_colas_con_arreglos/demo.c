#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef int tArrayEnteros[MAX];

typedef struct
{
  tArrayEnteros listaEnteros;
  int tope;
} tPila;

tPila pila;

// Definicion de funciones
void iniciarPrograma();

void crearPilaVacia();
bool pilaVacia(tPila);
bool pillaLlena(tPila);
void apilar(int);
void desapilar();
int cima(tPila);
void visualizarElementos(tPila);

int main()
{
  iniciarPrograma();
  return 0;
}

void iniciarPrograma()
{
  crearPilaVacia();
  printf("Pila vacía %s\n", pilaVacia(pila) ? "si" : "no");
  apilar(1);
  printf("Pila vacía %s\n", pilaVacia(pila) ? "si" : "no");
  apilar(2);
  apilar(3);
  apilar(4);
  visualizarElementos(pila);
  desapilar();
  visualizarElementos(pila);
  printf("Elemento en cima %d\n", cima(pila));
};

void crearPilaVacia()
{
  pila.tope = -1;
};

bool pilaVacia(tPila pPila)
{
  if (pPila.tope == -1)
    return true;
  return false;
};

bool pillaLlena(tPila pPila)
{
  if (pPila.tope == (MAX - 1))
    return true;
  return false;
};

void apilar(int pElemento)
{
  if (pillaLlena(pila) != true)
  {
    pila.tope = pila.tope + 1;
    pila.listaEnteros[pila.tope] = pElemento;
    printf("Elemento insertado: %d\n", pila.listaEnteros[pila.tope]);
  }
  else
  {
    printf("Pila llena!\n");
  }
};

void desapilar()
{
  if (pilaVacia(pila) == true)
  {
    printf("Pila vacía");
  }
  else
  {
    pila.listaEnteros[pila.tope] = 0;
    pila.tope = pila.tope - 1;
    printf("Se quitó un elemento \n");
  }
};

int cima(tPila pPila)
{
  return pPila.listaEnteros[pPila.tope];
};

void visualizarElementos(tPila pPila)
{
  int i;
  printf("Elementos en la pila: \n");
  for (i = 0; i <= pPila.tope; i++)
  {
    printf("%d\n", pPila.listaEnteros[i]);
  }
};
