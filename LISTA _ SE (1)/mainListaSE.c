#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "listase.h"

int main()
{
	setlocale(LC_ALL, "portuguese");
		  
    int op, cod, teste;
    float peso;
    ListaSE lt;
    Dado d;

    criaLista(&lt);

    do {
    printf("\n");
    printf("0. Fim\n");
	printf("1. Inclui no Inicio\n");
	printf("2. Exibe Lista\n");
	printf("3. Quantidade de Nodos\n");
	printf("4. Exibe Situacao da Lista\n");
	printf("5. Exclui do Inicio\n");
	printf("6. Inclui no Fim\n");
	printf("7. Exclui do Fim\n");
	printf("8. Consulta por Codigo\n");
	printf("9. Inclui Depois\n");
	printf("10. Exclui Nodo\n");
	printf("11. Esta Vazia\n");
	printf("Operacao: ");
        scanf("%d", &op);
        system("cls");

        switch (op) {
            case 0:
			printf("Encerrando...");
			break;
			
			case 1:
                printf("\nVoc� escolheu: Incluir no In�cio\n");
                printf("Informe o C�digo (cd): ");
				scanf("%d", &d.cod);
				printf("Informe o Peso: ");
				scanf("%f", &d.peso);
                if (incluiNoInicio(&lt, d) == 0){
                	 printf("\nOperacao Realizada com Sucesso!\n");
                    exibe(lt);
				}else{
					printf("\nOperacao NAO realizada: Faltou Memoria!\n");
				}
                    
                break;
            case 2:
                printf("\nVoc� escolheu: Exibir Lista\n");
                exibe(lt);
                break;
                
            case 3:
				 	printf("\nVoc� escolheu: Quantidade de Nodos\n");
			 	
			 	    printf("\n--->Existem (%d) dentro da Lista\n", quantidadeDeNodos(lt));		
				
            	break;    
            case 4:
                printf("Voc� escolheu: Exibir Situacao da Lista\n");
                
                if(Situacao(lt) == LISTA_VAZIA){
                	printf("\n--->A lista est� vazia\n");
				}else{
					
					printf("\n--->A lista possui 1 ou mais nodos!\n");
					
				}
                
                
                break;
            case 5:
                printf("Voc� escolheu: Excluir do In�cio\n");
                
				if (excluiDoInicio(&lt, &d) == LISTA_VAZIA){
					 printf("\nOperacao NAO realizada: Lista vazia!\n");
				}else{
					printf("\t|   C�digo --->%3d\n", d.cod);
					printf("\t|   Peso --->%.2fKg\n", d.peso);
					printf("\t|   --->Excluido com Sucesso!\n");
					printf("\t==============================================\n");
				     
				}
                break;
               case 6:
               	
                printf("Voc� escolheu: Incluir no Fim\n");
                
                printf("Informe o C�digo (cd): ");
				scanf("%d", &d.cod);
				printf("Informe o Peso: ");
				scanf("%f", &d.peso);
                 
                 if(incluiNoFim(&lt,d) == FALTOU_MEMORIA){
                 	printf("\nOperacao NAO realizada: Faltou Memoria!\n");
				 }else{ 
				 		
				 	 printf("\nOperacao Realizada com Sucesso!\n");
				 }
                 
                 
               break;
            case 7:
                printf("Voc� escolheu: Excluir do Fim\n");
                if (excluiDoFim(&lt,&d) == SUCESSO){
                printf("\t==============================================\n");
				printf("\t|   Dado encontrado - C�digo: %d\n", d.cod);
				printf("\t|   Peso: %.2f\n", d.peso);
			 	printf("\t|--->Excluido com Sucesso!\n");
				printf("\t==============================================\n");
					                
                    printf("Operacao Realizada com Sucesso!\n");
				}else{
					 printf("\nOperacao NAO realizada: Lista vazia!\n");
				}
                   
                break;
            case 8:
            	printf("Voc� escolheu:Consulta por Codigo \n");
                printf("Informe o C�digo (cd): ");
				scanf("%d", &cod);
				
                if (consultaPorCod(lt, cod, &d) == SUCESSO){
                	printf("\t==============================================\n");
					printf("\t|   Dado encontrado - C�digo: %d\n", d.cod);
					printf("\t|   Peso: %.2f\n", d.peso);
					printf("\t==============================================\n");
				}else{
					 printf("Dado nao encontrado!\n");
				}
                   
                break;
            case 9:
          	    printf("Voc� escolheu: Incluir Depois\n");
            	
				printf("\nInforme o C�digo (cd): \n");
				scanf("%d", &cod);
				
				printf("Informe o C�digo para inserir lista: (cd): ");
				scanf("%d", &d.cod);
				
				printf("Informe o Peso para inserir na lista: ");
				scanf("%f", &d.peso);
            	
            	teste = incluiDepois(&lt,cod, d);
           	   
            	
            	if(teste == LISTA_VAZIA){
            		
				printf("---> LISTA_VAZIA");
				
				}else{
				
				if(teste == FALTOU_MEMORIA ){
					
					printf("\nOperacao NAO realizada: Faltou Memoria!\n\n");
					
				}else if(teste == CODIGO_INEXISTENTE){
					
					printf("---> \nCODIGO_INEXISTENTE\n");
					
				}else{
					
					printf("\nOperacao Realizada com Sucesso!\n");
					
				}
					}
                break;
                
          case 10:
			    printf("Voc� escolheu: Excluir Nodo\n");
			    printf("Informe o c�digo do n� a ser exclu�do: ");
			    scanf("%d", &cod);
			    int resultadoExclusao = excluiNodo(&lt, cod, &d);
			    
			    if (resultadoExclusao == SUCESSO) {
      			    printf("\t==============================================\n");
					printf("\t|   Dado Excluido - C�digo: %d\n", d.cod);
					printf("\t|   Peso: %.2f\n", d.peso);
					printf("\t|--->Excluido com Sucesso!\n");
					printf("\t==============================================\n");
			         
			    } else if (resultadoExclusao == CODIGO_INEXISTENTE) {
			        printf("Nodo com c�digo %d n�o encontrado na lista.\n", cod);
			    } else {
			        printf("A lista est� vazia. Nada para excluir.\n\n");
			    }
    			break;
    			
  			case 11:
  				
				  if(estaVazia(lt) == LISTA_VAZIA){
				  	printf("---> LISTA_VAZIA\n");
				  }else{
				  	printf("A lista possui (%d) nodos\n", quantidadeDeNodos(lt));
				  }
  				
  				break;

            default:
                printf("Operacao Invalida!\n");
      }
      	
    } while (op != 0);

    return 0;

}

