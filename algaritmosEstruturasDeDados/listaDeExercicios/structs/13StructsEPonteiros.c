#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Carro{
    char modelo[50];
    int ano;
    float preco;
}Carro;

int main(int argc, char const *argv[]){
    Carro* carro = (Carro*)malloc(sizeof(Carro));
    if(carro == NULL){
        printf("\nfalha ao tentar alocar a memoria, tente novamente");
        return 0;
    }

    strcpy(carro->modelo, "chevrolet chevete");
    carro->ano = 1990;
    carro->preco = 25000.50;

    printf("\nnome do carro: %s", carro->modelo);
    printf("\nano do carro: %d", carro->ano);
    printf("\npreco do carro: R$%.2f", carro->preco);

    free(carro);    
    return 0;
}
