#include <stdio.h>

typedef struct{
 int hora,
 minuto,
 segundo; 
}Horario; 

main(){
	Horario hor1,hor2; 
	
	
	
	
	printf("Insira um horario:\n");
	scanf("%d %d %d",&hor1.hora,&hor1.minuto,&hor1.segundo);
	
	printf("Insira outro horario:\n");
	scanf("%d %d %d",&hor2.hora,&hor2.minuto,&hor2.segundo);	
	
	//hora2.hora > hor1.hora 
	
	if(hor2.hora>hor1.hora || hor2.hora == hor1.hora && hor2.minuto>hor1.minuto || hor2.hora ==  hor1.hora && hor2.minuto == hor1.minuto && hor2.segundo>hor1.segundo){	       
		printf("%d:%d:%d", hor1.hora,hor1.minuto, hor1.segundo );
	}else if(hor2.hora<hor1.hora || hor2.hora == hor1.hora && hor2.minuto<hor1.minuto || hor2.hora ==  hor1.hora && hor2.minuto == hor1.minuto && hor2.segundo<hor1.segundo){
	   printf("%d:%d:%d", hor2.hora,hor2.minuto, hor2.segundo );
	}else{
		printf("Horarios Iguais");
	}
	
	
}
