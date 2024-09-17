#include <stdio.h>
#include <string.h>

typedef struct dados_livro{
    
    char titulo[100];
    char nomeAutor[50];
    char sobrenomeAutor[50];
    int datas[3];

} dados_livro;

void input_dados(char *titulo, char *nome, char *sobrenome, int *dia, int *mes, int *ano){

    scanf(" %[^\n]", titulo);
    scanf(" %s", nome);
    scanf(" %s", sobrenome);
    scanf("%d", dia);
    scanf("%d", mes);
    scanf("%d", ano);

}

void print_dados(dados_livro livro){

    printf("Título: %s\n", livro.titulo);
    printf("Autor: %s %s\n", livro.nomeAutor, livro.sobrenomeAutor);
    printf("Data de Publicação: %02d/%02d/%04d\n", livro.datas[0], livro.datas[1], livro.datas[2]);

}

int main(){

    dados_livro livro;

    input_dados(livro.titulo, livro.nomeAutor, livro.sobrenomeAutor, &livro.datas[0], &livro.datas[1], &livro.datas[2]);
    print_dados(livro);

    return 0;

}