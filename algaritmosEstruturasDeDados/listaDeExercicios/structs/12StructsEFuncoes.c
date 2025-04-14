#include <stdio.h>

typedef struct Produto{
    char nomeProduto[50];
    int codigo;
    float preco;
}Produto;

void printarProduto(Produto produto){
    printf("\no nome do produto é: %s", produto.nomeProduto);
    printf("\no codigo do produto é: %d", produto.codigo);
    printf("\no preco do produto é: R$%.2f", produto.preco);
}

int main(int argc, char const *argv[]){
    Produto produto;

    printf("\ndigite um nome para o produto: ");
    scanf("%s", &produto.nomeProduto);
    printf("digite o código para esse produto: ");
    scanf(" %d", &produto.codigo);
    printf("digite o preço desse produto (em Reais): ");
    scanf(" %f", &produto.preco);

    printarProduto(produto);
    return 0;
}
