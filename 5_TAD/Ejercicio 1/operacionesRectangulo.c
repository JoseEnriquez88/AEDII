/*Luego escriba un programa en “C” que permita probar ambas funciones del TDA (área y perímetro), 
el programa que prueba el TDA debe aceptar el ingreso de dos variables (base y altura), 
invocar ambas funciones, y mostrar el resultado de las operaciones del TDA*/

#include<stdio.h>
#include<locale.h>
#include "operacionesRectangulo.h"

void ingresarDatos();
void mostrarResultados();
void iniciarPrograma();

float base, altura;

int main(){
	iniciarPrograma();
	return 0;
}

void ingresarDatos(){
	printf("Digite la base del rectángulo: ");
	scanf("%f", &base);
	printf("\nDigite la altura del rectángulo: ");
	scanf("%f", &altura);
	
	calcularPerimetro(base, altura);
	calcularArea(base, altura);
}

void mostrarResultados(){
	/*mostrando resultado de perímetro*/
	printf("\n\nEl perímetro del rectángulo es: %.2f", calcularPerimetro(base, altura));

	/*mostrando resultado de área*/
	printf("\nEl área del rectángulo es: %.2f", calcularArea(base, altura));
}

void iniciarPrograma(){
	setlocale(LC_ALL, "spanish");
	ingresarDatos();
	mostrarResultados();
}
