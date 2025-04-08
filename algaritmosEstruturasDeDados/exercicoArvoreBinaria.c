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

        printf("\nelemento adicionado com sucesso!");
        return novo;
    }

    return NULL;
}

int contains(no* noAtual, int valorAlvo){
    if(noAtual != NULL){
        if(valorAlvo > noAtual->valor){
            return contains(noAtual->direita, valorAlvo);
        }
        if(valorAlvo < noAtual->valor){
            return contains(noAtual->esquerda, valorAlvo);
        }

        printf("\nvalor encontardo!");
        return 1;
    }

    printf("\no valor buscado não existe na arvore binária");
    return 0;
}

no* descobrirOMenor(no* noAtual){
    if(noAtual != NULL){
        if(noAtual->esquerda == NULL){
            return noAtual;
        }
        if(noAtual->esquerda->esquerda != NULL){
            no* retorno = descobrirOMenor(noAtual->esquerda);
            return retorno;
        }

        no* temp = noAtual->esquerda;
        noAtual->esquerda = NULL;
        return temp;
    }

    return NULL;
}

no* remover(no* noAtual, int valorAlvo){
    if(noAtual != NULL){
        if(valorAlvo == noAtual->valor){
            if(noAtual->direita != NULL && noAtual->esquerda != NULL){
                no* temp = noAtual;
                no* menorNo = descobrirOMenor(temp->direita);
                
                menorNo->esquerda = temp->esquerda;
                if(temp->direita == menorNo){
                    menorNo->direita = NULL;
                } else{
                    menorNo->direita = temp->direita;
                }

                free(temp);
                printf("\nelemento liberado com sucesso!");
                return menorNo;
            } 
            if(noAtual->direita == NULL && noAtual->esquerda == NULL){
                free(noAtual);
                printf("\nelemento liberado com sucesso!");
                return NULL;
            }
            if(noAtual->direita != NULL && noAtual->esquerda == NULL){
                no* temp = noAtual->direita;
                free(noAtual);
                printf("\nelemento liberado com sucesso!");
                return temp;
            }
            if(noAtual->direita == NULL && noAtual->esquerda != NULL){
                no* temp = noAtual->esquerda;
                free(noAtual);
                printf("\nelemento liberado com sucesso!");
                return temp;
            }
        }
        
        if(valorAlvo > noAtual->valor){
            noAtual->direita =  remover(noAtual->direita, valorAlvo);
            return noAtual;
        }
        if(valorAlvo < noAtual->valor){
            noAtual->esquerda = remover(noAtual->esquerda, valorAlvo);
            return noAtual;
        }       
    }

    printf("\no valor buscado não existe na arvore binária");
}

void emOrdem(no* noAtual){
    if(noAtual != NULL){
        emOrdem(noAtual->esquerda);
        printf("%d ", noAtual->valor);
        emOrdem(noAtual->direita);
    }
}

void liberarArvore(no* noAtual){
    if(noAtual != NULL){
        liberarArvore(noAtual->esquerda);
        liberarArvore(noAtual->direita);
        free(noAtual);
        printf("\nelemento liberado com sucesso!");
    }
}


int main(int argc, char const *argv[]){
    arvore arvore;
    arvore.raiz = NULL;
    char resposta;
    int valorAlvo;

    while(1){
        printf("\nqual acao deseja realizar?\n\n[1] inserir um novo nó\n[2] remover um nó\n[3]buscar um nó\n[4]exibir em oredem\n[5] sair do programa\n\n");
        scanf(" %c", &resposta);

        switch (resposta){
            case '1':
                int valor;
                printf("\ndigite o valor que será incerido na arvore: ");
                scanf("%d", &valor);
                arvore.raiz = insert(arvore.raiz, valor);
                break;
            case '2':
                printf("\ndigite o valor do nó o qual voce deseja remover: ");
                scanf("%d", &valorAlvo);

                arvore.raiz = remover(arvore.raiz, valorAlvo);
                break;
            
            case '3':
                printf("\ndigite o valor que voce deseja buscar: ");
                scanf("%d", &valorAlvo);

                contains(arvore.raiz, valorAlvo);
                break;

            case '4':
                printf("\n");
                emOrdem(arvore.raiz);
                break;

            default:
                if(resposta != '5'){
                    printf("\nresposta inválida, tente novamente");
                }
                break;
        }

        if(resposta == '5'){
            break;
        }
    }

    liberarArvore(arvore.raiz);
    printf("\nobrigado por usar este programa, até a próxima!");
    return 0;
}
