#include <stdio.h>

int contagemRegreciva(int valor){
    if(valor > 0){
        printf("%d->", valor);
        contagemRegreciva(valor - 1);
    }
    if(valor == 0){
        printf("0");
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[]){
    int valor;

    printf("\ndigite um valor inteiro positivo qualquer: ");
    scanf(" %d", &valor);
    printf("\n");

    contagemRegreciva(valor);
    return 0;
}
