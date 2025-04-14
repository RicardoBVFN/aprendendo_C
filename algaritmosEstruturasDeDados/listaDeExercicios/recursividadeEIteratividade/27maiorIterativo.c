#include <stdio.h>

int maiorElemento(int vetor[], int tamanho){
    int maior;
    
    for(int i = 0; i < tamanho; i++){
        if(i == 0){
            maior = vetor[0];
        }
        if(vetor[i] > maior){
            maior = vetor[i];
        }
    }

    return maior;
}

int main(int argc, char const *argv[]){
    int tamanho;

    printf("\ndigite quantos elementos voce deseja cadastrar: ");
    scanf(" %d", &tamanho);

    int vetor[tamanho];

    for(int i = 0;i<tamanho; i++){
        printf("\ndigite o valor do elemento %d: ", i + 1);
        scanf(" %d", &vetor[i]);
    }

    int maior = maiorElemento(vetor, tamanho);

    printf("\no maior elemento do vetor cadastrado é: %d", maior);
    return 0;
}
