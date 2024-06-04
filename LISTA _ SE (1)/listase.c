#include <stdio.h>
#include <stdlib.h>
#include "listase.h"

void criaLista(ListaSE *lt){
     lt->inicio = NULL;
}

int incluiNoInicio(ListaSE *lt, Dado d){
    Nodo *pNodo;
    pNodo = (Nodo *) malloc (sizeof (Nodo));
    if (pNodo == NULL)
       return(FALTOU_MEMORIA);
    else {
       pNodo->info = d;
       pNodo->prox = lt->inicio;
       lt->inicio = pNodo;
       return(SUCESSO);
    }
}
 
void exibe(ListaSE lt){
   	Nodo *pAux;
     int c = 0 ;
     pAux = lt.inicio;
   
    if(pAux == NULL){
    	printf("---> LISTA_VAZIA\n");
	}else{
	
     printf("\nInicio: %p \n", lt.inicio);
     printf("Exibindo a Lista\n");
     printf("\n");
     while (pAux != NULL) {
     	   c++;
     	    printf("\t===================(%d)=======================\n",c);
			printf("\t|    EndProx --->%p\n", pAux->prox);
			printf("\t|    EndNodo --->%p\n", pAux);
			printf("\t|    Código --- >%3d  Peso --->%.2fKg\n", pAux->info.cod, pAux->info.peso);
			printf("\t==============================================\n");

           pAux = pAux->prox;
     }
}
	}
	
	 

int quantidadeDeNodos(ListaSE lt){
    int conta=0;
    Nodo *pAux;
    
    pAux = lt.inicio;
    
    while (pAux != NULL) {
           conta++;
           pAux = pAux->prox;
    }
    return(conta);
}


int estaVazia(ListaSE lt){
    if (lt.inicio==NULL)
       return(LISTA_VAZIA);
    else
       return(SUCESSO);     
}


int excluiDoInicio(ListaSE *lt, Dado *d){
	Nodo *ptr = lt->inicio;;
	
	if(ptr == NULL){
			return (LISTA_VAZIA);	
	}else{
		*d = lt->inicio->info;
		 lt->inicio = lt->inicio->prox;
		 free(ptr);
	     printf("\t==============================================\n");
			printf("\t|    Excluido\n");
			printf("\t|    EndNodo --->%p\n", ptr);
			printf("\t|    EndProx ---> %p\n", ptr->prox);
			printf("\n");
		
		 return (SUCESSO);
	}
	
}

int Situacao(ListaSE lt){
	
	if(lt.inicio == NULL){
		return (LISTA_VAZIA);
	}else{
		return (SUCESSO);
	}
	
}

int incluiNoFim(ListaSE *lt, Dado d){
	Nodo *ptr, *copy;
	
	ptr = (Nodo*)malloc(sizeof(Nodo));
	
	copy = lt->inicio;
	
	if(ptr == NULL){
		return (FALTOU_MEMORIA);
	}else if(copy == NULL){
		
		incluiNoInicio(lt,d);
		
	}else{
		do{
			if(copy->prox == NULL){
			
			ptr->info = d;
			copy->prox = ptr;
			ptr->prox = NULL;
			
			return (SUCESSO);
			
			}
			
             copy = copy->prox;
			
		}while(copy != NULL);
	}
		
}


int excluiDoFim(ListaSE *lt, Dado *d){
	Nodo *copy, *aux; 
	
	copy = lt->inicio;

	
	if(lt->inicio == NULL){
			return (LISTA_VAZIA);	
	}else if(quantidadeDeNodos(*lt) == 1){
		  *d = copy->info;
		   free(copy);
		   lt->inicio = NULL;
		return (SUCESSO);
	} else{
		
		do{
			if(copy->prox == NULL){
			*d = copy->info;
			aux->prox = NULL;
			free(copy);
			return (SUCESSO);
			}
			 aux = copy;
             copy = copy->prox;
			
		}while(copy != NULL);
		
		 return (SUCESSO);
	}
	
	
}

int consultaPorCod(ListaSE lt, int cod, Dado *d){

	while (lt.inicio != NULL) {
		
		if(lt.inicio->info.cod == cod){
			*d = lt.inicio->info;
			
			return (SUCESSO);
		}
		
           lt.inicio = lt.inicio->prox;
     }
     
     return (CODIGO_INEXISTENTE);
}




int incluiDepois(ListaSE *lt, int cod, Dado d){

	Nodo *ptr = (Nodo *) malloc (sizeof (Nodo));
  	Nodo *copy, *aux;
  	copy = lt->inicio;
  	
    if(ptr == NULL){
    	
    	return (FALTOU_MEMORIA);
    	
	}
	
	if(copy == NULL){
		
		return (LISTA_VAZIA);
		
	}else{
		
		while (copy != NULL) {
		
		 if(copy->info.cod == cod){
   		    aux = copy;	
			
			ptr->info = d;
			
			ptr->prox = aux->prox;
			
			aux->prox = ptr;
			
			return (SUCESSO);
		}
		 	
           copy = copy->prox;
     }
 	 
	 
	  	return (CODIGO_INEXISTENTE);
	 
     
	}
	
}

int excluiNodo(ListaSE *lt, int cod, Dado *d) {
    Nodo *copy, *aux = NULL;

    if (lt->inicio == NULL) {
        return LISTA_VAZIA;
    }

    copy = lt->inicio;

    while (copy != NULL) {
        if (copy->info.cod == cod) {
            if (aux == NULL) {
                lt->inicio = copy->prox;
            } else {
                aux->prox = copy->prox;
            }

            if (d != NULL) {
                *d = copy->info;
            }

            free(copy);

            return SUCESSO;
        }

        aux = copy;
        copy = copy->prox;
    }

    return CODIGO_INEXISTENTE;
}


