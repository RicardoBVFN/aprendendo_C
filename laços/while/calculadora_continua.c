#include <stdio.h>

float num1, num2, respostaOperacao;


int menu(){

    int respostaMenu;

    while (1)
    {
        
        printf("\ndigite a sua operacao:\n\n[1] soma\n[2] subtracao\n[3] multiplicacao\n[4] divisao\n[5] encerrar programa\n\n");
        scanf("%d", &respostaMenu);

        if(respostaMenu >= 1 && respostaMenu <= 5){

            break;

        } else{

            printf("\nresposta invalida, tente novamente\n");

        }

    }
    
    return respostaMenu;

}

void switchOperacoes(int respostaMenu){

    switch (respostaMenu)
    {
    case 1:

        respostaOperacao = num1 + num2;
        
        break;

    case 2:

        respostaOperacao = num1 - num2;

        break;

    case 3:

        respostaOperacao = num1 * num2;

        break;

    case 4:

        respostaOperacao = num1 / num2;

        break;
    
    default:
        break;
    }

}

void main(){

    while (1){

        int escolha = menu();

        if (escolha != 5){

            printf("\ndigite o primeiro numero: ");
            scanf("%f", &num1);

            printf("\ndigite o segundo numero: ");
            scanf("%f", &num2);
            
            switchOperacoes(escolha);

            printf("\na resposta e %.1f\n", respostaOperacao);

        } else{

            break;

        }
        
        
    }

    printf("\nobrigado por utilisar a nossa calculadora, volte sempre\n");
    

}