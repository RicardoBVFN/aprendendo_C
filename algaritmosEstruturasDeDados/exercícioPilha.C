#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    char letra;
    struct no* prox;
}no;

typedef struct pilha{
    no* inicio;
    no* fim;
}pilha;

void offer(pilha* p, char valor){
    no* novo = (no*)malloc(sizeof(no));

    if(novo != NULL){
        novo->letra = valor;
        if(p != NULL){
            novo->prox = p->inicio;
        }
        p->inicio = novo;
    }
}

void pop(pilha* p){
    if(p != NULL){
        if(p->inicio != NULL){
            no* temp = p->inicio;
            p->inicio = p->inicio->prox;
            printf("%c", temp->letra);
            free(temp);
        }
    }
}

int main(int argc, char const *argv[]){
    
    char palavra[20];
    pilha stack;

    printf("digite uma palavra: ");
    scanf("%s", &palavra);

   for(int i = 0; palavra[i] != '\0'; i++){
        offer(&stack, palavra[i]);
    }

    while (stack.inicio != NULL){
        pop(&stack);
    }

    return 0;
}
