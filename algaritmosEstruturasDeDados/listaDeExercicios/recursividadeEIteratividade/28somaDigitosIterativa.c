#include <stdio.h>

int somaAlgarismos(int valor){
    if(valor == 0){
        return 0;
    }
    if(valor < 0){
        valor *= -1;
    }

    int temp = valor;
    int soma = 0;

    while(temp > 0){
        soma = soma + (temp % 10);
        temp = temp / 10;
    }

    return soma;
}

int main(int argc, char const *argv[]){
    int valor;

    printf("\ndigite um valor inteiro qualquer: ");
    scanf(" %d", &valor);

    int soma = somaAlgarismos(valor);

    printf("\na soma dos algarismos do numero digitado e: %d", soma);
    return 0;
}