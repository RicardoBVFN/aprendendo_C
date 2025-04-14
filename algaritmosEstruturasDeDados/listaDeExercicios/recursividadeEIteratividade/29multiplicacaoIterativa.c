#include <stdio.h>

int produtoIterativo(int valor, int multiplicador){
    if(multiplicador < 0){
        valor *= -1;
        multiplicador *= -1;
    }

    int resultado = 0;

    for(int i = 1; i <= multiplicador; i++){
        resultado += valor;
    }

    return resultado;
}

int main(int argc, char const *argv[]){
    int valor;
    int multiplicador;

    printf("\ndigite um valor inteiro qualquer: ");
    scanf(" %d", &valor);
    printf("digite quantas vezes voce deseja multiplicar este numero: ");
    scanf(" %d", &multiplicador);

    int resultado = produtoIterativo(valor, multiplicador);
    printf("\no resultado da multiplicacao %d X %d e: %d", valor, multiplicador, resultado);
    return 0;
}