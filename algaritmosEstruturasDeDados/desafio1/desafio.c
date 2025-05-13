#include <string.h>
#include <stdio.h>

int buscaBinaria(const char *prefixo[], int tamanho, char* vetor[]){
    int inicio = 0, fim = tamanho - 1, meioIndex;
    char meio[50];
    int retorno [tamanho];

    while(inicio <= fim){
        meioIndex = (inicio + fim)/2;
        meio[50] = vetor[meioIndex];

        if(strncmp(meio, prefixo, strlen(prefixo))){
            printf
        }else{

        }
    }
}

int main(int argc, char const *argv[]){
    char *livros[] = {"Teste", "teste 2", "Teste 3"}; 

    return 0;
}
