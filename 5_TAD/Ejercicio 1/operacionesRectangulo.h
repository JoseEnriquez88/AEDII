/*Desarrollar un TDA �operacionesRectangulo� que declare y defina (implemente):

a) una funci�n para calcular el per�metro

b) una funci�n para calcular el �rea

Luego escriba un programa en �C� que permita probar ambas funciones del TDA (�rea y per�metro),
el programa que prueba el TDA debe aceptar el ingreso de dos variables (base y altura),
invocar ambas funciones, y mostrar el resultado de las operaciones del TDA.*/

#include <stdio.h>
#include <math.h>

float calcularPerimetro(float, float);
float calcularArea(float, float);

float area, perimetro;

float calcularPerimetro(float pBase, float pAltura)
{
	return perimetro = (float)(pBase * 2) + (pAltura * 2);
}

float calcularArea(float pBase, float pAltura)
{
	return area = (float)(pBase * pAltura);
}
