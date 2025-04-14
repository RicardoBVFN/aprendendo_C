#include <stdio.h>

typedef struct Paciente{
    char nome[50];
    int idade;
    char diagnostico[100];
}Paciente;

void printAcima60(Paciente pacientes[], int tamanho){
    if(pacientes != NULL){
        for(int i = 0;i < tamanho; i++){
            if(pacientes[i].idade >= 60){
                printf("\n\nnome do paciente: %s", pacientes[1].nome);
                printf("\nidade do paciente: %d", pacientes[i].idade);
                printf("\ndiagnostico do paciente: %s", pacientes[i].diagnostico);
            }
        }
    }
}

int main(int argc, char const *argv[]){
    int tamanho;
    
    printf("\nquantos pacientes deseja cadastrar? ");
    scanf(" %d", &tamanho);

    Paciente pacientes[tamanho];

    for(int i = 0;i<tamanho; i++){
        printf("\ndigite o nome do paciente %d: ", i + 1);
        scanf(" %s", &pacientes[i].nome);
        printf("digite a idade do paciente %d: ", i + 1);
        scanf(" %d", &pacientes[i].idade);
        printf("digite o diagnostico do paciente %d: ", i + 1);
        scanf(" %s", &pacientes[i].diagnostico);
    }

    printf("\npacientes com mais de 60 anos:\n");
    printAcima60(pacientes, tamanho);
    return 0;
}
