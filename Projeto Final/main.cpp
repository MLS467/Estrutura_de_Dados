#include <stdio.h>
#include <stdlib.h>
#include <locale>
#include <string.h>
#include <deque>
#include <stack>
#include <iostream>
#include "Projeto-Final.h"

int main() {
	
    setlocale(LC_ALL, "portuguese");
    char desligar;
    int opcao, op, cod, codigo, aux = 3,excluir, proximoCodigo = 1;
    Dado dado;
    std::deque<Dado> listaDeque;
    std::deque<Dado>::iterator i;
    std::stack<Dado> ListaStack;

    do {
        printf("\n\n\n");

	      printf(" +------------------------------------------------------------------------------+\n");
	      printf(" ¦                          CENTRO DE SAÚDE DO LOOP INFINITO                    ¦\n");
	      printf(" +------------------------------------------------------------------------------+\n");

		printf("\n\n\n+------------------------- Classificação de Risco -------------------------+\n\n\n");
		printf("\n1. Cor: Vermelho\n");
		printf("   - Descrição: Emergente (Vermelho) - Situações que requerem atenção e intervenção imediatas.\n");
		
		printf("\n2. Cor: Amarelo (Urgente/Pouco Urgente)\n");
		printf("   - Descrição: Casos muito urgentes e urgentes que demandam atendimento relativamente rápido.\n");
		
		printf("\n3. Cor: Azul (Não Urgente)\n");
		printf("   - Descrição: Casos que não são urgentes e podem esperar um período mais prolongado antes de receberem atendimento.\n");
		printf("\n\n\n+------------------------- MENU ---------------------------+\n\n\n");
		printf("\nEscolha o estado do paciente:\n\n");
		printf(" - Opção 1: Cor: Vermelho (Emergente)\n");
		printf(" - Opção 2: Cor: Amarelo (Urgente)\n");
		printf(" - Opção 3: Cor: Azul (Não Urgente)\n");
		printf(" - Opção 4: Excluir registro\n");
		printf(" - Opção 5: Exibir Lista de pacientes\n");
		printf(" - Opção 0: Desligar sistema\n");
		printf("\n+----------------------------------------------------------+\n\n\n");




        printf("\nDigite o número da opção: ");
        scanf("%d", &opcao);

#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        switch (opcao) {
    	   case 1:
		            printf("Você escolheu: Vermelho (Emergente)\n");
		            printf("\n0. Voltar\n");
		            printf("1. Adicionar paciente no topo\n");
					
		            printf("\nDigite a operação desejada: ");
		            scanf("%d", &op);
		
		            switch (op) {
		            case 0:
		                printf("Voltar...\n");
		                break;
		
		            case 1: 
		               
					    if ((!listaDeque.empty()) && (!ListaStack.empty())) {
		                    printf("+----------------------------------------------------------------------------------------------------------------------------+\n");
		                    printf("| %-10s | %-50s | %-10s | %-30s | %-10s |\n", "Cod", "Nome", "Idade", "CPF", "Situacao");
		                    printf("+----------------------------------------------------------------------------------------------------------------------------+\n");
							listaDeque.pop_front();
							dado = ListaStack.top();
						    printf("| %-10d | %-50s | %-10d | %-30lld | %-10s |\n", dado.cod, dado.nome, dado.idade, dado.cpf, dado.situacao);
		                    printf("+----------------------------------------------------------------------------------------------------------------------------+\n");
		                    printf("| \t\t\t\t\t\t\tPACIENTE ATENDIDO !\t\t\t\t\t\t     |\n");
		                    printf("+----------------------------------------------------------------------------------------------------------------------------+\n");
		                    ListaStack.pop();
							
		                }
		                	
						
		
		                dado.cod = proximoCodigo++ ;
		                
		                fflush(stdin);
		                printf("\nDigite o nome do paciente: ");
		                scanf("%50[^\n]s", dado.nome);
		                
		                fflush(stdin);
		                printf("Digite a idade do paciente: ");
		                scanf("%d", &dado.idade);
		
		                printf("Digite o CPF do paciente: ");
		                scanf("%lld", &dado.cpf);
		
		                strcpy(dado.situacao, "Emergente");
		
		                ListaStack.push(dado);
		
		                printf("\nOs dados foram guardados com sucesso!\n");
		
		                joinList(&listaDeque, ListaStack);
		                exibeLista(listaDeque, ListaStack);
						
		                break;
		
                    default:
		            	 printf("\n");
		                 printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
		                 printf("| \t\t\t\t\t\t\t CÓDIGO INVÁLIDO !\t\t\t\t\t\t       |\n");
		                 printf("--------------------------------------------------------------------------------------------------------------------------------\n");
		                break;
		            }
		
            break;

        case 2:
		            printf("Você escolheu: Amarelo e Laranja (Urgente)\n");
					printf("\nOpção 0: Voltar\n");
		            printf("\nOpção 1: Adicionar por código\n");
		            
					
		            printf("\nDigite a operação desejada: ");
		            scanf("%d", &op);
		
		            switch (op) {
		            case 0:
			                printf("Voltar...\n");
                    break;
		
		            case 1: 
		            
		            	   if (listaDeque.size() >= MAX_PACIENTE) {
		                    printf("+----------------------------------------------------------------------------------------------------------------------------+\n");
		                    printf("| %-10s | %-50s | %-10s | %-30s | %-10s |\n", "Cod", "Nome", "Idade", "CPF", "Situacao");
		                    printf("+----------------------------------------------------------------------------------------------------------------------------+\n");
		                    i = listaDeque.begin();
		                    printf("| %-10d | %-50s | %-10d | %-30lld | %-10s |\n", i->cod, i->nome, i->idade, i->cpf, i->situacao);
		                    printf("+----------------------------------------------------------------------------------------------------------------------------+\n");
		                    printf("| \t\t\t\t\t\t\tPACIENTE ATENDIDO !\t\t\t\t\t\t     |\n");
		                    printf("+----------------------------------------------------------------------------------------------------------------------------+\n");
		                    listaDeque.pop_front();
		                }
		            
			                
			
			                if (!listaDeque.empty()) {
			                	exibeLista(listaDeque, ListaStack);
			                	
								dado.cod = proximoCodigo++;
			                    printf("\nDigite o código de referencia\n");
			                    scanf("%d", &codigo);
			
			                    fflush(stdin);
			                    printf("Digite o nome do paciente: ");
			                    scanf("%50[^\n]s", dado.nome);
			                    fflush(stdin);
			
			                    printf("Digite a idade do paciente: ");
			                    scanf("%d", &dado.idade);
			
			                    printf("Digite o CPF do paciente: ");
			                    scanf("%lld", &dado.cpf);
			
			                    strcpy(dado.situacao, "Urgente");
			
								
			                    aux = adicionaDepois(&listaDeque, dado, codigo);
			                    
			                }else{
			                	
			                	dado.cod = proximoCodigo++;
			                	
               	                fflush(stdin);
				                printf("Digite o nome do paciente: ");
				                scanf("%50[^\n]s", dado.nome);
				
				                printf("Digite a idade do paciente: ");
				                scanf("%d", &dado.idade);
				
				                printf("Digite o CPF do paciente: ");
				                scanf("%lld", &dado.cpf);
				
				                strcpy(dado.situacao, "Urgente");
				                
				                listaDeque.push_back(dado);
				                
							}
			
			                if (aux == 0) {
			                    printf("\nCÓDIGO INEXISTENTE!\n");
			                } else if (aux == 1) {
			                	
			                    printf("\nOS DADOS FORAM ARMAZENADOS COM SUCESSO!\n");
			                }
			
			                exibeLista(listaDeque, ListaStack);
			
                    break;
                    
                    default:
                   	 printf("\n");
	                 printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
	                 printf("| \t\t\t\t\t\t\t CÓDIGO INVÁLIDO !\t\t\t\t\t\t       |\n");
	                 printf("--------------------------------------------------------------------------------------------------------------------------------\n");
	                break;
	            
  
			    }
			    
			    
			      
		break;

        case 3:
	            printf("Você escolheu: Azul (Não Urgente)\n");
	            printf("\nOpção 0: Voltar\n");
	            printf("Opção 1: Adicionar não urgente \n");
	           
			    
	            printf("\nDigite a operação desejada: ");
	            scanf("%d", &op);
	
	            switch (op) {
	            case 0:
	                printf("Voltar...\n");
	                break;
	
	            case 1:
	            	
	            	    if (listaDeque.size() >= MAX_PACIENTE) {
		                    printf("+----------------------------------------------------------------------------------------------------------------------------+\n");
		                    printf("| %-10s | %-50s | %-10s | %-30s | %-10s |\n", "Cod", "Nome", "Idade", "CPF", "Situacao");
		                    printf("+----------------------------------------------------------------------------------------------------------------------------+\n");
		                    i = listaDeque.begin();
		                    printf("| %-10d | %-50s | %-10d | %-30lld | %-10s |\n", i->cod, i->nome, i->idade, i->cpf, i->situacao);
		                    printf("+----------------------------------------------------------------------------------------------------------------------------+\n");
		                    printf("| \t\t\t\t\t\t\tPACIENTE ATENDIDO !\t\t\t\t\t\t     |\n");
		                    printf("+----------------------------------------------------------------------------------------------------------------------------+\n");
		                    listaDeque.pop_front();
		                }
	            	
	            	
		                fflush(stdin);
		                printf("Digite o nome do paciente: ");
		                scanf("%50[^\n]s", dado.nome);
		
		                printf("Digite a idade do paciente: ");
		                scanf("%d", &dado.idade);
		
		                printf("Digite o CPF do paciente: ");
		                scanf("%lld", &dado.cpf);
		
		                strcpy(dado.situacao, "Não-Urgente");
		
		                dado.cod = proximoCodigo++ ;
		                
						
		                listaDeque.push_back(dado);
		                
		                
		                exibeLista(listaDeque, ListaStack);
		
		                break;
	
	            default:
	                printf("\n");
	                 printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
	                 printf("| \t\t\t\t\t\t\t CÓDIGO INVÁLIDO !\t\t\t\t\t\t       |\n");
	                 printf("--------------------------------------------------------------------------------------------------------------------------------\n");
	                
	                break;
	            }
	
         break;

        case 4:
			 		printf("0. Voltar...\n");	  
		            printf("1. Excluir registro do topo\n");
		            printf("2. Excluir por código\n");
		            printf("3. Excluir todos registros...\n");
					printf("4. Excluir no fim\n");
		            printf("\nDigite a operação desejada: ");
		            scanf("%d", &op);
		
                switch (op) {
		            	
		            case 0:
					printf("\nVoltar...\n");
					break;
						
		            	
		            case 1:
		                if (listaDeque.empty()) {
						   	printf("\n");					
		                    printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
		                    printf("| \t\t\t\t\t\t\tA LISTA ESTÁ VAZIA !\t\t\t\t\t\t       |\n");
		                    printf("--------------------------------------------------------------------------------------------------------------------------------\n");
		                
						} else {
		
		                    printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
		                    printf("| %-10s | %-50s | %-10s | %-30s | %-12s |\n", "Cod", "Nome", "Idade", "CPF", "Situacao");
		                    printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
		                    i = listaDeque.begin();
		                    printf("| %-10d | %-50s | %-10d | %-30lld | %-12s |\n", i->cod, i->nome, i->idade, i->cpf, i->situacao);
		                    printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
		                    printf("| \t\t\t\t\t\t\tEXCLUÍDO COM SUCESSO !\t\t\t\t\t\t       |\n");
		                    printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
		                    listaDeque.pop_front();
		                    if(!ListaStack.empty())
							ListaStack.pop();
		                    printf("\n\n");
		                    exibeLista(listaDeque, ListaStack);
		                    
		                }
		            break;    
		            
		                
		                
               case 2:
           			 exibeLista(listaDeque, ListaStack);
            	
		           	 printf("\nPor favor, insira o valor do código de referência: ");
		             scanf("%d", &codigo);
		
					 if (listaDeque.empty()) {
				 	  printf("\n");
					  printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
				      printf("| \t\t\t\t\t\t\tA LISTA ESTÁ VAZIA !\t\t\t\t\t\t       |\n");
		              printf("--------------------------------------------------------------------------------------------------------------------------------\n");
					 
					 }else{
					 	
					 	dado = excluiPorCodigo(&listaDeque,codigo);
					 	
					 	if(dado.cod != 0){
						     
							 printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
				             printf("| %-10s | %-50s | %-10s | %-30s | %-12s |\n", "Cod", "Nome", "Idade", "CPF", "Situacao");
				             printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
				             printf("| %-10d | %-50s | %-10d | %-30lld | %-10s |\n", dado.cod, dado.nome, dado.idade, dado.cpf, dado.situacao);
				             printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
				             printf("| \t\t\t\t\t\t\tEXCLUÍDO COM SUCESSO !\t\t\t\t\t\t       |\n");
				             printf("+------------------------------------------------------------------------------------------------------------------------------+\n");	
								  if(!ListaStack.empty()){
								  ListaStack.pop();
							}
							}else{
							 printf("\n");
							 printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
			                 printf("| \t\t\t\t\t\t\t CÓDIGO INVÁLIDO !\t\t\t\t\t\t       |\n");
			                 printf("--------------------------------------------------------------------------------------------------------------------------------\n");
							}
						}
						
						

                   break;
                   
                case 3:
				
					if(!listaDeque.empty()){
							
				                printf("Deseja excluir todos os registros? S\\N \n");
				                scanf(" %c", &excluir);
				
				                if (excluir != 's' && excluir != 'n') {
						                    printf("\n[ERRO] Opção inválida, considerado N\n");
						                    excluir = 'n';
				                }
				
		                         excluir = tolower(excluir);
		                         
				                if(excluir == 's'){
										
										while(!listaDeque.empty()){
											listaDeque.pop_front();
											if(!ListaStack.empty()){
												ListaStack.pop();
											 }
											}
					     		 		 printf("\n");
									     printf("\n Todos os dados foram excluidos com sucesso \n");
									 	 printf("\n");
										 
										 exibeLista(listaDeque, ListaStack);
									 
									 }else if(excluir == 'n'){
									 	printf("\nOperação cancelada.\n");
									 }
				      
						}else{
    	 	           		  exibeLista(listaDeque, ListaStack);
							}
    	 	           
    	 	           break;
    	 	           
                   case 4:
    	 	           	if(listaDeque.empty()){
    	 	           		printf("\n");
					  		printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
				      		printf("| \t\t\t\t\t\t\tA LISTA ESTÁ VAZIA !\t\t\t\t\t\t       |\n");
		              		printf("--------------------------------------------------------------------------------------------------------------------------------\n");
    	 	           		
							}else{
						    printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
		                    printf("| %-10s | %-50s | %-10s | %-30s | %-12s |\n", "Cod", "Nome", "Idade", "CPF", "Situacao");
		                    printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
		                    i = listaDeque.end();
		                    --i;
		                    printf("| %-10d | %-50s | %-10d | %-30lld | %-12s |\n", i->cod, i->nome, i->idade, i->cpf, i->situacao);
		                    printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
		                    printf("| \t\t\t\t\t\t\tEXCLUÍDO COM SUCESSO !\t\t\t\t\t\t       |\n");
		                    printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
							listaDeque.pop_back();
    	 	           	    exibeLista(listaDeque, ListaStack);
							}
    	 	           	
    	 	           	break;
    	 	           
    	 	           
    	 	           
    	 	           
	                         default:
                         	 printf("\n");
				        	 printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
			                 printf("| \t\t\t\t\t\t\t CÓDIGO INVÁLIDO !\t\t\t\t\t\t       |\n");
			                 printf("--------------------------------------------------------------------------------------------------------------------------------\n");
				        	 
					         break;
		
		    }
		   
        break;
		
		
        case 0: 

		               
                printf("Deseja desligar o sistema S\\N \n");
                scanf(" %c", &desligar);

                if (desligar != 's' && desligar != 'n') {
                    printf("\n[ERRO] Opção inválida, considerado N\n");
                    desligar = 'n';
                }

                desligar = tolower(desligar);
         break;
         
         case 5:
         	
         	exibeLista(listaDeque, ListaStack);
         	
         break;
         

        default:
        	
        	 printf("\n");
             printf("+----------------------------------------------------------------------------------------------------------------------------+\n");
    		 printf("| \t\t\t\t\t\t\tA CÓDIGO INVÁLIDO !\t\t\t\t\t             |\n");
    		 printf("+----------------------------------------------------------------------------------------------------------------------------+\n");
       
	   break;
    
}

    } while (!(desligar == 's'));
    printf("\n");
    printf("+----------------------------------------------------------------------------------------------------------------------------+\n");
    printf("| \t\t\t\t\t\t\tA FINALIZADO COM SUCESSO !\t\t\t\t\t     |\n");
    printf("+----------------------------------------------------------------------------------------------------------------------------+\n");

}
