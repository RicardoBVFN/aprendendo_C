#include <stdio.h>

void selectionSort(int v[], int len){
    int min, temp;
    for(int i = 0; i < len - 1; i++){
        min = i;
        for(int j = i + 1; j < len; j++){
            if(v[j] < v[min]){
                min = j;
            }
        }
        if(min != i){
            temp = v[i];
            v[i] = v[min];
            v[min] = temp;

            //opcional: fizualizar o final de cada iteração
            for(int k = 0; k < len; k++){
                    printf("%d", v[k]);
                }
                printf("\n\n");
        }
    }
}

int main(int argc, char const *argv[]){
    int vetor[] = {9, 7, 5, 4, 3, 1};
    selectionSort(vetor, 6);
    return 0;
}
