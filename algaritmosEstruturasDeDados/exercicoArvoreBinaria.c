#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no* esquerda;
    struct no* direita;
}no;

typedef struct arvore{
    no* raiz;
}arvore;

no* insert(no* noAtual, int newValor){
    if(noAtual != NULL){
        if(newValor > noAtual->valor){
            noAtual->direita = insert(noAtual->direita, newValor);
        }
        if(newValor < noAtual->valor){
            noAtual->esquerda = insert(noAtual->esquerda, newValor);
        }

        return noAtual;
    }

    no* novo = (no*)malloc(sizeof(no));
    if(novo != NULL){
        novo->valor = newValor;
        novo->direita = NULL;
        novo->esquerda = NULL;

        return novo;
    }
}

void contains(no* noAtual, int valorAlvo){
    if(noAtual != NULL){
        if(valorAlvo > noAtual->valor){
            contains(noAtual->direita, valorAlvo);
        }
        if(valorAlvo < noAtual->valor){
            contains(noAtual->esquerda, valorAlvo);
        }

        printf("\nvalor encontardo!");
    }

    printf("\no valor buscado não existe na arvore binária");
}


int main(int argc, char const *argv[]){
    arvore arvore;
    arvore.raiz = NULL;
    char resposta;

    while(1){
        printf("\nqual acao deseja realizar?\n\n[1] inserir um novo nó\n[2] remover um nó\n[3]buscar um novo nó\n[4]exibir em oredem\n\n");
        scanf("%c", &resposta);

        switch (resposta){
        case '1':
            int valor;
            printf("\ndigite o valor que será incerido na arvore: ");
            scanf("%d", &valor);
            arvore.raiz = insert(arvore.raiz, valor);
            break;
        case '2':
            int valorAlvo;
            printf("\ndigite o valor do nó o qual voce deseja remover: ");
            scanf("%d", &valorAlvo);

            
        default:
            break;
        }

    }
    

    return 0;
}
