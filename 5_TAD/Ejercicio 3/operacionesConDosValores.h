/*Desarrollar un TDA "operacionesConDosValores.h" que declare e implemente las siguientes funciones 
para comparar dos valores enteros:

a) calcular el mayor valor

b) calcular el menor valor

c) determinar si los valores son iguales

d) intercambiar los valores->Recuerde que debera usar pasaje de valores por referencia

Luego escriba un programa para probar dicha libreria (TDA) que permita el ingreso de dos valores enteros 
y mediante la utilizacion de las funciones del TDA permita visualizar cual es el mayor valor, cual es el menor, 
o si los valores son iguales. 
Por ultimo, utilice la funcion para intercambiar y verifique que los valores se intercambien.
*/
#include<stdio.h>
#include<stdbool.h>

int calcularMayorValor(int, int);
int calcularMenorValor(int, int);
bool calcularValoresEnteros(int, int);
void intercambioDeValores(int , int );

int calcularMayorValor(int n1, int n2){
	if(n1 > n2){
		return n1;
	}else{
		return n2;
	}
}

int calcularMenorValor(int n1, int n2){
	if(n1 < n2){
		return n1;
	}else{
		return n2;
	}
}

bool calcularValoresEnteros(int n1, int n2){
	if(n1 == n2){
		return true;
	/*printf("\nLas dos variables son iguales.");*/
	}else{
		return false;
	/*	printf("\nLas dos variables NO son iguales."); */
	}
}

void intercambioDeValores(int n1, int n2){
	int aux;
	aux = n1;
	n1 = n2;
	n2 = aux;
}


