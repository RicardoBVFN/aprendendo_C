#include <stdio.h>

float x, y, respostaOperacao;

int menu(){

    int resposta;

    printf("\nqual operacao vc deseja fazer?\n[1] soma\n[2] subtracao\n[3] multiplicacao\n[4] divisão\n\n");

    scanf("%d", &resposta);

    return resposta;
}

void switchOperacoes(int respostaMenu){

    switch (respostaMenu)
    {
    case 1:
        
        respostaOperacao = x + y;
        break;

    case 2:

        respostaOperacao = x - y;
        break;

    case 3:

        respostaOperacao = x * y;
        break;
    
    default:

        respostaOperacao = x / y;
        break;
    }

}

void main(){

    printf("digite o primeiro valor: ");
    scanf("%f", &x);

    printf("\ndigite o segundo valor: ");
    scanf("%f", &y);

    int menur = menu();

    switchOperacoes(menur);

    printf("\nsua resposta e %.2f", respostaOperacao);

}
