#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "FilaSE.h"

main() {
    
	setlocale(LC_ALL, "Portuguese"); 
  
  // usei o locale porque é mais fácil para usar no meu teclado!
    
	
	FilaSE fl;
    Dado dado;
   
    int opcao;
    
    criaFila(&fl);
   
    do {
        printf("0. Fim\n");
        printf("1. Insere\n");
        printf("2. Retira\n");
        printf("3. Quantidade de nodos\n");
        printf("4. Exibe situação da fila\n");
        printf("5. Consulta frente\n");
        printf("6. Exibe Fila\n");
        printf("7. Verifica se a fila está vazia.\n");
        printf("\nEscolha uma opção:\n");
        scanf("%d", &opcao);
        system("cls");
        
       switch (opcao) {
    case 0:
        printf("FIM.\n");
        break;

    case 1:
        printf("INSERE.\n");

        printf("\nDIGITE UM CÓDIGO:\n");
        scanf("%d", &dado.cod);

        printf("DIGITE O PESO:\n");
        scanf("%f", &dado.peso);

        if (insere(&fl, dado) == FALTOU_MEMORIA) {
            printf("\n----> FALTOU MEMÓRIA\n");
        } else {
            printf("\n----> DADOS ARMAZENADOS COM SUCESSO\n");
        }

        break;

    case 2:
        printf("RETIRA.\n");

        if (retira(&fl, &dado) == FILA_VAZIA) {
            printf("\n----> A FILA ESTÁ VAZIA\n");
        } else {
            printf("\n----> DADO EXCLUÍDO COM SUCESSO\n");
            printf("\n----> COD:%d ----> PESO:%.3f Kg\n", dado.cod, dado.peso);
        }

        break;

    case 3:
        printf("QUANTIDADE DE NODOS.\n");

        if (qtdDeNodos(fl) == FILA_VAZIA) {
           printf("\n----> A FILA ESTÁ VAZIA\n");
        } else {
            printf("\n----> FILA EXIBIDA COM SUCESSO\n");
        }

        break;

    case 4:
        printf("EXIBE SITUAÇÃO DA FILA.\n");

        if (exibeSituacaoDaFila(fl) == FILA_VAZIA) {
            printf("\n----> A FILA ESTÁ VAZIA\n");
        } else {
            printf("\n----> A FILA POSSUI 1 OU MAIS NODOS\n");
        }

        break;

    case 5:
        printf("CONSULTA FRENTE.\n");

        if (consulta(fl) == FILA_VAZIA) {
           printf("\n----> A FILA ESTÁ VAZIA\n");
        } else {
            printf("\n----> CONSULTA CONCLUÍDA\n");
        }

        break;

    case 6:
        printf("EXIBE FILA.\n");

        exibeFila(&fl);

        break;

    case 7:
        printf("VERIFICA SE A FILA ESTÁ VAZIA.\n");

        if (estaVazia(fl) == FILA_VAZIA) {
            printf("\n----> A FILA ESTÁ VAZIA\n");
        } else {
            printf("\n----> A FILA NÃO ESTÁ VAZIA\n");
        }

        break;

    default:
        printf("\n----> OPÇÃO INVÁLIDA.\n");

}

        printf("\n");
        
    } while (opcao != 0);
    
    
}

