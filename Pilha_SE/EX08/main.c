#include <stdio.h>
#include <stdlib.h>
#include "pilhaSE.h"

/*
Nome: Maisson Leal da Silva

Data: 30/09/2023
*/

int main() {
    Dado dado;
    Pilha pl;
    int escolha, op;

    do {
        printf("CRIAR UMA PILHA 1.SIM / 0.NAO\n");
        scanf("%d", &op);

        if (op == 0) {
            printf("----> ENCERRANDO...\n");
            break;
        } else if (op == 1) {
            criaPilha(&pl);

            do {
                printf("\n\nMENU:\n");
                printf("1. EMPILHA\n");
                printf("2. DESEMPILHA\n");
                printf("3. VERIFICAR SE ESTA VAZIA\n");
                printf("4. CONSULTAR O TOPO\n");
                printf("5. EXIBIR\n");
                printf("0. SAIR\n\n");

                printf("\nESCOLHA UMA OPCAO: ");
                scanf("%d", &escolha);

                switch (escolha) {
                    case 1:
                        printf("\nOPCAO ESCOLHIDA: EMPILHA\n");

                        printf("\nDIGITE O CODIGO: ");
                        scanf("%d", &dado.cod);

                        printf("\nDIGITE O PESO: ");
                        scanf("%f", &dado.peso);

                        if (empilha(&pl, dado) == FALTOU_MEMORIA) {
                            printf("\n----> FALTOU MEMORIA <----\n");
                        } else {
                            printf("\n----> EMPILHADO COM SUCESSO <----\n");
                        }

                        break;

                    case 2:
                        printf("\nOPCAO ESCOLHIDA: DESEMPILHA\n");

                        if (desempilha(&pl, &dado) == PILHA_VAZIA) {
                            printf("\n----> NAO E POSSIVEL DESEMPILHAR. PILHA VAZIA!\n");
                        } else {
                            printf("\nEXCLUIDO COM SUCESSO!\n");
                            printf("COD ----> %d Peso ----> %.3fKg\n", dado.cod, dado.peso);
                        }

                        break;

                    case 3:
                        printf("\nOPCAO ESCOLHIDA: VERIFICAR SE ESTA VAZIA\n");

                        if (estaVazia(pl) == 1) {
                            printf("\n----> PILHA VAZIA <----\n");
                        } else {
                            printf("\n----> A PILHA CONTEM 1 NODO OU MAIS!\n");
                        }

                        break;

                    case 4:
                        printf("\nOPCAO ESCOLHIDA: CONSULTAR O TOPO\n");

                        if (consultaPilha(&pl) == PILHA_VAZIA) {
                            printf("\n ----> PILHA VAZIA <---- \n");
                        } else {
                            printf("\n ---> CONSULTA CONCLUIDA! <----\n");
                        }

                        break;

                    case 5:
                        exibe(pl);
                        break;

                    case 0:
                        printf("\n----> SAINDO...\n");
                        break;

                    default:
                        printf("\nOPCAO INVALIDA. TENTE NOVAMENTE.\n");
                        break;
                }

            } while (escolha != 0);

        } else {
            printf("\n\nOPCAO INVALIDA. TENTE NOVAMENTE.\n\n");
            
        }

    } while (op != 1);

    return 0;
}

