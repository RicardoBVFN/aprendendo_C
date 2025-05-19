#include <stdio.h>

void bubbleSort(int v[], int len){
    int mudancas, temp;
    for(int i = len -1; i > 0; i--){
        mudancas = 0;
        for(int j = 0; j < i; j++){
            if(v[j] > v[j + 1]){
                temp = v[j + 1];
                v[j + 1] = v[j];
                v[j] = temp;
                mudancas++;

                //opcional: vizualizar cada movimentação
                for(int k = 0; k < len; k++){
                    printf("%d", v[k]);
                }
                printf("\n\n");
            }
        }
        if(mudancas == 0){
            break;
        }
    }
}

int main(int argc, char const *argv[]){
    int vetor[] = {9, 7, 5, 4,  3, 1};
    int* vetorOrdenado;
    bubbleSort(vetor, 6);
    return 0;
}
