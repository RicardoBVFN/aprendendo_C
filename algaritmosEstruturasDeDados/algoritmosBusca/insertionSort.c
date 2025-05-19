#include <stdalign.h>

void insertionSort(int v[], int len){
    int temp;
    for(int i = 1; i < len; i++){
        for(int j = i; j > 0; j--){
            if(v[j] < v[j - 1]){
                temp = v[j];
                v[j] = v[j-1];
                v[j-1] = temp;
            }
        }

        //opcional: visualizar o resultado de cada iteração
        for(int k = 0; k < len; k++){
            printf("%d", v[k]);
        }
        printf("\n\n");
    }
}

int main(int argc, char const *argv[]){
    int vetor[] = {4, 7, 2, 5, 4, 0};
    insertionSort(vetor, 6);
    return 0;
}
