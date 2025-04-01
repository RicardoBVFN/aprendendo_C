#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct No{
    int valor;
    struct No* esquerda;
    struct No* direita;
}No;
typedef struct Arvore{
    No* raiz;
}Arvore;

No* insert(No* raiz, int newValor){
    if(raiz == NULL){
        No* novo = (No*)malloc(sizeof(No));

        if(novo != NULL){
            novo->valor = newValor;
            novo->esquerda = NULL;
            novo->direita = NULL;
            printf("\nelemento adicionado com sucesso!");
            return novo;
        } else{
            printf("\nalgo de errado ocoreu na alocação dessa memória");
        }
    }
    else if(newValor < raiz->valor){
        raiz->esquerda = insert(raiz->esquerda, newValor);
    }
    else if(newValor > raiz->valor){
        raiz->direita = insert(raiz->direita, newValor);
    }

    return raiz;
}

void preOrdem(No* raiz){
    if(raiz != NULL){
        printf("%d ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}
void emOrdem(No* raiz){
    if(raiz != NULL){
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        emOrdem(raiz->direita);
    }
}
void posOrdem(No* raiz){
    if(raiz != NULL){
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}


int main(void){
    Arvore arvore;
    arvore.raiz = NULL;

    arvore.raiz = insert(arvore.raiz, 40);
    arvore.raiz = insert(arvore.raiz, 5);
    arvore.raiz = insert(arvore.raiz, 10);
    arvore.raiz = insert(arvore.raiz, 30);
    arvore.raiz = insert(arvore.raiz, 15);
    arvore.raiz = insert(arvore.raiz, 20);
    arvore.raiz = insert(arvore.raiz, 55);
    arvore.raiz = insert(arvore.raiz, 50);
    arvore.raiz = insert(arvore.raiz, 45);
    arvore.raiz = insert(arvore.raiz, 60);

    emOrdem(arvore.raiz);
    printf("\n");
    preOrdem(arvore.raiz);
    printf("\n");
    posOrdem(arvore.raiz);
}
