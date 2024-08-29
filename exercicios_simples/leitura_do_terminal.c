#include <stdio.h>

int main(void){

    char nome[10], sobrenome[15];

    printf("digite o seu nome: ");
    scanf("%s", &nome);

    printf("\ndigite o seu sobrenome: ");
    scanf("%s", &sobrenome);

    printf("prazer em te conhecer %s %s\n", nome, sobrenome);
    
}