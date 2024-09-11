#include <stdio.h>

void geradorDeMatriz(int **matrizVazia, int ordemMatriz){

    int comparador;

    for (int i = 0; i < ordemMatriz; i++){
        
        for (int j = 0; j < ordemMatriz; j++){
            
            if (i > j){

                comparador = ordemMatriz - i;

                if (j < comparador){
                    
                    matrizVazia[i][j] = j + 1;

                } else{

                    matrizVazia[i][j] = comparador;

                }
                

            } else{

                if (j > i){

                    comparador = ordemMatriz - j;

                    if (i < comparador){
                        
                        matrizVazia[i][j] = i + 1;

                    } else{

                        matrizVazia[i][j] = comparador;

                    }

                } else{

                    if (j >= (ordemMatriz / 2)){

                        matrizVazia[i][j] = ordemMatriz - j;

                    } else{

                        matrizVazia[i][j] = j + 1;

                    }

                }
                

            }

        }
        

    }
    
}

void printMatriz(int **matrizPrint, int ordemMatriz){

   for (int i = 0; i < ordemMatriz; i++) {
        for (int j = 0; j < ordemMatriz; j++) {
            if (j == 0) {
                printf("%3d", matrizPrint[i][j]);
            } else {
                printf(" %3d", matrizPrint[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
    
}

int main(){

    int input;

    while (1){

        scanf("%d", &input);

        if (input != 0){

            int matriz[input][input], *matrizPtr[input];

            for (int i = 0; i < input; i++) {

                matrizPtr[i] = matriz[i];

            }

            geradorDeMatriz(matrizPtr, input);

            printMatriz(matrizPtr, input);


        } else{

            break;

        }

    }

    return 0;

}