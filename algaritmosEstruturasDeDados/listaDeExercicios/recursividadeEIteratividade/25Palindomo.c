#include <stdio.h>
#include <string.h>

int detectorPalindromo(char palavra[], int comeco, int fim){
    if(comeco >= fim){
        return 1;
    }
    if(palavra[comeco] == palavra[fim - 2]){
        return detectorPalindromo(palavra, comeco + 1, fim - 1);
    } else{
        return 0;
    }
}
int getSize(char palavra[], int iterador){
    if(palavra == NULL){
        return 0;
    }
    if(palavra[iterador ] != '\0'){
        return getSize(palavra, iterador + 1);
    }

    return iterador;
}

int main(int argc, char const *argv[]){
    char temp[100];

    printf("\ndigite uma palavra qualquer: ");
    fgets(temp, sizeof(temp), stdin);

    char palavra[getSize(temp, 0)];
    strcpy(palavra, temp);
    if(detectorPalindromo(palavra, 0, getSize(palavra, 0))){
        printf("\na palavra digitada é um palindromo!");
    } else{
        printf("\na palavra digitada não e um palindormo!");
    }

    return 0;
}
