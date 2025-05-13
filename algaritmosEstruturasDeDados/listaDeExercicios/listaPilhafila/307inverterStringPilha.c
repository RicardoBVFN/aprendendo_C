#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct{
    char dados[MAX];
    int topo;
}Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int isEmpty(Pilha *p){
    return p->topo == -1;
}

void push(Pilha *p, char c){
    if (p->topo == MAX - 1) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->dados[++(p->topo)] = c;
}

char pop(Pilha *p){
    if (isEmpty(p)) {
        printf("Erro: Pilha vazia!\n");
        return '\0';
    }
    return p->dados[(p->topo)--];
}

void inverterString(char *str){
    Pilha p;
    inicializarPilha(&p);

    for(int i = 0; i < strlen(str); i++){
        push(&p, str[i]);
    }

    for(int i = 0; i < strlen(str); i++){
        str[i] = pop(&p);
    }
}

int main(){
    char str[MAX];

    printf("Digite uma string: ");
    fgets(str, MAX, stdin);
    
    str[strcspn(str, "\n")] = '\0';
    inverterString(str);
    printf("String invertida: %s\n", str);

    return 0;
}