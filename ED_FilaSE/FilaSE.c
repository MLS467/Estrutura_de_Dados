#include <stdio.h>
#include <stdlib.h>
#include "FilaSE.h"

void criaFila(FilaSE *fl){
	fl->frente = NULL;
	fl->re = NULL;
}


int insere(FilaSE *fl, Dado dado){
	
	Nodo *ptr = (Nodo*) malloc (sizeof(Nodo));
	
	if(ptr == NULL){
		
		return(FALTOU_MEMORIA);
		
	}else if(fl->frente == NULL){		
		ptr->info.cod = dado.cod;
		ptr->info.peso = dado.peso; 
		fl->re = ptr;
		fl->re->prox = NULL;
		fl->frente = ptr;
		return (SUCESSO);
		
	}else{
		ptr->info.cod = dado.cod;
		ptr->info.peso = dado.peso; 
		fl->re->prox = ptr;
		fl->re = ptr;
		fl->re->prox = NULL;		
		return (SUCESSO);
	}
}


int retira(FilaSE *fl,Dado *dado){
	Nodo *ptr = fl->frente;
	
	if(fl->frente == NULL){
		return (FILA_VAZIA);
	}else{
		dado->cod = fl->frente->info.cod; 
		dado->peso = fl->frente->info.peso;
		fl->frente = fl->frente->prox;
		printf("\n----> ENDEREÇO: %d\n", ptr);
		free(ptr);
		return (SUCESSO);
	}
	
}


int estaVazia(FilaSE fl){
	if(fl.frente == NULL){
		return (FILA_VAZIA);
	}else{
		return (SUCESSO);
	}
}


int consulta(FilaSE fl){
	if(fl.frente == NULL){
		return (FILA_VAZIA);
	}else{
		printf("\n----> COD: %d ----> PESO: %.3fKg\n",fl.frente->info.cod,fl.frente->info.peso);
		return (SUCESSO);
	}
	
}

int exibeFila(FilaSE *fl) {
    Nodo *ptr = fl->frente; 
    
    if (ptr == NULL) {
       printf("\n----> A FILA ESTÁ VAZIA\n");
    } else {
        while (ptr != NULL) {
   	
            printf("\n----> COD: %d ----> PESO:%.3fKg\n", ptr->info.cod, ptr->info.peso);
            ptr = ptr->prox;
           
        }
       printf("\n----> EXIBIDA COM SUCESSO\n");
    }
}

int qtdDeNodos(FilaSE fl){
int contador = 0;

Nodo *ptr = fl.frente;
	if(ptr == NULL){
		return (FILA_VAZIA);
	}else{
		while(ptr != NULL){
		contador += 1;	  	
		ptr = ptr->prox;
	}
	printf("\n---->EXISTEM %d NODOS NA FILA\n", contador);
	return (SUCESSO);
	}	
}

int exibeSituacaoDaFila(FilaSE fl){
	if(fl.frente == NULL){
		return (FILA_VAZIA);
	}else{
	    return (SUCESSO);
	}
}
