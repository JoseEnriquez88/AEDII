/*Se tiene registrada la informaci�n sobre las notas de los ex�menes finales de los alumnos 
de la facultad durante el presente a�o, en un archivo ordenado en forma ascendente por n�mero 
de libreta. De cada alumno se conoce el:

N�mero de Libreta  Nombre y apellido   C�digo de Materia   Nota Obtenida
(entero)       	   ( char [50] )       (entero)            (real)

Se pide:
a) Listar un rengl�n por alumno con el promedio de notas obtenida.
b) Informar el total de alumnos.
c) Informar el alumno con mejor nota promedio
El formato de salida requerido es:
			ver PDF.

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef char tString[50];

typedef struct{
	int numLibreta;
	tString nombreCompleto;
	int codMateria;
	float notaObtenida;
}tr_alumnos;

FILE * vf_alumnos;
tr_alumnos vr_alumnos;

int numLibretAnt;

int totalAlumnos;
float promedioNotas;

void inicializacion(){
	vf_alumnos = fopen("alumnos.dat", "rb");
	
	if(vf_alumnos != NULL){
		printf("Archivo abierto.\n\n");
	}else{
		printf("\Archivo inexistente.\n\n");
		exit(EXIT_FAILURE);
	}
	
	fread(&vr_alumnos, sizeof(tr_alumnos), 1, vf_alumnos); 
}

void procesoCorte(){
	while(!feof(vf_alumnos)){
		principioCorte();
		while(!feof(vf_alumnos) && vr_alumnos.numLibreta == numLibretAnt){
		unAlumno();
		fread(&vr_alumnos, sizeof(tr_alumnos), 1, vf_alumnos); 	
		}
		finCorte();
	}
}

void finalizacion(){
	
}

void principioCorte(){
	promedioNotas = 0; 
	totalAlumnos = 0;
	
	numLibretAnt = vr_alumnos.numLibreta;
}

void unAlumno(){
	
}

void finCorte(){
	
	fclose(vf_alumnos);
}


