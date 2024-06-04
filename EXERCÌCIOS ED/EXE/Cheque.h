#ifndef Cheque_H
#define Cheque_H

typedef struct {
 int numero;
 float valor;
 int situacao;	
}Cheque;

int emiteCheque(Cheque *x,float valorCheque);
int compensaCheque(Cheque *x);
void criaCheque(Cheque *x, int numeroCheque);
void exibeCheque(Cheque *x);
float obtemValor(Cheque *x);
int obtemSituacao (Cheque *x);	
int obtemNumero(Cheque *x);

#endif
