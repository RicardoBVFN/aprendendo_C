#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No* prox;
}No;

void inverterLista(No** cabeca){
    No* anterior = NULL;
    No* atual = *cabeca;
    No* proximo = NULL;

    while(atual != NULL){
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    *cabeca = anterior;
}

No* criarNo(int valor){
    No* novoNo = (No*)malloc(sizeof(No));
    if (!novoNo) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    novoNo->dado = valor;
    novoNo->prox = NULL;
    return novoNo;
}

void inserirInicio(No** cabeca, int valor){
    No* novoNo = criarNo(valor);
    if (novoNo) {
        novoNo->prox = *cabeca;
        *cabeca = novoNo;
    }
}

void exibirLista(No* cabeca){
    No* temp = cabeca;
    printf("Lista: ");
    while(temp != NULL){
        printf("%d -> ", temp->dado);
        temp = temp->prox;
    }
    printf("NULL\n");
}

void liberarLista(No** cabeca){
    No* temp;
    while(*cabeca != NULL){
        temp = *cabeca;
        *cabeca = (*cabeca)->prox;
        free(temp);
    }
}

int main() {
    No* lista = NULL;

    inserirInicio(&lista, 10);
    inserirInicio(&lista, 20);
    inserirInicio(&lista, 30);
    inserirInicio(&lista, 40);

    printf("Lista original:\n");
    exibirLista(lista);

    inverterLista(&lista);

    printf("Lista invertida:\n");
    exibirLista(lista);

    liberarLista(&lista);
    return 0;
}