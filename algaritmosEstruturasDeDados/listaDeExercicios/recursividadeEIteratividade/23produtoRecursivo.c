#include <stdio.h>

int produtoRecursivo(int valor, int multiplicador){
    if(multiplicador > 0){
        return valor + produtoRecursivo(valor, multiplicador - 1);
    }
    if(multiplicador == 0){
        return 0;
    }
    if(multiplicador < 0){
        printf("teste");
        multiplicador = multiplicador * -1;
        valor = valor * -1;
        return valor + produtoRecursivo(valor, multiplicador - 1);
    }
}

int main(int argc, char const *argv[]){
    int valor;
    int multiplicador;

    printf("\ndigite um valor inteiro qualquer: ");
    scanf(" %d", &valor);
    printf("digite quantas vezes voce deseja multiplicar este numero: ");
    scanf(" %d", &multiplicador);

    int resultado = produtoRecursivo(valor, multiplicador);
    printf("\no resultado da multiplicacao %d X %d e: %d", valor, multiplicador, resultado);
    return 0;
}
