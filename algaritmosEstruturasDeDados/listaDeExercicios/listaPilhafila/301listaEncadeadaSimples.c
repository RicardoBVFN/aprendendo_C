#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

No* criarNo(int valor){
    No* novoNo = (No*)malloc(sizeof(No));
    if(!novoNo){
        return NULL;
    }
    novoNo->dado = valor;
    novoNo->prox = NULL;
    return novoNo;
}

void inserirInicio(No** cabeca, int valor){
    No* novoNo = criarNo(valor);
    if(novoNo){
        novoNo->prox = *cabeca;
        *cabeca = novoNo;
    }
}

// Inserir no final
void inserirFinal(No** cabeca, int valor){
    No* novoNo = criarNo(valor);
    if(!novoNo){
        return;
    }

    if (*cabeca == NULL) {
        *cabeca = novoNo;
    } else {
        No* temp = *cabeca;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novoNo;
    }
}

void removerElemento(No** cabeca, int valor){
    No* temp = *cabeca, *anterior = NULL;

    if(temp != NULL && temp->dado == valor){
        *cabeca = temp->prox;
        free(temp);
        return;
    }
    while(temp != NULL && temp->dado != valor){
        anterior = temp;
        temp = temp->prox;
    }
    if(temp == NULL){
        return;
    }

    anterior->prox = temp->prox;
    free(temp);
}

void exibirLista(No* cabeca){
    No* temp = cabeca;
    printf("Lista Encadeada: ");
    while (temp != NULL) {
        printf("%d -> ", temp->dado);
        temp = temp->prox;
    }
    printf("NULL\n");
}

void liberarLista(No** cabeca){
    No* temp;
    while (*cabeca != NULL) {
        temp = *cabeca;
        *cabeca = (*cabeca)->prox;
        free(temp);
    }
}

int main(){
    No* lista = NULL;

    inserirInicio(&lista, 10);
    inserirInicio(&lista, 5);
    inserirFinal(&lista, 20);
    inserirFinal(&lista, 30);

    exibirLista(lista);

    removerElemento(&lista, 20);
    exibirLista(lista);

    liberarLista(&lista);
    return 0;
}