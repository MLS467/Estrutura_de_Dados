#ifndef FilaSE_H
#define FilaSE_H

#define SUCESSO 0
#define FILA_VAZIA 1
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
 Nodo *frente;
 Nodo *re;
} FilaSE;

void criaFila(FilaSE *fl);
int insere(FilaSE *fl, Dado dado);
int retira(FilaSE *fl,Dado *dado);
int estaVazia(FilaSE fl);
int consulta(FilaSE fl);
int qtdDeNodos(FilaSE fl);
int exibeSituacaoDaFila(FilaSE fl);
int exibeFila(FilaSE *fl);

#endif
