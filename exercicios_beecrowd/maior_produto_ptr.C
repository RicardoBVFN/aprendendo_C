#include <stdio.h>
#include <stdlib.h>

int maiorProduto(int listaNumeros[], int tamanhoLista){

    int maiorProduto = 0;

    for (int i = 0; i < tamanhoLista; i++){
        
        for (int j = 1; j < tamanhoLista; j++){

           if (i == 0 && j == 1){
            
            maiorProduto = listaNumeros[i] * listaNumeros[i + j];

           } else{

            if ((i + j) != tamanhoLista){

                if (maiorProduto < (listaNumeros[i] * listaNumeros[i + j])){

                    maiorProduto = (listaNumeros[i] * listaNumeros[i + j]);

                } else{

                    continue;

                }

            } else{

                break;

            }

           }
            
        }
        
    }

    return maiorProduto;

}

int main(){

    int numeros[3], maiorProd;

    scanf("%d %d %d", &numeros[0], &numeros[1], &numeros[2]);

    maiorProd = maiorProduto(numeros, 3);

    printf("%d\n", maiorProd);

    return 0;
    
}