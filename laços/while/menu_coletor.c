#include <stdio.h>

int resposta;

void main(){

    while (1){

        printf("\ndigite o seu sexo\n\n[1] masculino\n[2] feminino\n\n");
        scanf("%d", &resposta);

        if(resposta == 1 || resposta == 2){

            break;

        } else{

            printf("\nresposta invalida, tente novamente\n");

        }

    }
    

}
