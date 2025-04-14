#include <stdio.h>

int numeroAlgarismos(int valor, int divisor, int quantidadeAlgarismos){
    if((valor / divisor) > 0){
        return numeroAlgarismos(valor, divisor * 10, quantidadeAlgarismos + 1);
    }else{
        return quantidadeAlgarismos;
    }
}

int main(int argc, char const *argv[]){
    int valor;

    printf("\ndigite um valor inteiro qualquer: ");
    scanf(" %d", &valor);

    printf("\no valor %d possui %d algarismos", valor, numeroAlgarismos(valor, 1, 0));
    return 0;
}
