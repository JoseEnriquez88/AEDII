#include<stdio.h>
#include<string.h>
#include<locale.h>

typedef char tString[80];

typedef struct{
	int numCuenta;
	tString nombreCliente;
	int codOperacion; /*1-deposito, 2-extraccion*/
	float importe;	
}tClientes;

FILE * archivo;
tClientes regClientes;

void iniciarProceso();
void grabarArchivo();
void ingresarRespuesta();
void ingresarDatosClientes();
void grabarRegistroClientes();
void finalizarProceso();

void iniciarPrograma();

char respuesta;
int deposito, extraccion;

int main(){
	iniciarPrograma();
	return 0;
}

void iniciarProceso(){
	deposito=0;
	extraccion=0;
	archivo = fopen("Clientes.dat", "wb");
}

void grabarArchivo(){
	ingresarRespuesta();
	while(respuesta != 'n'){
		ingresarDatosClientes();
		grabarRegistroClientes();
		ingresarRespuesta();
	}
}

void ingresarRespuesta(){
	printf("Desea ingresar datos al archivo? s/n: ");
	fflush(stdin); 
	respuesta = tolower(respuesta);
	scanf("%c", &respuesta);
}

void ingresarDatosClientes(){
	printf("\nDigite numero de cuenta del cliente: ");
	scanf("%d", &regClientes.numCuenta);
	printf("\nDigite el nombre completo del cliente: ");
	fflush(stdin);
	scanf("%[^\n]s", regClientes.nombreCliente);
	printf("\nDigite el código de operación a realizar (1-Depósito/2-Extracción): ");
	scanf("%d", &regClientes.codOperacion);
	if(regClientes.codOperacion == 1){
		deposito++;
	}else if(regClientes.codOperacion == 2){
		extraccion++;
	}else{
		printf("\nDIGITE SOLO 1 O 2 SEGUN SEA LA OPERACIÓN A REALIZAR. NO SEA BOLUDO/A\n\n");
	}
	printf("\nDigite el importe a ingresar/extraer: ");
	scanf("%f", &regClientes.importe);
}

void grabarRegistroClientes(){
	fwrite(&regClientes, sizeof(tClientes), 1, archivo);
	printf("\n\n\t\t\t***REGISTRO DEL CLIENTE AGREGADO***\n\n");
}

void finalizarProceso(){
	fclose(archivo);
}

void iniciarPrograma(){
	setlocale(LC_ALL, "spanish");
	iniciarProceso();
	grabarArchivo();
	finalizarProceso();
}
