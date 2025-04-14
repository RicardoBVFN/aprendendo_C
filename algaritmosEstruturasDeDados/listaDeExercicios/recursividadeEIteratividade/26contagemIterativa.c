#include <stdio.h>

void contagemRegreciva(int valor){
    for(int i = valor;i > 0; i--){
        printf("%d->", i);
    }
    printf("0");
}

int main(int argc, char const *argv[]){
    int valor;

    printf("\ndigite um valor inteiro positivo qualquer: ");
    scanf(" %d", &valor);
    printf("\n");

    contagemRegreciva(valor);
    return 0;
}