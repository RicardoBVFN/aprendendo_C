#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

typedef struct lista{
    int valor;
    struct lista* prox;
}lista;

// typedef struct exercícioFila
// {
//     lista* head;                     macete de início e fim 
//     lista* end;                      define uma struct só para o início e para o fim
// };


lista* offer(int valor, lista* head){
    lista* novo = (lista*)malloc(sizeof(lista));

    if(novo != NULL){
        novo->valor = valor;
        novo->prox = head;

        return novo;
    }

    return NULL;
}

lista* offerEnd(int valor, lista* end){
    lista* novo = (lista*)malloc(sizeof(lista));

    if(novo != NULL){
        novo->valor = valor;
        novo->prox = NULL;

        if(end != NULL){
            end->prox = novo;
        }

        return novo;
    }

    return NULL;
    
}

int removeLista(int targetValue, lista** head){
    lista* current = *head;
    lista* previous = NULL;
    
    while(current != NULL){
        if(targetValue == current->valor){
            if(previous == NULL){
                *head = current->prox;
            }
            else{
                previous->prox = current->prox;
            }

            free(current);
            return 1;
        }

        previous = current;
        current = current->prox;
    }

    return 0;
}

int pop(lista** head){

    if(*head == NULL){
        return 0;
    }

    lista* current = *head;
    *head = current->prox;
    free(current);

    return 1;
}

int popEnd(lista** head, lista** end){

    if(*head == NULL || *end == NULL){
        return 0;
    }

    lista* current = *head;

    while(current->prox != *end){
        current = current->prox;
    }

    free(*end);
    current->prox = NULL;
    *end = current;

    return 1;

}

lista* get(int targetValue, lista* selector){
    while(selector != NULL){
        if(selector->valor == targetValue){
            return selector;
        } else{
            selector = selector->prox;
        }
    }
    return NULL;
}

int main(int argc, char const *argv[]){
    lista* head = NULL;
    lista* end = NULL;
    lista* selector = NULL;
    int removeu;

    head = offer(10, head);
    end = get(10, head);

    end = offerEnd(20, end);
    if(get(20, head) != NULL){
        printf("sucesso");
    }

    return 0;
}
