#include <stdio.h>

int idade, ano, resposta;

void main(){

    printf("digite o ano em que voce nasceu: ");
    scanf("%d", &ano);

    idade = 2024 - ano;

    if(idade == 18){

        printf("\nmeus parabens, voce foi selecionado para servir em cabrobo por um ano, SELVA\n");

    } else{

        if(idade > 18){

            printf("\nvoce ja se apresentou em uma ajunta militar?\n\n[1] sim\n[2] nao\n\n");
            scanf("%d", &resposta);

            if(resposta == 1){

                printf("\ntudo certo soldado, obrigado pelo seu servico\n");

            } else{

                printf("\nok, ja rastreamos o seu cpf e estamos enviando um batalhao até sua residencia, boa sorte");

            }

        } else{

            printf("\nvoce esta livre, por enquanto\n");

        }
        
    }

}