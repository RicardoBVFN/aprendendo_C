#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
    int dados[MAX];
    int frente, traseira;
}Fila;

void inicializarFila(Fila *f){
    f->frente = 0;
    f->traseira = -1;
}

int isEmpty(Fila *f){
    return f->frente > f->traseira;
}

void enqueue(Fila *f, int valor){
    if(f->traseira == MAX - 1){
        printf("Erro: Fila cheia!\n");
        return;
    }
    f->dados[++(f->traseira)] = valor;
}

int dequeue(Fila *f){
    if(isEmpty(f)){
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    return f->dados[(f->frente)++];
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
    for(int i = f->frente; i <= f->traseira; i++){
        printf("%d ", f->dados[i]);
    }
    printf("\n");
}

int main(){
    Fila f;
    inicializarFila(&f);

    enqueue(&f, 10);
    enqueue(&f, 20);
    enqueue(&f, 30);

    exibirFila(&f);
    printf("Elemento na frente da fila: %d\n", front(&f));
    printf("Removendo elemento: %d\n", dequeue(&f));
    exibirFila(&f);

    return 0;
}