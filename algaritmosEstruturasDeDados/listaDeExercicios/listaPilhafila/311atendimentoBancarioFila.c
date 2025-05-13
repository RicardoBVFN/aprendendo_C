#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct{
    char nomes[MAX][50];
    int frente, traseira;
}Fila;

void inicializarFila(Fila *f){
    f->frente = 0;
    f->traseira = -1;
}

int isEmpty(Fila *f){
    return f->frente > f->traseira;
}

int isFull(Fila *f){
    return f->traseira == MAX - 1;
}

void enqueue(Fila *f, char *nome){
    if(isFull(f)){
        printf("Erro: Fila cheia! Não é possível adicionar mais clientes.\n");
        return;
    }
    strcpy(f->nomes[++(f->traseira)], nome);
}

void dequeue(Fila *f){
    if(isEmpty(f)){
        printf("Erro: Fila vazia! Nenhum cliente para atender.\n");
        return;
    }
    printf("Atendendo cliente: %s\n", f->nomes[f->frente]);
    f->frente++;
}

void front(Fila *f){
    if(isEmpty(f)){
        printf("Fila vazia! Nenhum cliente para atender.\n");
        return;
    }
    printf("Próximo cliente a ser atendido: %s\n", f->nomes[f->frente]);
}

void exibirFila(Fila *f){
    if(isEmpty(f)){
        printf("Fila vazia! Nenhum cliente aguardando.\n");
        return;
    }

    printf("Clientes na fila:\n");
    for(int i = f->frente; i <= f->traseira; i++){
        printf("%d. %s\n", i - f->frente + 1, f->nomes[i]);
    }
}

int main(){
    Fila fila;
    inicializarFila(&fila);

    enqueue(&fila, "Carlos");
    enqueue(&fila, "Maria");
    enqueue(&fila, "João");

    exibirFila(&fila);
    front(&fila);

    dequeue(&fila);
    exibirFila(&fila);

    return 0;
}