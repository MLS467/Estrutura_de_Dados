#ifndef pilhaSE_H
#define pilhaSE_H

#define SUCESSO 0
#define PILHA_VAZIA 1
#define FALTOU_MEMORIA 2



typedef struct {
 int cod;
 float peso;
} Dado;

typedef struct nodo Nodo;

struct nodo {
 Dado info;
 Nodo *prox;
};

typedef struct {
 Nodo *topo;
} Pilha;

int consultaPilha(Pilha *pl);
void criaPilha(Pilha *pl);
int empilha(Pilha *pl , Dado dado);
int desempilha(Pilha *pl, Dado *dado);
int estaVazia(Pilha p);

#endif
