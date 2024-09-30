#include <stdio.h>
#include <stdlib.h>

void alocacaoDinamica(int **numeros){

    *numeros = (int*) malloc(2 * sizeof(int));

    if(numeros == NULL){

        printf("\nerro ao alocar memória");

    }

}

int main(){

    int *numeros, quantidadeCasos, soma, diferenca;

    scanf("%d", &quantidadeCasos);

    for (int i = 0; i < quantidadeCasos; i++){
    
        alocacaoDinamica(&numeros);

        scanf("%d %d", &numeros[0], &numeros[1]);

        soma = numeros[0] + numeros[1];
        diferenca = numeros[0] - numeros[1]; 

        printf("%d\n", soma);
        printf("%d\n", diferenca);

        free(numeros);

    }
    
}