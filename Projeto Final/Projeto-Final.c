#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Projeto-Final.h"


void exibeLista(std::deque<Dado> listaD, std::stack<Dado> ListaStack){
	std::deque<Dado>::iterator i;
	
	
        if(listaD.empty()){
   	 printf("\n+------------------------------------------------------------------------------------------------------------------------------+\n");
     printf("| \t\t\t\t\t\t\tA LISTA ESTÁ VAZIA !\t\t\t\t\t\t       |\n");
     printf("--------------------------------------------------------------------------------------------------------------------------------\n");
 	   
		}else{

	printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
	printf("| \t\t\t\t\t\tCENTRO DE SAÚDE DO LOOP INFINITO\t\t\t\t\t       |\n");
	printf("|                                                                                                                              |\n");		

	printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
	printf("| %-10s | %-50s | %-10s | %-30s | %-12s |\n", "Cod", "Nome", "Idade", "CPF", "Situacao");
	printf("--------------------------------------------------------------------------------------------------------------------------------\n");


 i = listaD.begin();

while(i!= listaD.end() ){
   	
   printf("| %-10d | %-50s | %-10d | %-30lld | %-12s |\n", i->cod, i->nome, i->idade, i->cpf, i->situacao);
   ++i;
}

printf("+------------------------------------------------------------------------------------------------------------------------------+\n");
 }
 
}




void joinList (std::deque<Dado> *listaD, std::stack<Dado> ListaS){
	
	while (!ListaS.empty()) {
		         listaD->push_front(ListaS.top());
		         ListaS.pop();
		       }
}




int adicionaDepois(std::deque<Dado> *listaD, Dado d, int cod){
	
	std::deque<Dado>::iterator i;
	
	for(i = listaD->begin() ; i!= listaD->end() ; i++){
									
		if(i->cod == cod){
			
			listaD->insert(i+1,d);
		
		     return 1;
         }
	}
    return 0;
}


Dado excluiPorCodigo(std::deque<Dado> *listaD, int cod) {
    std::deque<Dado>::iterator i;
	Dado copy;
	
    for (i = listaD->begin(); i != listaD->end(); i++) {
        if (i->cod == cod) {
        	copy = *i;
            listaD->erase(i);
            return copy;
        }
    }
    
	copy.cod = 0;
	return copy;
}
