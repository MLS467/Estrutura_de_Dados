#include <stdio.h>
#include <stdlib.h>
#include "Cheque.h"

main() {
	int numCheque1,numCheque2;
	char situacao[][20] = {"Em_branco", "Emitido", "Compensado"};
	Cheque cheque1, cheque2;
	float valorCheque1, valorCheque2;
	
	printf("Insira o numero do Cheque (1): ");
	scanf("%d", &numCheque1);
	criaCheque(&cheque1,numCheque1);
	
	printf("Insira o numero do Cheque (2): ");
	scanf("%d", &numCheque2);
	criaCheque(&cheque2,numCheque2);

                      // cheques começam em branco //	
//	printf("Situacao cheque 1:%s\n",situacao[obtemSituacao(&cheque1)]);
//	printf("Situacao cheque 2:%s\n",situacao[obtemSituacao(&cheque2)]);
	
	printf("Insira o valor do Cheque (1): ");
	scanf("%f", &valorCheque1);
	emiteCheque(&cheque1, valorCheque1);
	
	printf("Insira o valor do Cheque (2): ");
	scanf("%f", &valorCheque2);
	emiteCheque(&cheque2, valorCheque2);
	
	system("cls");
	exibeCheque(&cheque1);
	exibeCheque(&cheque2);
	printf("\n");
	printf("Valor/Cheque(1): %.2f\n", obtemValor(&cheque1));
	printf("Valor/Cheque(2): %.2f\n", obtemValor(&cheque2));	
	printf("\n");
	if(obtemValor(&cheque1)> obtemValor(&cheque2)){
		compensaCheque(&cheque1);
	}else{
		compensaCheque(&cheque2);
	}
	
	
	printf("Situacao cheque (1):%s\n",situacao[obtemSituacao(&cheque1)]);
	printf("Situacao cheque (2):%s\n",situacao[obtemSituacao(&cheque2)]);
	printf("\n");
	printf("Numero cheque (1):%d\n",obtemNumero(&cheque1));
	printf("Numero cheque (2):%d\n",obtemNumero(&cheque2));
	
	
}
	

