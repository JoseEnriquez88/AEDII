/*Escribir un TAD �operacionesBasicas� que permita calcular las operaciones de suma, resta, 
multiplicaci�n y divisi�n de una calculadora para dos valores float. 

Luego desarrolle un programa en �C� que a partir del ingreso de dos variables reales y el operador 
(+: suma, -: resta, *: multiplicaci�n, /: divisi�n), 
invoque al TDA y muestre los resultados de la operaci�n seleccionada.*/

#include<stdio.h>

float suma(float x, float y);
float resta(float x, float y);
float multiplicacion(float x, float y);
float division(float x, float y);

float suma(float x, float y){
	float resultado;
	return resultado = (float) x + y;
}

float resta(float x, float y){
	float resultado;
	return resultado = (float) x - y;
}

float multiplicacion(float x, float y){
	float resultado;
	return resultado = (float) x * y;	
}

float division(float x, float y){
	float resultado;
	return resultado = (float) x / y;	
}
