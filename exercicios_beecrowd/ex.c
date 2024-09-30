#include <stdio.h>
#include <stdlib.h>


int main(){

int *numeros, soma;

numeros = malloc(2 * sizeof(int));

if(numeros == NULL){

    printf("erro, falha ao alocar memória");

}

scanf("%d", &numeros[0]);
scanf("%d", &numeros[1]);

soma = numeros[0] + numeros[1];

printf("%d", soma);

free(numeros);

}