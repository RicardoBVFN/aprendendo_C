#include <stdio.h>
#include <stdlib.h>
#define MAX 100

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
    if (p->topo == MAX - 1) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->dados[++(p->topo)] = valor;
}

int pop(Pilha *p){
    if (isEmpty(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return p->dados[(p->topo)--];
}

int top(Pilha *p){
    if (isEmpty(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return p->dados[p->topo];
}

void exibirPilha(Pilha *p){
    if(isEmpty(p)){
        printf("Pilha vazia!\n");
        return;
    }
    
    printf("Elementos da pilha: ");
    for(int i = 0; i <= p->topo; i++){
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}

int estaBalanceado(const char *str) {
    int pilha[MAX];
    int topo = -1;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(') {
            pilha[++topo] = '(';
        } else if (str[i] == ')') {
            if (topo == -1) {
                return 0;
            }
            topo--;
        }
    }

    return topo == -1;
}


int main(){
    Pilha p;
    inicializarPilha(&p);

    push(&p, 10);
    push(&p, 20);
    push(&p, 30);
    
    exibirPilha(&p);
    
    printf("Topo da pilha: %d\n", top(&p));

    printf("Removendo elemento do topo: %d\n", pop(&p));

    exibirPilha(&p);

    char entrada[MAX];

    printf("Digite uma string contendo apenas '(' e ')': ");
    scanf("%s", entrada);

    if (estaBalanceado(entrada)) {
        printf("Válido\n");
    } else {
        printf("Inválido\n");
    }

    return 0;
}