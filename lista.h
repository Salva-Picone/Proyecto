//Libreria de listas.

#include<stdio.h>			//Librerias anexadas.
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define GIR_LEN 5			//Longitud de giro.

typedef struct node {							//Estructura de listas.
	char name[20];
	struct node *next;
} Node;

typedef char vctorchar[GIR_LEN];				//Dato definido para el uso de lectura de giros por medio de arreglos. 

//------------------------------------------------------------------

Node *new_item(char *name, char calle[GIR_LEN]);
Node *add_end(Node *listp, Node *newp);
void print(Node *listp);
int posicion(Node *listp,char *valor);

//--------------------------FUNCIONES-------------------------------      

Node *new_item(char *name, char calle[GIR_LEN]){			/*Creacion de un nuevo item o nodo*/
	Node *newp;
	if((newp=(Node *)malloc(sizeof(Node)))==NULL){
		fprintf(stderr,"new_item: error en malloc\n");
		exit(1);
	}
	strcpy(newp->name,calle);
	newp->next=NULL;
	return newp;
}

Node *add_end(Node *listp, Node *newp){						/*Agragar elemnto a final de lista*/
	Node *p;
	if(listp==NULL)
		return newp;
	for(p=listp;p->next!=NULL;p=p->next);
	p->next = newp;
	return listp;
}

void print(Node *listp){									/*Imprimir lista*/
	printf("-->");
	for(;listp!=NULL;listp=listp->next)
		printf("%s-->",listp->name);
	printf("NULL\n");
}

int posicion(Node *listp,char *valor){  					/*Buscar posicion de la lista*/
	int i;
	
	for(i=0; listp != NULL; listp = listp->next, i++){
		if (strcmp(listp->name,valor) == 0)
			return i;
	}
}

