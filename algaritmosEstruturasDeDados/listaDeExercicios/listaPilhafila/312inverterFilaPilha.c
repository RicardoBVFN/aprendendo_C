#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
    int dados[MAX];
    int frente, traseira;
}Fila;

typedef struct{
    int dados[MAX];
    int topo;
}Pilha;

void inicializarFila(Fila *f){
    f->frente = 0;
    f->traseira = -1;
}

void inicializarPilha(Pilha *p){
    p->topo = -1;
}

int isEmptyFila(Fila *f){
    return f->frente > f->traseira;
}

int isEmptyPilha(Pilha *p){
    return p->topo == -1;
}

void enqueue(Fila *f, int valor){
    if(f->traseira == MAX - 1){
        printf("Erro: Fila cheia!\n");
        return;
    }
    f->dados[++(f->traseira)] = valor;
}

int dequeue(Fila *f){
    if(isEmptyFila(f)){
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    return f->dados[(f->frente)++];
}

void push(Pilha *p, int valor){
    if(p->topo == MAX - 1){
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->dados[++(p->topo)] = valor;
}

int pop(Pilha *p){
    if(isEmptyPilha(p)){
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return p->dados[(p->topo)--];
}

void inverterFila(Fila *f){
    Pilha p;
    inicializarPilha(&p);

    while(!isEmptyFila(f)){
        push(&p, dequeue(f));
    }

    while(!isEmptyPilha(&p)){
        enqueue(f, pop(&p));
    }
}

void exibirFila(Fila *f){
    if(isEmptyFila(f)){
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
    Fila fila;
    inicializarFila(&fila);

    enqueue(&fila, 10);
    enqueue(&fila, 20);
    enqueue(&fila, 30);
    enqueue(&fila, 40);
    enqueue(&fila, 50);

    printf("Fila original:\n");
    exibirFila(&fila);

    inverterFila(&fila);

    printf("Fila invertida:\n");
    exibirFila(&fila);

    return 0;
}