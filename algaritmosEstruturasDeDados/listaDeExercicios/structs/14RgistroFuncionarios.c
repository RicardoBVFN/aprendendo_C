#include <stdio.h>

typedef struct Funcionario{
    char nome[50];
    char cargo[30];
    float salario;
}Funcionario;

int main(int argc, char const *argv[]){
    int n;

    printf("\nquantos usuarios voce deseja cadastrar? ");
    scanf("%d", &n);
    Funcionario funcionarios[n];

    for(int i = 0; i < n; i++){
        printf("\ndigite o nome do funcionario %d: ", i + 1);
        scanf(" %s", &funcionarios[i].nome);
        printf("digite o cargo do funcionario %d: ", i + 1);
        scanf(" %s", &funcionarios[i].cargo);
        printf("digite o salário do funcionario %d (em reais): ", i + 1);
        scanf(" %f", &funcionarios[i].salario);
    }

    printf("\nlista de funcionarios cadastrados:\n");
    for (int i = 0; i < n; i++){
        printf("\nnome do funcionario: %s\ncargo do funcionario: %s\nsalario do funcionario: R$%.2f\n", funcionarios[i].nome, funcionarios[i].cargo, funcionarios[i].salario);
    }

    return 0;
}
