#include <stdio.h>

int salario, valor, periodo, resposta;
float prestacao;

void main(){

    printf("\ndigite o seu salario: R$");
    scanf("%d", &salario);

    printf("\ndigite o valor do seu financiamento: R$");
    scanf("%d", &valor);

    printf("\ndigite o periodo do financiamento (em meses): ");
    scanf("%d", &periodo);

    prestacao = valor / periodo;

    if(prestacao > (salario * 0.3)){

        printf("\nlamento, mas seu financiamento foi recusado\n");

    } else{

        printf("ok, seu financiamento de R$%d será pago em %d prestacoes de R$%.2f, voce concorda com esses termos?\n\n[1] sim\n[2] nao\n\n", valor, periodo, prestacao);
        scanf("%d", &resposta);

        if(resposta == 1){

            printf("\nparabens, voce acaba de ter seu financiamento aprovado\n");

        } else{

            printf("\nque pena, esperamos poder fazer negocios com voce um dia\n");

        }

    }

}
