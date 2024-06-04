#include <stdio.h>
#include <stdlib.h>
#include "listade.h"

void criaLista(ListaDE *lt){
     lt->inicio = NULL;
     lt->fim = NULL;
     lt->n = 0;
}

int incluiNoInicio(ListaDE *lt, Dado d){
    Nodo *pNodo;
    pNodo = (Nodo *) malloc (sizeof (Nodo));
    if (pNodo == NULL)
       return(FALTOU_MEMORIA);
    else {
       pNodo->info = d;
       pNodo->prox = lt->inicio;
       pNodo->ant = NULL;
       
       if (lt->n == 0)
          lt->fim = pNodo;
       else
          lt->inicio->ant = pNodo;  

       lt->inicio = pNodo;
       lt->n++;
       return(SUCESSO);
    }
}

void exibe(ListaDE lt) {
    Nodo *pAux;
    pAux = lt.inicio;

    printf("\nExibindo a Lista\n");
    printf("\t---------------------------------------------------------------------------\n");
    printf("| %-15s  | %-5s | %-25s | %-10s | %-15s  |\n", "End Ant", "cd", "End Nodo", "peso", "End Prox");
    printf("\t---------------------------------------------------------------------------\n");

    while (pAux != NULL) {
        printf("| %-15p | %-5d | %-25p | %-10.2f | %-15p |\n", pAux->ant, pAux->info.cod, pAux, pAux->info.peso, pAux->prox);
        pAux = pAux->prox;
    }

    printf("\t---------------------------------------------------------------------------\n");
    printf("Fim: %p - N = %d\n", lt.fim, lt.n);
}


int quantidadeDeNodos(ListaDE lt){
	if(estaVazia(lt) == LISTA_VAZIA){
		
		return (LISTA_VAZIA);
		
	}else{
		
		return (SUCESSO);
	}
}

int estaVazia(ListaDE lt){
	if(lt.n == 0){
		return (LISTA_VAZIA);
	}else{
		return (SUCESSO);
	}
}

int exibeSituacao(ListaDE lt){
	if(estaVazia(lt) == LISTA_VAZIA){
		
		return (LISTA_VAZIA);
		
	}else{
		
		return (SUCESSO);
}
}

int excluiDoInicio(ListaDE *lt, Dado *d){
	Nodo *ptr;
	
	if(estaVazia(*lt) == LISTA_VAZIA){
		
		return (LISTA_VAZIA);
		
	}else{
		
		ptr = lt->inicio;
		*d = lt->inicio->info;
		
		  if(lt->n == 1){
		  	
		  	lt->fim = NULL;
		  	
		  }else{
		  	lt->inicio->ant = NULL;
		  }
		  
		  lt->inicio = lt->inicio->prox;
		  free(ptr);
		  lt->n--;
		  
		  return (SUCESSO);	  
		
	}
	
	
}

int incluiNoFim(ListaDE *lt, Dado d){
	Nodo *ptr = (Nodo*)malloc(sizeof(Nodo));
	
	if(ptr == NULL){
		
		return (FALTOU_MEMORIA);
		
	}else{
		
		ptr->info = d;
		ptr->prox = NULL;
		
		  if(lt->n == 0){
		  	ptr->ant = NULL;
		  	lt->inicio = ptr;
		  
		  }else{
		  	
		  	ptr->ant = lt->fim;
		  	lt->fim->prox = ptr;
		  	
		  }
		  
		lt->fim = ptr;		  
		lt->n++;
		return (SUCESSO);
	}
	
}

int excluiDoFim(ListaDE *lt, Dado *d){
	Nodo *ptr;
	
	if(estaVazia(*lt) == LISTA_VAZIA){
		
		return (LISTA_VAZIA);
		
	}else{
		ptr = lt->fim;
		*d = lt->fim->info;
		
		    if(lt->n == 1){
		    	lt->inicio = NULL;
		    	lt->fim = NULL;
			}else{
				lt->fim = lt->fim->ant;
				lt->fim->prox = NULL;
			}
		
		lt->n--;
		free(ptr);
		return (SUCESSO);
}
	
}

int incluiDepois(ListaDE *lt, int cod, Dado d) {
    Nodo *ptr, *pNodo;
    
    if (estaVazia(*lt) == LISTA_VAZIA) {
        return (LISTA_VAZIA);
    } else {
        pNodo = lt->inicio;
        while (pNodo != NULL && pNodo->info.cod != cod) {
            pNodo = pNodo->prox;
        }
        
        if (pNodo == NULL) {
            return (CODIGO_INEXISTENTE);
        } else {
            ptr = (Nodo*)malloc(sizeof(Nodo));
            
            if (ptr == NULL) {
                return (FALTOU_MEMORIA);
            } else {
                ptr->info = d;
                ptr->prox = pNodo->prox;
                ptr->ant = pNodo;
                pNodo->prox = ptr;
                
                if (ptr->prox == NULL) {
                    lt->fim = ptr;
                } else {
                    ptr->prox->ant = ptr;
                }
                
                lt->n++;
                return (SUCESSO);
            }
        }
    }
}

int excluiNodo(ListaDE *lt, int cod, Dado *d) {
    Nodo *ptr;
    
    if (estaVazia(*lt) == LISTA_VAZIA) {
        return (LISTA_VAZIA);
    } else {
        ptr = lt->inicio;
        while (ptr != NULL && ptr->info.cod != cod) {
            ptr = ptr->prox;
        }
        
        if (ptr == NULL) {
            return (CODIGO_INEXISTENTE);
        } else {
            *d = ptr->info;
            
            if (ptr->ant == NULL) {
                lt->inicio = ptr->prox;
            } else {
                ptr->ant->prox = ptr->prox;
            }
            
            if (ptr->prox == NULL) {
                lt->fim = ptr->ant;
            } else {
                ptr->prox->ant = ptr->ant;
            }
            
            free(ptr);
            lt->n--;
            return (SUCESSO);
        }
    }
}

int consultaPorCodigo(ListaDE *lt, int cod, Dado *d) {
    Nodo *ptr;
    
    if (estaVazia(*lt) == LISTA_VAZIA) {
        return (LISTA_VAZIA);
    } else {
        ptr = lt->inicio;
        while (ptr != NULL && ptr->info.cod != cod) {
            ptr = ptr->prox;
        }
        
        if (ptr == NULL) {
            return (CODIGO_INEXISTENTE);
        } else {
            *d = ptr->info;
            return (SUCESSO);
        }
    }
}


