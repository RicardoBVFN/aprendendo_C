#include <stdio.h>

typedef struct Pessoa{
    char nome[50];
    int idade;
    float altura;
}Pessoa;

int main(int argc, char const *argv[]){
    Pessoa pessoa;

    printf("\ndigite o seu nome: ");
    scanf("%s", &pessoa.nome);
    printf("digite a sua idade: ");
    scanf(" %d", &pessoa.idade);
    printf("digite a sua altura (em metros): ");
    scanf(" %f", &pessoa.altura);

    printf("seu nome é %s, você tem %d anos e possui %.2f metros", pessoa.nome, pessoa.idade, pessoa.altura);
    return 0;
}
