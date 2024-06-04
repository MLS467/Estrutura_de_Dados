#include <stdio.h>
// Programa desenvolvido por Maisson em 31/08/2023
typedef struct {
    int numConta;
    float saldo;
} Conta;

float obtemSaldo(Conta *x);
void depositaNaConta(Conta *x, float valorDeposito);
void retiraDaConta(Conta *x, float valorRetirado);
void criaConta(Conta *x, int numConta);

main() {
    Conta contaCorrente, contaPoupanca;
    int numContaCorrente, numContaPoupanca, opcao;
    float valorContaCorrente, valorContaPoupanca, faltaNaCorrente;

    printf("Criar conta Corrente, insira o numero da conta\n");
    scanf("%d", &numContaCorrente);
    criaConta(&contaCorrente, numContaCorrente);

    printf("Criar conta Poupanca, insira o numero da conta\n");
    scanf("%d", &numContaPoupanca);
    criaConta(&contaPoupanca, numContaPoupanca);

    do {
    	
        printf("\n");
        printf("Insira a operacao desejada:\n");
        puts("1. Deposito conta corrente 2. Deposito poupanca 3.Retirada conta corrente 4.Retirada poupanca 5.Fim");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1: {
            	system("cls");
                // deposita na conta corrente
                printf("\nValor para depositar Conta Corrente: ");
                scanf("%f", &valorContaCorrente);
                depositaNaConta(&contaCorrente, valorContaCorrente);
                printf("\t--->Conta Corrente : %.2f\n", contaCorrente.saldo);
                printf("\t--->Conta Poupanca: %.2f\n", contaPoupanca.saldo);
		printf("\t--->Saldo Total: %.2f\n",contaCorrente.saldo + contaPoupanca.saldo );
                break;
            }
            case 2: {
            	system("cls");
                // deposita na conta poupanca
                printf("\nValor para depositar Conta Poupanca: ");
                scanf("%f", &valorContaPoupanca);
                depositaNaConta(&contaPoupanca, valorContaPoupanca);
                printf("\t--->Conta Corrente : %.2f\n", contaCorrente.saldo);
                printf("\t--->Conta Poupanca: %.2f\n", contaPoupanca.saldo);
                printf("\t--->Saldo Total: %.2f\n",contaCorrente.saldo + contaPoupanca.saldo );

                break;
            }
            case 3: {
            	system("cls");
                // ver possibilidade de retirar corrente
                // função retirar
                
                printf("\nValor para retirar da Conta Corrente: ");
                scanf("%f", &valorContaCorrente);

                if (valorContaCorrente <= obtemSaldo(&contaCorrente)) {
                    retiraDaConta(&contaCorrente, valorContaCorrente);
                    printf("\t--->Conta Corrente : %.2f\n", contaCorrente.saldo);
                    printf("\t--->Conta Poupanca: %.2f\n", contaPoupanca.saldo);
                    printf("\t--->Saldo Total: %.2f\n",contaCorrente.saldo + contaPoupanca.saldo );
                } else if (valorContaCorrente <= (obtemSaldo(&contaCorrente) + obtemSaldo(&contaPoupanca))) {
                    faltaNaCorrente = valorContaCorrente - obtemSaldo(&contaCorrente);
                    retiraDaConta(&contaCorrente, obtemSaldo(&contaCorrente));
                    retiraDaConta(&contaPoupanca, faltaNaCorrente);
                    printf("\t--->Conta Corrente : %.2f\n", contaCorrente.saldo);
                    printf("\t--->Conta Poupanca: %.2f\n", contaPoupanca.saldo);
                    printf("\t--->Saldo Total: %.2f\n",contaCorrente.saldo + contaPoupanca.saldo );
                } else {
                    printf("\t--->Saldo insuficiente\n");
                }

                break;
            }
            case 4: {
            	system("cls");
                // ver possibilidade de retirar poupanca
                // função retirar

                printf("\nValor para retirar da Conta Poupanca: ");
                scanf("%f", &valorContaPoupanca);

                if (contaPoupanca.saldo < valorContaPoupanca) {
                    printf("\t--->Saldo insuficiente\n");
                } else {
                    retiraDaConta(&contaPoupanca, valorContaPoupanca);
                    printf("\t--->Conta Corrente : %.2f\n", contaCorrente.saldo);
                    printf("\t--->Conta Poupanca: %.2f\n", contaPoupanca.saldo);
                }

                break;
            }
            case 5: {
                break;
            }
            default: {
                printf("\t--->Operacao invalida!\n");
                break;
            }
        }

    } while (opcao > 0 && opcao < 5);

    
}

void depositaNaConta(Conta *x, float valorDeposito) {
    x->saldo += valorDeposito;
}

void retiraDaConta(Conta *x, float valorRetirado) {
    x->saldo -= valorRetirado;
}

void criaConta(Conta *x, int numConta) {
    x->numConta = numConta;
    x->saldo = 0;
}

float obtemSaldo(Conta *x) {
    return x->saldo;
}

