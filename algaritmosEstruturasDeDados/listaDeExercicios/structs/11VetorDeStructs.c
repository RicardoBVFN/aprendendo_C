#include <stdio.h>

typedef struct Aluno{
    char nome[50];
    int matricula;
    float nota;
}Aluno;

int main(int argc, char const *argv[]){
    Aluno alunos[5];
    float media = 0;

    for(int i = 0; i < 5; i++){
        printf("\ndigite o nome do aluno %d: ", i + 1);
        scanf("%s", &alunos[1].nome);
        printf("digite a matricula do aluno %d: ", i + 1);
        scanf(" %d", &alunos[i].matricula);
        printf("digite a nota do aluno %d: ", i + 1);
        scanf(" %f", &alunos[i].nota);

        media += alunos[i].nota;
    }

    media /= 5;

    printf("\na media dos alunos cadastrados é de %.2f", media);    
    return 0;
}
