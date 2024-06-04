#include <deque>
#include <stack>
#ifndef PROJETO_FINAL_H
#define PROJETO_FINAL_H

#define MAX_PACIENTE 5

typedef struct{
	int cod;
	char nome [50];
	int idade;
	char situacao [15];
	long long int cpf; 
}Dado;

int adicionaDepois(std::deque<Dado> *listaD, Dado d, int cod);
void exibeLista(std::deque<Dado>listaD, std::stack<Dado> ListaStack);
void joinList (std::deque<Dado> *listaD, std::stack<Dado> ListaS);
Dado excluiPorCodigo(std::deque<Dado> *listaD, int cod);

#endif
