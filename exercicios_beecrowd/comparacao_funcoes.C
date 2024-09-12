#include <math.h>
#include <stdio.h>


int funcaoRafael(int x, int y){

    int resultado;

    x = pow(x, 2);
    y = pow(y, 2);

    resultado = (9 * x) + y;

    return resultado;

}

int funcaoBeto(int x, int y){

    int resultado;

    x = pow(x, 2);
    y = pow(y, 2);

    resultado = (2 * x) + (25 * y);

    return resultado;

}

int funcaoCarlos(int x, int y){

    int resultado;

    y = pow(y, 3);

    resultado = (x * -100) + y;

    return resultado;

}

int main(){

    int numeroCasos, Rafael, Beto, Carlos, x, y;

    scanf("%d", &numeroCasos);

    for (int i = 0; i < numeroCasos; i++){
        
        scanf("%d %d", &x, &y);

        Rafael = funcaoRafael(x, y);
        Beto = funcaoBeto(x, y);
        Carlos = funcaoCarlos(x, y);

        if ((Rafael > Beto) && (Rafael > Carlos)){

            printf("Rafael ganhou\n");

        } else{

            if ((Beto > Rafael) && (Beto > Carlos)){

                printf("Beto ganhou\n");

            } else{

                if ((Carlos > Rafael) && (Carlos > Beto)){

                    printf("Carlos ganhou\n");

                }

            }

        }

    }

    return 0;
    
}