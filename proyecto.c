//Proyecto.

#include<stdio.h>					//Librerias anexadas.
#include<stdlib.h>
#include<string.h>
#include<unistd.h> 
#include"lista.h"					//LLamado de libreria de listas.
#define BUFF_LEN 60					//longitud de linea.
#define GIR_LEN 5					//Longitud de giro.
#define CAL_LEN 3					//Longitud de calle.

int main() {
	int i, j, k=0, turn_n, ubi1=0, ubi2=0;											//Varibales para contadares, nro de giros y datos de ubicacion.
	char archivo[BUFF_LEN];															//Variable para la lectura del nombre del archivo.
	vctorchar vector_a[BUFF_LEN];													//Variable para la lectura de una lidena del archivo.
	char primero[GIR_LEN], segundo[GIR_LEN], aux[GIR_LEN], id_giro[GIR_LEN];		//Vectores para lectura de giros y llenado listas.
	char turn_char[CAL_LEN],street1[CAL_LEN],street2[CAL_LEN];						//Vectores para lectura de calles y numero de giros.
	int **matriz;																	//Matriz dinamica, compuesta de doble punteros.
	char *arreglo;
	Node *listag=NULL;																//Lista de giros (nombres).
	Node *listac=NULL;      														//Lista de calles (nombres).	
	FILE *f;																		//Archivo.
	
	/*Inicio del programa*/
	printf("Ingrese el nombre del archivo: ");
	scanf("%s", &archivo);							//Lectura del nombre del archivo.	
	
	/*Abrir archivo*/
	if ((f = fopen(archivo,"r")) == NULL){
		fprintf(stderr, "ERROR DE APERTURA: %s no pudo ser abierto o no existe.\n",archivo);   //Vereficacion en caso que el archivo se encuentre vacio. 
		exit(1);	
	}

	/*Lectura de numero de giros*/
	fscanf(f,"%2s", turn_char);  		//Lee nro. de giros (Primera linea).
	turn_n = atoi(turn_char);    		//Convierte nro. de giros de char a int.
	printf("\n%d\n",turn_n);				//VISUALIZACION DE LECTURA DE NUMERO DE GIRO.
	
	
	/*Lectura de cruces y almacenamiento de las listas*/
	for (i = 0; i < turn_n; i++) {
		fscanf(f, "%2s%2s ", street1, street2);				//Lee de forma separada las calles de un giro.
		strcat(strcpy(id_giro,street1),street2);			//Concatenacion de calles para la formacion del giro.
		printf("\n%s",id_giro);								//VISUALIZACION DE LECTURA DE NOMBRES DE GIROS.
		listag=add_end(listag, new_item("", id_giro));		//Se agrega el giro a la lista de giros.
		
		int cont=0;
		strcpy(aux,street1);						//Por medio de una varieble auxiliar copiamos la calle 1.
        strcpy(vector_a[k],aux);					//Ahora en un vector copiamos esa varable auxiliar.
        k++;										
        for (j=0; j<turn_n; j++) {
            if (strcmp(vector_a[j], aux)==0){		
                cont++;
            }
		}
        if (cont==1) {										//Si el contador es = a 1, esta calle se agragara a la lista de calles.
            listac=add_end(listac, new_item("",street1));		
        }
	}

	printf("\n\nCALLES: ");
	print(listac);   				//Se muestra por pantalla las calles del conjunto.
	printf("\nGIROS: ");             
	print(listag);					//Se muestra por pantalla los giros del conjunto.


	/*Fabricacion e inicializacion de matriz*/
	matriz=(int **)malloc(turn_n *sizeof(int*));		//Reservado de memoria.
		
	for (i = 0; i < turn_n; i++) {
		matriz[i]=(int *)malloc(turn_n *sizeof(int));	//Formacion y inicializacion.
	}
	
	for (i = 0; i < turn_n; i++) {
		for (j = 0; j < turn_n; j++) {
			matriz[i][j]=0;
		}								
	}
	
	
	/*Lectura de cruces incompatibles*/
	while (feof(f) == 0){									//Mientras archivo no sea final de linea.
		fscanf(f, "%4s - %4s", primero, segundo);			//Lectura de giros icompatibles por linea.
		printf("\n%s - %4s", primero, segundo); 			//VISUALIZACION DE GIROS IMCOMPATIBLES.
	    ubi1=posicion(listag,primero);						//Se guarda en una variable el llamda de la funcion.
		ubi2=posicion(listag,segundo);  					
		matriz[ubi1][ubi2]=1;								//Se marca en una posicion especifica en la matriz dinamica un 1. 
		matriz[ubi2][ubi1]=1;
	}
	
	
	printf("\n\n");											//VISUALIZACION DE LLENADO DE GIROS COMPATIBLES E IMCOMPATIBLES DE LA MATRIZ DINAMICA.
	for (i = 0; i < turn_n; i++) {
		for (j = 0; j < turn_n; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");								
	}
	
		
	fclose(f); 
	/*Cierra archivo*/

	/*Proceso de fases optimas*/
	arreglo=(char *)malloc(turn_n *sizeof(char));
	
	int comp=0;
	int incomp=0;
	for (i = 0; i < turn_n; i++) {
		for (j = 0; j < turn_n; j++) {
			if(matriz[i][j]!=1)
				comp++;
			else
				incomp++;
		}								
	}
	
	printf("\nCantidad de giros comaptibles: %d",comp);
	printf("\nCantidad de giros incomaptibles: %d",incomp);
	return 0;
}
