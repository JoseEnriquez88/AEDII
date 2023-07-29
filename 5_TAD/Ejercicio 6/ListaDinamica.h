/*Escribir un TDA para cargar y mostrar los elementos de una lista dinámica, en donde el nodo tenga 
un campo identificador de tipo entero y un campo descripción de tipo cadena de caracteres.

Luego desarrolle un programa para probar dicho TDA.*/

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

typedef char tString[80];

typedef struct{
	int entero;
	tString cadena;
}tDatos;

typedef struct nodo{
	tDatos datos;
	struct nodo *siguiente;
}tLista;

tLista * lista;
tDatos listaDatos;

void crearLista();
bool listaVacia(tLista *);
void insertarElemento(tDatos);
void insertarPrimero(tDatos);
void insertarAdelante(tDatos);
void mostrarElementos(tLista *);

void crearLista(){
	lista = NULL;
}

bool listaVacia(tLista * pLista){
	return pLista == NULL;
}

void insertarElemento(tDatos pDato){
	if(listaVacia(lista) == true){
		insertarPrimero(pDato);
	}else{
		insertarAdelante(pDato);
	}
}

void insertarPrimero(tDatos pDato){
	lista = (tLista*) malloc(sizeof(tLista));
	lista->datos = pDato;
	lista->siguiente = NULL;
	printf("\n\tPRIMER ELEMENTO AGREGADO\n\n");
	
}

void insertarAdelante(tDatos pDato){
	tLista * nuevoNodo;
	nuevoNodo = (tLista*) malloc(sizeof(tLista));
	nuevoNodo->datos = pDato;
	nuevoNodo->siguiente = lista;
	lista = nuevoNodo;
	printf("\n\tELEMENTO AGREGADO\n\n");
}

void mostrarElementos(tLista * pLista){
	tLista * aux;
	aux = pLista;
	
	if(!listaVacia(aux)){
		printf("\n\t\tELEMENTOS DE LA LISTA.\n\n");
		while(aux != NULL){
			printf("Entero: %d\nCadena: %s\n\n", aux->datos.entero, aux->datos.cadena);
			aux = aux->siguiente;
		}
	}else{
		printf("\n\tNO HAY ELEMENTOS EN LA LISTA\n\n");
	}
}

