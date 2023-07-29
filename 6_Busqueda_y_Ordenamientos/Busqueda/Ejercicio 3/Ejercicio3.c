/*Escribir un programa que permita ingresar por teclado la cantidad de elementos de un vector, 
y cada uno de los valores de los elementos del vector. 
Además, escribir funciones para obtener:

a) el máximo valor almacenado en el vector
b) el mínimo valor almacenado en el vector
c) la media de todos los valores
d) la semisuma (promedio entre el máximo y mínimo).
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#define MAX 10

int mayorElemento(int);
int menorElemento(int);
int mediaDeValores(int);
int obtenerPromedio(int);

void ingresarDatos();
void mostraResultados();
void iniciarPrograma();

int vectorNum[MAX];
int vector; 

int main(){
	iniciarPrograma();
	return 0;
}

int mayorElemento(int pVector){
	int i;
	int mayor = pVector[0];
	for(i=0;i<=MAX;i++){
		if(pVector[i] < mayor){
			mayor = pVector[i];
		}
	}
	return mayor;
}

int menorElemento(int pVector){
	int i;
	int menor = pVector[0];
	for(i=0;i<=MAX;i++){
		if(pVector[i] < menor){
			menor = pVector[i];
		}		
	}
	return menor;
}

int mediaDeValores(int pVector){
	
}

int obtenerPromedio(int pVector){
	int i, caja=0, promedio;
	for(i=0;i<=pVector;i++){
		caja = caja + pVector[i];
	}
	promedio = caja / pVector;
	return promedio;
}

void ingresarDatos(){
	int i;
	printf("\Digite el número de elementos del vector (MAXIMO 10): ");
	scanf("%d", &vector);
	
	for(i=0;i<vector;i++){
		printf("\nDigite los números: ");
		scanf("%d", &numeros[i]);
	}
	menorElemento(vector);
	mayorElemento(vector);
	mediaDeValores(vector);
	obtenerPromedio(vector);
}

void mostraResultados(){
	printf("\nEl máximo valor almacenado en el vector es: %d", mayorElemento(vector));
	printf("\nEl mínimo valor almacenado en el vector es: %d", menorElemento(vector));
	printf("\nLa media de todos los valores en el vector es: %d", mediaDeValores(vector));
	printf("\nLa semisuma (promedio entre el máximo y mínimo) es: %d", obtenerPromedio(vector));
}

void iniciarPrograma(){
	setlocale(LC_ALL, "spanish");
	ingresarDatos();
	mostraResultados();
}

