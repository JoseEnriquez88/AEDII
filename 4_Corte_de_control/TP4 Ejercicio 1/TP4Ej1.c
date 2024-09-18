#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef char tString[80];

typedef struct
{
	int numCuenta;
	tString nombreCliente;
	int codOperacion; /*1-deposito, 2-extraccion*/
	float importe;
} tClientes;

FILE *archivo;
tClientes regClientes;

void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unCliente();
void finCorte();

int numcuentaAnt;
// contadores
int cantMovDepositos, cantMovExtraccion;
// acumuladores
float importeDepositos, importeExtraccion;

int main()
{
	inicializacion();
	procesoCorte();
	finalizacion();
	return 0;
}

void inicializacion()
{
	setlocale(LC_ALL, "spanish");
	archivo = fopen("Clientes.dat", "rb");

	if (archivo != NULL)
	{
		fread(&regClientes, sizeof(tClientes), 1, archivo);
	}
	else
	{
		exit(EXIT_FAILURE);
	}

	printf("*** DETALLES DE MOVIMIENTOS POR CUENTA ***\n\n");
	printf("Nro. Cuenta\t Dep�sito\t Extracci�n");
}

void procesoCorte()
{
	while (!feof(archivo))
	{
		procesoCorte();
		while (!feof(archivo) && regClientes.numCuenta == numcuentaAnt)
		{
			unCliente();
			fread(&regClientes, sizeof(tClientes), 1, archivo);
		}
		finCorte();
	}
}

void finalizacion()
{
	fclose(archivo);
}

void principioCorte()
{
	cantMovDepositos = 0;
	cantMovExtraccion = 0;
	importeDepositos = 0;
	importeExtraccion = 0;

	numcuentaAnt = regClientes.numCuenta;
}

void unCliente()
{
	if (regClientes.codOperacion == 1)
	{
		cantMovDepositos++;
		importeDepositos = importeDepositos + regClientes.codOperacion;
		printf("\n%d\t%d.\n", regClientes.numCuenta, regClientes.codOperacion);
	}
	else if (regClientes.codOperacion == 2)
	{
		cantMovExtraccion++;
		importeExtraccion = importeExtraccion + regClientes.codOperacion;
		printf("\n%d\t%d.\n", regClientes.numCuenta, regClientes.codOperacion);
	}
	else
	{
		printf("\nTe re cabe y lo sabes ameo/a.");
	}
}

void finCorte()
{
	printf("\nTotal Cta %d.\t%f\t%f\n", regClientes.numCuenta, importeDepositos, importeExtraccion);
	printf("\nCantidad movimientos cuenta: %d.\t%d\t%d\n", regClientes.numCuenta, cantMovDepositos, cantMovExtraccion);
}
