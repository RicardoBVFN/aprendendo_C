#include <stdio.h>

typedef struct dados_pacientes{
    
    char nome[50];
    int idade;
    float altura;

} dados_pacientes;

void cadastro(dados_pacientes *paciente){

    scanf(" %s", paciente->nome);
    scanf("%d", &paciente->idade);
    scanf("%f", &paciente->altura);

}

void print_dados(dados_pacientes paciente){

    printf("Nome: %s\n", paciente.nome);
    printf("Idade: %d\n", paciente.idade);
    printf("Altura: %.2f\n", paciente.altura);

}

int main(){

dados_pacientes paciente;

cadastro(&paciente);
print_dados(paciente);

}