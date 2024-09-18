// En una clínica la secretaria hace un listado con los nombres y apellidos de los pacientes que van llegando
// para luego ser atendidos en ese orden, también agenda el tipo de cobertura (1-obra social 2-pre-paga 3-
// particular). El médico atiende un máximo de 20 pacientes por día. Se solicita: generar un listado de todos
// los pacientes que van a ser atendidos en el día, conocer si hay turnos disponibles, y realizar una función
// para  borrar  de  la  lista  los  pacientes  a  medida  que  son  atendidos  (utilizar  la  implementación  con  frente
// móvil).

//! listar pacientes => pilas
//! funcion que muestre si hay turnos disponible
//! una vez los pacientes son atentidos borrar de la pila sus turnos

// #ifndef LC_ALL
// #define LC_ALL 0
// #endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#define MAX 20

typedef char tString[50];

typedef struct
{
  tString nombre;
  tString apeliido;
} Turnos;

typedef struct
{
  Turnos pilaTurnos[MAX];
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
void apilar(Turnos pLibros);
void desapilar();
Turnos cima(tPila pPila);
void visualizarElementos(tPila pPila);

int main()
{
  iniciarPrograma();
  return 0;
};

void iniciarPrograma() {};

void menu() {};

void mostrarMenu() {};

void ingresarDatos() {};

void crearPilaVacia() {};

bool pilaVacia(tPila pPila) {};

bool pilaLlena(tPila pPila) {};

void apilar(Turnos pLibros) {};

void desapilar() {};

Turnos cima(tPila pPila) {};

void visualizarElementos(tPila pPila) {};
