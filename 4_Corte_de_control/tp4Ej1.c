#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef char tString[50];

typedef struct{
	int numCuenta;
 	tString nombreCliente[50];
 	int codOperacion; /*1-Depósito...2-Extracción*/ 
 	float importe;
}tRegistroCuenta;

FILE * cuenta;
tRegistroCuenta regCuenta;

int numCuentAnt; /*esta variable se controla en while*/

int cantMovimientos;
float totalImporDeposito, totalImporExtraccion;

void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unCuenta();
void finCorte();
void calOperacion();

int main(){
	inicializacion();
	procesoCorte();
	finalizacion();
	
	return 0;
}

void inicializacion(){
	setlocale(LC_ALL, "spanish");
	cuenta = fopen("Cuentas.dat", "rb");

	if(cuenta != NULL){
		printf("\nArchivo abierto\n\n");
	}else{
		printf("Archivo inexistente\n");
		exit(EXIT_FAILURE);
	}
	
	fread(&regCuenta, sizeof(tRegistroCuenta), 1, cuenta);
	

	
}

void procesoCorte(){
	while(!feof(cuenta)){
		principioCorte();
		while(!feof(cuenta) && regCuenta.numCuenta == numCuentAnt){
			unCuenta();
			fread(&regCuenta, sizeof(tRegistroCuenta), 1, cuenta);
		}
		finCorte();
	}
}

void finalizacion(){
	
	
	fclose(cuenta);
}

void principioCorte(){
	cantMovimientos = 0;
	totalImporDeposito = 0;
	totalImporExtraccion = 0;
	
	numCuentAnt = regCuenta.numCuenta;
}

void unCuenta(){
	cantMovimientos = cantMovimientos + 1;
	printf("***DETALLE DE MOVIMIENTOS POR CUENTA***");
	printf("Nro. Cuenta\tDepósito\tExtracción");
	calOperacion();
	
}

void finCorte(){
	printf("Total de movimientos de la cuenta %d: %d", regCuenta.numCuenta);
}

void calOperacion(){
	
	if(regCuenta.codOperacion == 1){
		cantMovimientos++;
		totalImporDeposito = totalImporDeposito + regCuenta.importe;
		printf("\n%d\t%f", regCuenta.numCuenta, regCuenta.importe);
	}
	else if(regCuenta.codOperacion == 2){
		cantMovimientos++;
		totalImporExtraccion = totalImporExtraccion + regCuenta.importe;
		printf("\n%d\t\t\t%f", regCuenta.numCuenta, regCuenta.importe);
	}else{
		printf("\nCodigo incorrecto. Digite de nuevo.\n");
	}
}
