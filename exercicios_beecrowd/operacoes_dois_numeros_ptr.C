#include <stdio.h>

void operacoes(int numeros[], float respostas[]){

    for(int i = 1; i < 5; i++){

        switch (i){
        case 1:
            
            respostas[0] = numeros[0] + numeros[1];
            break;

        case 2:

            respostas[1] = numeros[0] - numeros[1];
            break;

        case 3:

            respostas[2] = numeros[0] * numeros[1];
            break;

        case 4:

            if(numeros[1] != 0){

                respostas[3] = numeros[0] / numeros[1];

            }else{
                
                respostas[3] = 0;

            }
        
        default:
            break;
        }

    }

}

int main(){

    int listaNumeros[2];
    float listaRespostas[4];

    scanf("%d %d", &listaNumeros[0], &listaNumeros[1]);

    operacoes(listaNumeros, listaRespostas);

    printf("%.0f\n%.0f\n%.0f\n", listaRespostas[0], listaRespostas[1], listaRespostas[2]);

    if(listaRespostas[3] != 0){

        printf("%.0f\n", listaRespostas[3]);

    }else{

       printf("Divisão por zero\n");

    }

    return 0;
    
}