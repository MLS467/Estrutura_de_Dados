#include <stdio.h>
#include <stdlib.h>
#include "listade.h"

int main() {
    int op, cd, peso, resultadoExclusao, teste;
    ListaDE lt;
    Dado d;

    criaLista(&lt);

    do {
        printf("\n0. Sair\n");
        printf("1. Inserir no Inicio\n");
        printf("2. Exibir Lista\n");
        printf("3. Numero de Nodos\n");
        printf("4. Status da Lista\n");
        printf("5. Excluir do Inicio\n");
        printf("6. Inserir no Fim\n");
        printf("7. Excluir do Fim\n");
        printf("8. Buscar por Codigo\n");
        printf("9. Inserir Depois\n");
        printf("10. Excluir Nodo\n");
        printf("Operacao: ");
        scanf("%d", &op);
        system("cls");

        switch (op) {

        case 1:
            printf("Inserir no Inicio\n");
            printf("Informe o Codigo (cd): ");
            scanf("%d", &d.cod);
            printf("Informe o Peso: ");
            scanf("%f", &d.peso);
            if (incluiNoInicio(&lt, d) == SUCESSO) {
                printf("\nOperacao realizada com sucesso!\n");
                exibe(lt);
            } else {
                printf("\nOperacao falhou: Falta de Memoria!\n");
            }
            break;

        case 2:
            printf("Exibir Lista\n");
            exibe(lt);
            break;

        case 3:
            printf("Numero de Nodos\n");
            if (quantidadeDeNodos(lt) == LISTA_VAZIA) {
                printf("\n---> A lista esta vazia\n");
            } else {
                printf("\n---> Existem (%d) nos na lista\n", lt.n);
            }
            break;

        case 4:
            printf("Status da Lista\n");
            if (exibeSituacao(lt) == LISTA_VAZIA) {
                printf("\n---> A lista contem 1 ou mais nos\n");
            } else {
                printf("\n---> A lista esta vazia\n");
            }
            break;

        case 5:
            printf("Excluir do Inicio\n");
            if (excluiDoInicio(&lt, &d) == SUCESSO) {
                printf("\t==============================================\n");
                printf("\t|   Dado Removido - Codigo: %d\n", d.cod);
                printf("\t|   Peso: %.2f\n", d.peso);
                printf("\t==============================================\n");
            } else {
                printf("A lista esta vazia\n");
            }
            break;

        case 6:
            printf("Inserir no Fim\n");
            printf("Informe o Codigo (cd): ");
            scanf("%d", &d.cod);
            printf("Informe o Peso: ");
            scanf("%f", &d.peso);
            if (incluiNoFim(&lt, d) == SUCESSO) {
                printf("\nOperacao realizada com sucesso!\n");
            } else {
                printf("\nOperacao falhou: Falta de Memoria!\n");
            }
            break;

        case 7:
            printf("Excluir do Fim\n");
            printf("Voce escolheu: Excluir do Fim\n");
            if (excluiDoFim(&lt, &d) == SUCESSO) {
                printf("\t==============================================\n");
                printf("\t|   Dado Encontrado - Codigo: %d\n", d.cod);
                printf("\t|   Peso: %.2f\n", d.peso);
                printf("\t==============================================\n");
                printf("\n---> Excluido com sucesso!\n\n");
            } else {
                printf("Operacao falhou: A lista esta vazia!\n");
            }
            break;

        case 8:
            printf("Buscar por Codigo\n");
            printf("Informe o Codigo (cd): ");
            scanf("%d", &cd);
            if (consultaPorCodigo(&lt, cd, &d) == SUCESSO) {
                printf("\t==============================================\n");
                printf("\t|   Dado Encontrado - Codigo: %d\n", d.cod);
                printf("\t|   Peso: %.2f\n", d.peso);
                printf("\t==============================================\n");
            } else {
                printf("\n---> Dado nao encontrado!\n");
            }
            break;

        case 9:
            printf("Inserir Depois\n");
            printf("Voce escolheu: Inserir Depois\n");
            printf("\nInforme o Codigo (cd): \n");
            scanf("%d", &cd);
            printf("Informe o Codigo para inserir na lista (cd): ");
            scanf("%d", &d.cod);
            printf("Informe o Peso para inserir na lista: ");
            scanf("%f", &d.peso);
            teste = incluiDepois(&lt, cd, d);

            if (teste == SUCESSO) {
                printf("\nOperacao realizada com sucesso!\n");
            } else if (teste == LISTA_VAZIA) {
                printf("---> A lista esta vazia\n");
            } else if (teste == FALTOU_MEMORIA) {
                printf("\nOperacao falhou: Falta de Memoria!\n\n");
            } else if (teste == CODIGO_INEXISTENTE) {
                printf("---> Codigo nao existe\n");
            }
            break;

        case 10:
            printf("Excluir Nodo\n");
            printf("Voce escolheu: Excluir Nodo\n");
            printf("Informe o codigo do no a ser excluido: ");
            scanf("%d", &cd);
            int resultadoExclusao = excluiNodo(&lt, cd, &d);

            if (resultadoExclusao == SUCESSO) {
                printf("\t==============================================\n");
                printf("\t|   Dado Removido - Codigo: %d\n", d.cod);
                printf("\t|   Peso: %.2f\n", d.peso);
                printf("\t|---> Excluido com sucesso!\n");
                printf("\t==============================================\n");
            } else if (resultadoExclusao == LISTA_VAZIA) {
                printf("A lista esta vazia. Nada para excluir.\n\n");
            } else if (resultadoExclusao == CODIGO_INEXISTENTE) {
                printf("No com codigo %d nao encontrado na lista.\n");
            }
            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida. Por favor, tente novamente.\n");
        }

    } while (op != 0);

    return 0;
}

