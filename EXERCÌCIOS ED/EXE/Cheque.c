#include "Cheque.h"
#include <stdio.h>
#include <String.h>


void criaCheque(Cheque *x, int numeroCheque){
	x->numero = numeroCheque;
	x->valor = 0;
	x->situacao = 0;
}
void exibeCheque(Cheque *x){

char situacao[20];

if (x->situacao == 0) {
    strcpy(situacao, "Em_Branco");
} else if (x->situacao == 1) {
    strcpy(situacao, "Emitido");
} else {
    strcpy(situacao, "Compensado");
}

     printf("Numero do cheque:%d, Valor:%.2f, Situacao: %s\n", x->numero,x->valor,situacao);
	
}

float obtemValor(Cheque *x){
 return x->valor;
	
}

int obtemSituacao(Cheque *x){
  return  x->situacao;
	
}

int obtemNumero(Cheque *x){
	return x->numero;
}

int compensaCheque(Cheque *x){
    if(x->situacao == 1){
    	x->situacao = 2;
    	return 0;
    }else{
    	return 1;
    }
}

int emiteCheque(Cheque *x,float valorCheque){

    if(x->situacao == 0){
    	x->valor += valorCheque;
    	x->situacao = 1;
    	return 0;
    }else{
    	return 1;
    }	
}

