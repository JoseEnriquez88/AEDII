#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>

typedef struct{
	long codProducto;
	char descripcion[80]; 
	float precioUnitario;
}tDato;

typedef struct nodo{
	tDato datos;
	struct nodo *siguiente;
}tListaProductos;

tDato productos;
tListaProductos * listaProducto;
int cantProducto=0;


void crearLista();
bool listaVacia();
void insertarProducto(tDato);
void eliminarProducto();
void mostrarProducto(tListaProductos *);
void insertarPrimero(tDato);
void insertarAdelante(tDato);
void insertarK(int, tDato);
void eliminarK(int);

void iniciarPrograma();
void menu();
void mostrarMenu();
void agregarDatosProductos();
void preguntarIngresoProducto(tDato);
void preguntarEliminarProducto();

int main(){
	iniciarPrograma();
	return 0;
}

void crearLista(){
	listaProducto = NULL;
}

bool listaVacia(){
	if(listaProducto == NULL){
		return true;
	}else{
		return false;
	}
}

void insertarProducto(tDato pDato){
	if(listaVacia(listaProducto) == true){
		insertarPrimero(pDato);
	}else{
		insertarAdelante(pDato);
	}
}

void eliminarProducto(){
	if(!listaVacia(listaProducto)){
		tListaProductos * nodoSuprimir;
		nodoSuprimir = listaProducto;
		nodoSuprimir = nodoSuprimir->siguiente;
		free(nodoSuprimir);
		nodoSuprimir = NULL;
		printf("\nPrimer producto eliminado.\n\n");
	}else{
		printf("\nNo hay productos en la lista.\n\n");
	}
}

void mostrarProducto(tListaProductos * pListaProducto){
	tListaProductos * aux;
	aux = pListaProducto;
	/*int contProductos;*/
	
	if(!listaVacia(aux)){
		printf("\n\t\tPRODUCTOS EN LA LISTA:\n\n");
		while(aux != NULL){
			cantProducto++;
			printf("Codigo producto: %ld\nDescripción: %s\nPrecio: %.2f\n\n", aux->datos.codProducto, aux->datos.descripcion, aux->datos.precioUnitario);
			aux = aux->siguiente;
		}
	}else{
		printf("\n\t\tNO HAY PRODUCTOS PARA MOSTRAR\n\n");
	}
}

void insertarPrimero(tDato pDato){
	listaProducto = malloc(sizeof(tListaProductos));
	listaProducto->datos = pDato;
	listaProducto->siguiente = NULL;
	printf("\n\t\tPRIMER PRODUCTO AGREGADO\n\n");	
}

void insertarAdelante(tDato pDato){
	tListaProductos * nuevoNodo;
	
	nuevoNodo = malloc(sizeof(tListaProductos));
	nuevoNodo->datos = pDato;
	nuevoNodo->siguiente = listaProducto;
	listaProducto = nuevoNodo;
	printf("\n\t\tPRODUCTO AGREGADO\n");

}


void insertarK(int k, tDato pDato){
	tListaProductos * nuevoNodo, * aux;
	aux = listaProducto;
	int i;
	
	if(!listaVacia(aux)){
		for(i=1;i<k-1;i++){
			aux = aux->siguiente;
		}
		nuevoNodo = malloc(sizeof(tListaProductos));
		nuevoNodo->datos = pDato;
		nuevoNodo->siguiente = aux->siguiente;
		aux->siguiente = nuevoNodo;
		printf("\nProducto agregado en posición %d.\n", k);	
	}else{
		printf("\n\t\tNO HAY ESPACIO EN LA LISTA.\n");
	}
	
	
}

void eliminarK(int k){
	tListaProductos * nodoSuprimir, * aux;
	aux = listaProducto;
	int i;
	
	if(!listaVacia(aux)){
		for(i=1;i<k-1;i++){
			aux = aux->siguiente;
		}
		nodoSuprimir = aux->siguiente;
		aux->siguiente = nodoSuprimir->siguiente;
		free(nodoSuprimir);
		nodoSuprimir = NULL;
		printf("\nSe eliminó producto en posición %d.\n", k);
	}else{
		printf("\n\t\tNO HAY PRODUCTOS A ELIMINAR\n\n");
	}
}


void iniciarPrograma(){
	setlocale(LC_ALL, "spanish");
	crearLista();
	mostrarMenu();
}


void menu(){
	printf("\t\tMENU");
	printf("\n1.Agregar producto.\n2.Eliminar producto.\n3.Mostrar productos.\n4.Salir del menu.\n\nDigite una opción: ");	
}


void mostrarMenu(){
	int opcion=0;
	do{
		menu();
		scanf("%d", &opcion);
		
		switch(opcion){
			case 1:
					agregarDatosProductos();
					preguntarIngresoProducto(productos);
					printf("\n\n");
					system("pause");
					break;
			case 2:
					preguntarEliminarProducto();
					printf("\n\n");
					system("pause");
					break;				
			case 3:
					mostrarProducto(listaProducto);
					printf("\n\n");
					system("pause");
					break;
			case 4:
					printf("\n\t\t---SALIENDO DEL MENU---");
					printf("\n\n");
					system("pause");
					break;
			default:
					printf("\n\t\tOPCIÓN INCORRECTA. DIGITE SOLO LAS OPCIONES DADAS EN EL MENU");
					printf("\n\n");
					system("pause");
					break;
		}
		system("cls");
	}while(opcion != 4);
}

void agregarDatosProductos(){
	printf("\nDigite codigo del producto: ");
	scanf("%ld", &productos.codProducto);
	printf("\nDigite descripción del producto: ");
	fflush(stdin);
	scanf("%[^\n]s", &productos.descripcion);
	printf("\nDigite precio del producto: ");
	scanf("%f", &productos.precioUnitario);
}

void preguntarIngresoProducto(tDato pDato){
	int opcion, posK;
	
	printf("\nQuiere ingresar el producto en cualquier posición? (1.si/2.no): ");
	scanf("%d", &opcion);
	if(opcion == 1){
		printf("\nDigite la posición donde quiere agregar el producto: ");
		scanf("%d", &posK);
		insertarK(posK, pDato);	
	}else{
		insertarProducto(pDato);
	}
	cantProducto++;
}

void preguntarEliminarProducto(){
	int opcionE, posKE;
	
	printf("\nQuiere eliminar el producto de cualquier posición? (1.si/2.no): ");
	scanf("%d", &opcionE);
	
	if(opcionE == 1){
		printf("\nDigite la posición a eliminar: ");
		scanf("%d", &posKE);
		eliminarK(posKE);
	}else{
		eliminarProducto();
	}
	cantProducto++;
}


