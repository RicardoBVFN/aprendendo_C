#include <stdio.h>

typedef struct{
    char nome[20];
    float fisica;
    float matematica;
    float media;
}aluno;

int main(){

    aluno aluno1, aluno2, aluno3;

    printf("\ndigite o nome do aluno: ");
    scanf("%s", aluno1.nome);
    printf("\ndigite a nota de fisica do aluno: ");
    scanf("%f", &aluno1.fisica);
    printf("\ndigite a nota de matematica do aluno: ");
    scanf("%f", &aluno1.matematica);
    aluno1.media = (aluno1.fisica + aluno1.matematica) / 2;

    printf("\ndigite o nome do aluno: ");
    scanf("%s", aluno2.nome);
    printf("\ndigite a nota de fisica do aluno: ");
    scanf("%f", &aluno2.fisica);
    printf("\ndigite a nota de matematica do aluno: ");
    scanf("%f", &aluno2.matematica);
    aluno2.media = (aluno2.fisica + aluno2.matematica) / 2;

    printf("\ndigite o nome do aluno: ");
    scanf("%s", aluno3.nome);
    printf("\ndigite a nota de fisica do aluno: ");
    scanf("%f", &aluno3.fisica);
    printf("\ndigite a nota de matematica do aluno: ");
    scanf("%f", &aluno3.matematica);
    aluno3.media = (aluno3.fisica + aluno3.matematica) / 2;

    printf("\nas medias dos alunos são %.2f, %.2f, %.2f", aluno1.media, aluno2.media, aluno3.media);
    
}