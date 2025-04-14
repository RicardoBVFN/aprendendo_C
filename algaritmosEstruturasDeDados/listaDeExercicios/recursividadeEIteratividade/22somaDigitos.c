#include <stdio.h>

int somaAlgarismos(int valor){
    if (valor == 0) {
        return 0;
    }
    if(valor < 0){
        valor *= -1;
    }
    return (valor % 10) + somaAlgarismos(valor / 10);    
}

int main(int argc, char const *argv[]){
    int valor;

    printf("\ndigite um valor inteiro qualquer:");
    scanf(" %d", &valor);

    int soma = somaAlgarismos(valor);

    printf("\na soma dos algarismos do numero digitado e: %d", soma);
    return 0;
}
