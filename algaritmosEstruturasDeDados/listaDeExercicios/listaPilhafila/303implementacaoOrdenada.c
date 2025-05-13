#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No* prox;
}No;

No* criarNo(int valor){
    No* novoNo = (No*)malloc(sizeof(No));
    if(!novoNo){
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    novoNo->dado = valor;
    novoNo->prox = NULL;
    return novoNo;
}

void inserirOrdenado(No** cabeca, int valor){
    No* novoNo = criarNo(valor);
    if (!novoNo) return;

    if(*cabeca == NULL || (*cabeca)->dado > valor){
        novoNo->prox = *cabeca;
        *cabeca = novoNo;
        return;
    }

    No* temp = *cabeca;
    while(temp->prox != NULL && temp->prox->dado < valor){
        temp = temp->prox;
    }

    novoNo->prox = temp->prox;
    temp->prox = novoNo;
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

    if(temp == NULL) {
        return;
    }

    anterior->prox = temp->prox;
    free(temp);
}

void exibirLista(No* cabeca){
    No* temp = cabeca;
    printf("Lista Encadeada Ordenada: ");
    while(temp != NULL){
        printf("%d -> ", temp->dado);
        temp = temp->prox;
    }
    printf("NULL\n");
}

int contarElementos(No* cabeca){
    int contador = 0;
    No* temp = cabeca;

    while(temp != NULL){
        contador++;
        temp = temp->prox;
    }

    return contador;
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

    inserirOrdenado(&lista, 20);
    inserirOrdenado(&lista, 5);
    inserirOrdenado(&lista, 30);
    inserirOrdenado(&lista, 10);

    exibirLista(lista);
    printf("Quantidade de elementos na lista: %d\n", contarElementos(lista));

    removerElemento(&lista, 10);
    exibirLista(lista);
    printf("Quantidade de elementos após remoção: %d\n", contarElementos(lista));

    liberarLista(&lista);
    return 0;
}