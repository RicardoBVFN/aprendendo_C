#include <stdio.h>
#include <stdlib.h>
#define MAX 32

typedef struct{
    int dados[MAX];
    int topo;
}Pilha;

void inicializarPilha(Pilha *p){
    p->topo = -1;
}

int isEmpty(Pilha *p){
    return p->topo == -1;
}

void push(Pilha *p, int valor){
    if(p->topo == MAX - 1){
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->dados[++(p->topo)] = valor;
}

int pop(Pilha *p){
    if(isEmpty(p)){
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return p->dados[(p->topo)--];
}

void converterDecimalParaBinario(int numero){
    Pilha p;
    inicializarPilha(&p);

    if(numero == 0){
        printf("Binário: 0\n");
        return;
    }

    while(numero > 0){
        push(&p, numero % 2);
        numero /= 2;
    }

    printf("Binário: ");
    while(!isEmpty(&p)){
        printf("%d", pop(&p));
    }
    printf("\n");
}

int main(){
    int numero;

    printf("Digite um número decimal: ");
    scanf("%d", &numero);

    converterDecimalParaBinario(numero);
    return 0;
}