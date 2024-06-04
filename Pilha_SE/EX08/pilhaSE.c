#include <stdio.h>
#include <stdlib.h>
#include "pilhaSE.h"

void criaPilha(Pilha *pl){
	pl->topo = NULL;
	printf("PILHA CRIADA COM SUCESSO!\n");
}


int empilha(Pilha *pl , Dado dado){
	Nodo *ptr = (Nodo *)malloc(sizeof(Nodo));
	
	if(ptr == NULL){
		return (FALTOU_MEMORIA);
	}else{
		ptr->info = dado;
		ptr->prox = pl->topo;
		pl->topo = ptr;	
		
		return (SUCESSO);
	}	
}

int consultaPilha(Pilha *pl){
	if(pl->topo == NULL){
		return (PILHA_VAZIA);
	}else{
		printf("TOPO --->%d\n", pl->topo);
		printf("COD ---> %d, PESO ---> %.3fKg\n", pl->topo->info.cod , pl->topo->info.peso);
		return (SUCESSO);
	}
	
}

int desempilha(Pilha *pl, Dado *dado){
Nodo *ptr;
	
	if(pl->topo == NULL){
		
		return (PILHA_VAZIA);
		
	}else{
	
	*dado = pl->topo->info;
     ptr = pl->topo->prox;
	 
 	 free(pl->topo);
	 
	 pl->topo = ptr;
	 	
 	
	return (SUCESSO);
	
	}
}

int estaVazia(Pilha p){
	if(p.topo == NULL){
		return 1;
	}else{
		return 0;
	}
}

void exibe(Pilha pl){
	
	Nodo *ptr = pl.topo;
	
	if(ptr == NULL){
		printf("\n ----> PILHA_VAZIA <----\n");
	}else{
		
		while(ptr != NULL){
		
	       printf("COD ----> %d Peso ----> %.3fKg\n", ptr->info.cod, ptr->info.peso);
		   ptr = ptr->prox;
		   
		   }
	}
}
