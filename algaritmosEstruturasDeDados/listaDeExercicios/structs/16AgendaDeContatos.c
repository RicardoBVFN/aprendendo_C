#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contatos{
    char nome[50];
    char telefone[15];
    struct Contatos* prox;
}Contato;

typedef struct Agenda{
    Contato* primeiroContato;
    Contato*ultimoContato;
}Agenda;

Contato* addContato(Contato* ultimoContato, char nome[50], char telefone[15]){

    Contato* novo = (Contato*)malloc(sizeof(Contato));
    if(novo == NULL){
        return NULL;
    }

    strcpy(novo->nome, nome);
    strcpy(novo->telefone, telefone);
    novo->prox = NULL;

    return novo;
}

Contato* buscarContato(Contato* contatoAtual, char nomeAlvo[50]){
    if(contatoAtual != NULL){
        if (strcmp(contatoAtual->nome, nomeAlvo) == 0) {
            return contatoAtual;
        }        
        
        return buscarContato(contatoAtual->prox, nomeAlvo);
    }

    return NULL;
}

void freeAgenda(Contato* contatoAtual){
    if(contatoAtual->prox != NULL){
        Contato* temp = contatoAtual;
        contatoAtual = contatoAtual->prox;

        free(temp);
        freeAgenda(contatoAtual);
    } else{
        free(contatoAtual);
    }
}

int main(int argc, char const *argv[]){
    Agenda agenda;
    agenda.primeiroContato = NULL;
    agenda.ultimoContato = NULL;

    int userResponse = 0;

    while (userResponse != 3){
        printf("\no que deseja fazer?\n\n[1] adicionar um contato\n[2] buscar um contato\n[3] sair do programa e deletar a agenda\n\n");
        scanf(" %d", &userResponse);

        switch (userResponse){
            case 1:
                char novoNome[50];
                char novoNumero[15];

                printf("\ndigite um nome para o novo contato: ");
                scanf(" %s", novoNome);
                printf("digite o numero do seu novo contato: ");
                scanf(" %s", novoNumero);

                Contato* temp = addContato(agenda.primeiroContato, novoNome, novoNumero);
                if(temp != NULL){
                    if(agenda.ultimoContato != NULL){
                        agenda.ultimoContato->prox = temp;
                        agenda.ultimoContato = temp;
                    } else{
                        agenda.ultimoContato = temp;
                    }

                } else{
                    printf("\nalgo de errado ocorreu na definição do novo contato, tente novamente");
                }

                if(agenda.primeiroContato == NULL){
                    agenda.primeiroContato = agenda.ultimoContato;
                }
                break;

            case 2:
                Contato* contatoBuscado;
                char nomeAlvo[50];

                printf("\ndigite o nome do contato que você deseja buscar: ");
                scanf(" %s", nomeAlvo);

                contatoBuscado = buscarContato(agenda.primeiroContato, nomeAlvo);

                if(contatoBuscado != NULL){
                    printf("\no nome do contato buscad e: %s", contatoBuscado->nome);
                    printf("\no numero do contato buscado é: %s", contatoBuscado->telefone);
                } else{
                    printf("\nalgo de errado ocorreu na busca pelo contato, tente novamente");
                }
                
                break;

            default:
                if(userResponse != 3){
                    printf("\nsua resposta deve conemplar uma das três opções numéricas, tente novamente");
                }
                break;
        }

        if(userResponse == 3){
            if(agenda.primeiroContato != NULL){
                freeAgenda(agenda.primeiroContato);
            }
        }
    }
    
    return 0;
}
