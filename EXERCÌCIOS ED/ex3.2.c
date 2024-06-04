#include <stdio.h>
#include <stdlib.h>
typedef struct{
int dia, mes, ano;
}Data;

typedef struct{
int matricula;
Data dataNasc;
}Aluno;

main(){
       Aluno aluno; 
       Data dataHoje;
     
       
       printf("Insira a data de hoje, dia/mes/ano:\n");
       scanf("%d %d %d",&dataHoje.dia,&dataHoje.mes,&dataHoje.ano );
       
       do{
       	
       	printf("\nInsira o numero da matricula: ");
       	scanf("%d", &aluno.matricula);
       	
       	fflush(stdin);
       	
       	if(aluno.matricula > 0){
       	printf("\nInsira a data de nascimento, dia/mes/ano:\n ");
       	scanf("%d %d %d", &aluno.dataNasc.dia,&aluno.dataNasc.mes, &aluno.dataNasc.ano);
       
        
        system("cls");
        	if(dataHoje.ano - aluno.dataNasc.ano > 18){		  
			  printf("Ja tem 18 anos ou mais\n");
	       }else if(dataHoje.ano - aluno.dataNasc.ano == 18 ){
	       	if(dataHoje.mes <= aluno.dataNasc.mes && dataHoje.dia <= aluno.dataNasc.dia || dataHoje.mes < aluno.dataNasc.mes && dataHoje.dia > aluno.dataNasc.dia)
		       printf("Ja tem 18 anos \n");
	       }else{
	       	printf("Menor de 18 anos\n");
	       }
       	 
 }
       	
       }while(aluno.matricula>0);
	
}
