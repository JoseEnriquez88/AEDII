/*Construir un árbol binario de búsqueda, donde el contenido de cada nodo sea un entero positivo, 
y que permita las siguientes acciones:
a) Insertar nodos en el árbol.
b) Saber si el árbol está vacío.
c) Buscar un elemento en el árbol.
d) Eliminar un nodo del árbol.
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

typedef int tElem;

typedef struct nodoArbol{
	tElem contenido;
	struct nodoArbol * hijoIzdo;
	struct nodoArbol * hijoDcho;
}tArbol;

tArbol * arbol;

void crearArbol(tArbol *);
bool arbolVacio(tArbol *);
void insertar(tArbol **, int);
bool consultarArbolVacio(tArbol *);
bool buscar(tArbol *, int);
void busquedaElem();
void eliminar(tArbol **, int);
tArbol * buscar_min(tArbol *);

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

void insertar(tArbol ** pArbol, int pDato){
	if(arbolVacio(*pArbol)){
		(*pArbol) = malloc(sizeof(tArbol));
		if((*pArbol) != NULL){
			(*pArbol)->contenido = pDato;
			(*pArbol)->hijoIzdo = NULL;
			(*pArbol)->hijoDcho = NULL;
		}else{
			printf("No hay memoria.");
		}
	}else{
		if(pDato < (*pArbol)->contenido){
			insertar(&((*pArbol)->hijoIzdo), pDato);
		}else{
			if(pDato > (*pArbol)->contenido){
				insertar(&((*pArbol)->hijoDcho), pDato);	
			}else{
				printf("Valor duplicado.\n");
			}
		}
	}
}

bool consultarArbolVacio(tArbol* pArbol){
	if(arbolVacio(pArbol)){
		return true;
	}else{
		return false;
	}
}

bool buscar(tArbol * pArbol, int pDato){
	if(arbolVacio(pArbol)){
		return false;
	}else{
		if(pDato < pArbol->contenido){
			return buscar(pArbol->hijoIzdo, pDato);
		}else{
			if(pDato > pArbol->contenido){
				return buscar(pArbol->hijoDcho, pDato);
			}else{
				return true;
			}
		}
	}
}

void busquedaElem(){
	int buscarNum;
	printf("\nDigite el número a buscar: ");
	scanf("%d", &buscarNum);
	buscar(arbol, buscarNum);
	printf("\nExiste el valor %d? %s\n", buscarNum, buscar(arbol, buscarNum) ? "si" : "no");
}

void eliminar(tArbol ** pArbol, int pDato){
	tArbol *  aux;
	if(arbolVacio(*pArbol)){
		printf("Elementos encontrado.\n");
	}else{
		if(pDato < (*pArbol)->contenido){
			eliminar(&((*pArbol)->hijoIzdo), pDato);
		}else{
			if(pDato > (*pArbol)->contenido){
				eliminar(&((*pArbol)->hijoDcho), pDato);
			}else{
				if((*pArbol)->hijoIzdo == NULL){
					aux = *pArbol;
					*pArbol = (*pArbol)->hijoDcho;
					free(aux);
				}else{
					if((*pArbol)->hijoIzdo == NULL){
						aux = *pArbol;
						*pArbol = (*pArbol)->hijoDcho;
						free(aux);
					}else{
						aux = buscar_min((*pArbol)->hijoDcho);
						(*pArbol)->contenido = aux->contenido;
						eliminar(&((*pArbol)->hijoDcho), (*pArbol)->contenido);
					}
				}
			}
		}
	}
}

tArbol * buscar_min(tArbol * pArbol){
	if(arbolVacio(pArbol)){
		return NULL;
	}else{
		if(arbolVacio(pArbol->hijoIzdo)){
			return pArbol;
		}else{
			return buscar_min(pArbol->hijoIzdo);
		}
	}
}


void ingresarDatos(){
	int num;
	printf("\nDigite un número entero positivo: ");
	scanf("%d", &num);
	insertar(&arbol, num); 
}

void iniciarPrograma(){
	setlocale(LC_ALL, "spanish");
	crearArbol(arbol);
	mostrarMenu();
}

void menu(){
	printf("\t\tMENÚ.");
	printf("\n\t\t1.Insertar datos en el árbol.\n\t\t2.Saber si el árbol está vacío.");
	printf("\n\t\t3.Buscar un elemento en el árbol.\n\t\t4.Eliminar un nodo del árbol.\n\t\t5.Salir del menú");
	printf("\n\n\t\tDigite una opción: ");
}

void mostrarMenu(){
	int opcion=0, dato;
	do{
		menu();
		scanf("%d", &opcion);
		
		switch(opcion){
			case 1:
					ingresarDatos();
					printf("\n\n");
					system("pause");
					break;
			case 2:
					consultarArbolVacio(arbol);
					printf("\n\n");
					system("pause");
					break;
			case 3:
					busquedaElem();
					printf("\n\n");
					system("pause");
					break;					
			case 4:
					printf("\n\nIngrese el valor del nodo a eliminar: ");
					scanf ("%d", &dato);
					eliminar(&arbol, dato);
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
	}while(opcion != 5);
}

