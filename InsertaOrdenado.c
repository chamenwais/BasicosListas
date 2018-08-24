/*
 * InsertaOrdenado.c
 *
 *  Created on: 20 ago. 2018
 *      Author: utnso
 */

#include <stdio.h>

typedef struct node {
	int val;
	struct node * next;
} PNode;

void print_list(PNode * head);

void insertarOrdenado(PNode ** lst, int valor);

int main(){
	int listaAleatoria[5];
	listaAleatoria[0] = 4;
	listaAleatoria[1] = 5;
	listaAleatoria[2] = 2;
	listaAleatoria[3] = 1;
	listaAleatoria[4] = 7;
	PNode * p=NULL;
	for(int i=0;i<=4;i++){
		insertarOrdenado(&p, listaAleatoria[i]);
	}
	print_list(p);
	liberarMemoria(p);
	return 0;
}

void insertarOrdenado(PNode ** lst, int valor){
	PNode * nuevo = malloc(sizeof(PNode));
	nuevo->val=valor;
	if(*lst==NULL){
		nuevo->next=NULL;
		*lst=nuevo;
		return;
	}
	if (valor<(*lst)->val){
		nuevo->next=*lst;
		*lst=nuevo;
		return;
	}
	PNode * aux=*lst;
	PNode * ant=NULL;
	while((aux!=NULL)&&(aux->val<=valor)){
		ant=aux;
		aux=aux->next;
	}
	if(aux==NULL){
		ant->next=nuevo;
		nuevo->next=NULL;
	} else {
		ant->next=nuevo;
		nuevo->next=aux;
	}
}

void print_list(PNode * head){
	PNode * current = head;
	while(current !=NULL){
		printf("%d\n", current->val);
		current = current->next;
	}
}

void liberarMemoria(PNode * head){
	PNode * current = head;
	while(current !=NULL){
		PNode * aux = current;
		free(current);
		current = aux->next;
	}
}
