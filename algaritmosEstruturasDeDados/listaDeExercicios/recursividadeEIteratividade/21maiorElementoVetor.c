#include <stdio.h>

int maiorElemento(int vetor[], int tamanho){
    if(vetor != NULL && tamanho >= 0){
        int maiorAnterior = maiorElemento(vetor, tamanho - 1);
        if(vetor[tamanho - 1] > maiorAnterior){
            return vetor[tamanho - 1];
        } else{
            return maiorAnterior;
        }
    }
    if(tamanho == 1 && vetor != NULL){
        return vetor[0];
    }
    
    return 0;
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
