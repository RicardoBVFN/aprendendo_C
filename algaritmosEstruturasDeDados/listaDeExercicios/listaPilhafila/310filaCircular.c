#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct{
    int dados[MAX];
    int frente, traseira, tamanho;
}Fila;

void inicializarFila(Fila *f){
    f->frente = 0;
    f->traseira = -1;
    f->tamanho = 0;
}

int isEmpty(Fila *f){
    return f->tamanho == 0;
}

int isFull(Fila *f){
    return f->tamanho == MAX;
}

void enqueue(Fila *f, int valor){
    if(isFull(f)){
        printf("Erro: Fila cheia!\n");
        return;
    }
    f->traseira = (f->traseira + 1) % MAX;
    f->dados[f->traseira] = valor;
    f->tamanho++;
}

int dequeue(Fila *f){
    if(isEmpty(f)){
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    int removido = f->dados[f->frente];
    f->frente = (f->frente + 1) % MAX;
    f->tamanho--;
    return removido;
}

int front(Fila *f){
    if(isEmpty(f)){
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    return f->dados[f->frente];
}

void exibirFila(Fila *f){
    if(isEmpty(f)){
        printf("Fila vazia!\n");
        return;
    }

    printf("Elementos da fila: ");
    for(int i = 0; i < f->tamanho; i++){
        int index = (f->frente + i) % MAX;
        printf("%d ", f->dados[index]);
    }
    printf("\n");
}

int main(){
    Fila f;
    inicializarFila(&f);

    enqueue(&f, 10);
    enqueue(&f, 20);
    enqueue(&f, 30);
    enqueue(&f, 40);
    enqueue(&f, 50);
    
    exibirFila(&f);

    printf("Removendo: %d\n", dequeue(&f));
    printf("Removendo: %d\n", dequeue(&f));

    enqueue(&f, 60);
    enqueue(&f, 70);

    exibirFila(&f);

    return 0;
}