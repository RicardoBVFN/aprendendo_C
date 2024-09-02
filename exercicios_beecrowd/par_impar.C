#include <stdio.h>

int numeroCasos;
char *saidas[] = {"EVEN", "ODD", "POSITIVE", "NEGATIVE", "NULL"};


void verificador(int nCasos, int *vetorN){

    int coeficiente, number;


    for (int i = 0; i < nCasos; i++){
    

        number = vetorN[i];

        coeficiente = number % -2; 

        switch (coeficiente){
        case 0:

            if(number < 0){

                printf("%s %s\n", saidas[0], saidas[3]);

            } else{

                if (number == 0){
                
                    printf("%s\n", saidas[4]);

                } else{
                
                    printf("%s %s\n", saidas[0], saidas[2]);

                }

            }

            break;

        case 1:

            printf("%s %s\n", saidas[1], saidas[2]);

            break;

        case -1:
        
            printf("%s %s\n", saidas[1], saidas[3]);
            break;

        default:
            break;
        }

    }
    
}

int main(){

    scanf("%d", &numeroCasos);

    int vetNumeros[numeroCasos];

    for (int i = 0; i < numeroCasos; i++){
        
        scanf("%d", &vetNumeros[i]);

    }
    
    verificador(numeroCasos, vetNumeros);

    return 0;

}
