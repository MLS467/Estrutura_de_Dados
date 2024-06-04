#include <stdio.h>
#include <stdlib.h>
#include <deque>

typedef struct {
    int cod;
    float peso;
} Dado;

int main() {
    
    FILE *arq;
    Dado dado;
    int op, cod, peso, cd;
    std::deque<Dado> lista;
    std::deque<Dado>::iterator i;

    do {
        printf("-------------------------MENU----------------------\n");
        printf("(0)-FIM\n");
        printf("(1)-INCLUI NO INICIO\n");
        printf("(2)-EXIBE LISTA\n");
        printf("(3)-QUANTIDADE DE NODOS\n");
        printf("(4)-EXIBE SITUACAO DA LISTA\n");
        printf("(5)-EXCLUI DO INiCIO\n");
        printf("(6)-INCLUI NO FIM\n");
        printf("(7)-EXCLUI DO FIM\n");
        printf("(8)-CONSULTA POR CODIGO\n");
        printf("(9)-INCLUI DEPOIS\n");
        printf("(10)-EXCLUI NODO\n");
        printf("(11)-GRAVAR ARQUIVO\n");
        printf("(12)-LER ARQUIVO\n\n");

        printf("Escolha a opcao: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("Digite o codigo:\n");
                scanf ("%d", &dado.cod);
                printf("Digite o peso:\n");
                scanf("%f", &dado.peso);
                lista.push_front(dado);
                printf("Operacao Realizada com Sucesso!\n");
                break;
                
            case 2:
                for (i = lista.begin(); i != lista.end(); i++) {
                    printf("cod: %d\n", i->cod);
                    printf("peso: %f\n", i->peso);
                }
                break;
                 
            case 3:
                printf("Quantidade de nodos: %d\n", lista.size());
                break;
                 
            case 4:
                if(lista.empty()) {
                    printf("Lista vazia!\n");
                } else {
                    printf("A lista possui 1 ou mais nodos.\n");
                }
                break;
                 
            case 5:
                if (lista.empty()) {
                    printf("Lista vazia!\n");
                } else {
                    lista.erase(lista.begin());
                    printf("Operacao realizada com sucesso!\n");
                }
                break;
                 
            case 6:
                printf("Digite o codigo:\n");
                scanf("%d", &dado.cod);
                printf("Digite o peso:\n");
                scanf("%f", &dado.peso);
                if (lista.empty()) {
                    printf("Lista vazia!\n");
                } else {
                    lista.push_back(dado);
                    printf("Operacao realizada com sucesso!\n");
                }
                break;
                 
            case 7:
                if (lista.empty()) {
                    printf("Lista vazia!\n");
                } else {
                    lista.erase(lista.end());
                    printf("Operacao realizada com sucesso!\n");
                }   
                break;
            
            case 8:
                printf("Digite o codigo do nodo a ser encontrado:\n");
                scanf("%d", &cd);
                for (i = lista.begin(); i != lista.end(); i++) {
                    if (i->cod == cd) {
                        printf("\n%d - %f\n", i->cod, i->peso);
                        printf("O dado foi encontrado!");
                    }
                }
                break;
                 
            case 9:
                printf("Digite o codigo de referência:\n");
                scanf("%d", &cd);
                printf("Digite o codigo:\n");
                scanf ("%d", &dado.cod);
                printf("Digite o peso:\n");
                scanf("%f", &dado.peso);
                if (lista.empty()) {
                    printf("\nLista vazia!\n");
                } else {
                    for (i = lista.begin(); i != lista.end(); i++) {
                        if (i->cod == cd) {
                            lista.insert(i+1, dado);
                        }
                    }
                }
                break;    
                
            case 10:
                printf("Digite o codigo do nodo da lista a ser excluido:\n");
                scanf("%d", &cd);
                if (lista.empty()) {
                    printf("\nLista vazia!\n");
                } else {
                    for (i = lista.begin(); i != lista.end(); i++) {
                        if (i->cod == cd) {
                            lista.erase(i);
                        }
                    }
                } 
                break;
                    
            case 11:
                arq = fopen("Arquivo.txt", "w");
                for (i = lista.begin(); i != lista.end(); i++) {
                    fprintf(arq, "%d - %f\n", i->cod, i->peso);
                }
                fclose(arq);
                printf("\nDados gravados!\n");
                break;
                
            case 12:
                arq = fopen("Arquivo.txt", "r");
                while (fscanf(arq, "%d - %f\n", &dado.cod, &dado.peso) != EOF) {
                    lista.push_back(dado);
                }
                fclose(arq);
                printf("\nDados lidos!\n");
                break;
           
        }
        
        if (op != 0) {
            
            for (i = lista.begin(); i != lista.end(); i++) {
          	 
			       printf("Codigo---> %d, Peso---> %.3f Kg\n", i->cod, i->peso);
			       printf("\n");

            }
            printf("\n");  
        } else {
            printf("\nPrograma encerrado.\n");
        }
               
    } while (op!=0);  

    return(0);
}

