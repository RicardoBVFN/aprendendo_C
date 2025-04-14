#include <stdio.h>

typedef struct Livro{
    char titulo[50];
    char autor[50];
    int anoPublicacao;
}Livro;

void PrintLivrosAno(Livro livros[], int anoDefinido, int tamanhoColecao){
    for(int i; i< tamanhoColecao; i++){
        if(livros[i].anoPublicacao == anoDefinido){
            printf("\nnome do livro: %s", livros[i].titulo);
            printf("\nautor do livro: %s", livros[i].autor);
            printf("\nano de publicacao: %d\n", livros[i].anoPublicacao);
        }
    }
}

int main(int argc, char const *argv[]){
    int tamanhoColecao;
    int anoDefinido;

    printf("\nquantos livros voce deseja cadastrar? ");
    scanf(" %d", &tamanhoColecao);

    Livro livros[tamanhoColecao];

    for(int i = 0; i < tamanhoColecao; i++){
        printf("\ndigite o titulo do livro %d: ", i + 1);
        scanf(" %s", &livros[i].titulo);
        printf("digite o nome do autor do livro %d: ", i + 1);
        scanf(" %s", &livros[i].autor);
        printf("digite o ano de publicacao do livro %d: ", i + 1);
        scanf(" %d", &livros[i].anoPublicacao);
    }

    printf("\ndigite o ano de bulicacao dos livros que voce deseja buscar: ");
    scanf(" %d", &anoDefinido);

    PrintLivrosAno(livros, anoDefinido, tamanhoColecao);
    return 0;
}
