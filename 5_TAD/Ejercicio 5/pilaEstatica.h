/*Escribir un TDA para cargar y mostrar los elementos de una pila estática de elementos 
de tipo cadena de caracteres. Luego desarrolle un programa para probar dicho TDA.*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX 10

typedef char tVector[MAX];

typedef struct{
	tVector elementos;
	int tope;
}tPila;

void crearPila();
bool pilaVacia(tPila);
bool pilaLlena(tPila);
void apilar(char[80]);

char tope(tPila);
void mostrarElementos(tPila);

tPila pila;
char palabra[80];
void crearPila(){
	pila.tope = -1;
}

bool pilaVacia(tPila pPila){
	return pPila.tope == -1;
}

bool pilaLlena(tPila pPila){
	return pPila.tope == MAX - 1;
}

void apilar(char pPalabra[80]){
	if(!pilaLlena(pila)){
		pila.tope++;
		strcpy(pila.elementos[pila.tope].palabra, pPalabra);
		printf("\nElementos insertados\n");
	}else{
		printf("\nNo queda lugar en la pila.\n");
	}
}

void mostrarElementos(tPila pPila){
	int i;
	printf("\nElementos en la pila:\n\n");
	for(i=0;i<=pPila.tope;i++){
		printf("%s \n\n", pPila.elementos[i].palabra);
	}
	printf("\n\n");
}

