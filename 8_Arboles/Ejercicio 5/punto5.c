#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

typedef int numEnteros;

typedef struct nodoArbol{
	numEnteros contenido;			
    struct nodoArbol * hijoIzdo;    
    struct nodoArbol * hijoDcho;    
}tArbol;

tArbol * arbol;

void crearArbol(tArbol *);
bool arbolVacio(tArbol *);
void recorrerPreorden(tArbol *);
void recorrerInorden(tArbol *);
void recorrerPostorden(tArbol *);
void insertar(tArbol **, int);

void ingresarDatos();
void iniciarPrograma();
void menu();
void mostrarMenu();

int main(){
	iniciarPrograma();
	return 0;
}

void crearArbol(tArbol * pArbol){
	pArbol = NULL;
}

bool arbolVacio(tArbol * pArbol){
	return pArbol == NULL;
}

void recorrerPreorden(tArbol * pArbol){
	if(pArbol != NULL){
		printf("%d ", pArbol->contenido);
		recorrerPreorden(pArbol->hijoIzdo);
		recorrerPreorden(pArbol->hijoDcho);
	}
}
void recorrerInorden(tArbol * pArbol){
	if(pArbol != NULL){
		recorrerInorden(pArbol->hijoIzdo);
		printf("%d ", pArbol->contenido);
		recorrerInorden(pArbol->hijoDcho);
	}
}

void recorrerPostorden(tArbol * pArbol){
	if(pArbol != NULL){
		recorrerPostorden(pArbol->hijoIzdo);
		recorrerPostorden(pArbol->hijoDcho);
		printf("%d ", pArbol->contenido);
	}
}

void insertar(tArbol ** pArbol, int pNumeros){
	if(arbolVacio(*pArbol)){
		(*pArbol) = malloc(sizeof(tArbol));
		if((*pArbol) != NULL){
			(*pArbol)->contenido = pNumeros;
			(*pArbol)->hijoIzdo = NULL;
			(*pArbol)->hijoDcho = NULL;
		}else{
			printf("\nNo hay memoria disponible\n", pNumeros);
		}
	}else{
		if(pNumeros < ((*pArbol)->contenido)){
			insertar(&((*pArbol)->hijoIzdo), pNumeros);
		}else{
			if(pNumeros > ((*pArbol)->contenido)){
				insertar(&((*pArbol)->hijoDcho), pNumeros);
			}else{
				printf("Valor duplicado.\n");
			}
		}
	}
}

void ingresarDatos(){
	int numeros;
	char opc;
	do{
		printf("\nDigite números para insertar: ");
		scanf("%d", &numeros);
		insertar(&arbol, numeros);
		printf("\nDesea ingresar otro número? (s - si/n - no): ");
		fflush(stdin);
		opc = tolower(opc);
		scanf("%c", &opc);
	
	}while(opc != 'n');
}

void iniciarPrograma(){
	setlocale(LC_ALL, "spanish");
	crearArbol(arbol);
	mostrarMenu();
}
void menu(){
	printf("\t\tMENU");
	printf("\n\t\t1.Ingresar datos.\n\t\t2.Recorrer pre orden.\n\t\t3.Recorrer in orden.\n\t\t4.Recorrer post orden.\n\t\t5.Salir de menú.");
	printf("\n\n\t\tDigite una opción: ");
}

void mostrarMenu(){
	int opc=0;
	do{
		menu();
		scanf("%d", &opc);
		
		switch(opc){
			case 1:
					ingresarDatos();
					printf("\n\n");
					system("pause");
					break;
			case 2:
					recorrerPreorden(arbol);
					printf("\n\n");
					system("pause");
					break;					
			case 3:
					recorrerInorden(arbol);
					printf("\n\n");
					system("pause");
					break;					
			case 4:
					recorrerPostorden(arbol);
					printf("\n\n");
					system("pause");
					break;					
			case 5:
					printf("\n\t\t---SALIENDO DEL MENÚ---");
					printf("\n\n");
					system("pause");
					break;					
			default:
					printf("\n\t\t---OPCIÓN INCORRECTA. DIGITE SOLO LAS OPCIONES DADAS EN EL MENÚ---");
					printf("\n\n");
					system("pause");
					break;
		}
		system("cls");
	}while(opc != 5);
}
