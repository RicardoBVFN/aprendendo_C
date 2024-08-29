#include <stdio.h>

int velocidade;

void main(){

    printf("\ndigite a sua velocidade em km/h: ");
    scanf("%d", &velocidade);

    if ((velocidade > 80 && velocidade <120) || velocidade < 40){

        printf("\nvoce levou uma multa de R$293,47 alem de 7 pontos na sua CNH\n");

    } else {

        if(velocidade >= 120){

            printf("\nvoce levou uma multa de R$293,47 , 7 pontos na sua CNH e esta com a mesma sendo cacada\n");

        } else{

            printf("\nok, prossiga com cuidado\n");

        }

    }
    

}
