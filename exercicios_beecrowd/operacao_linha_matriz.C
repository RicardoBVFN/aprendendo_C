#include <stdio.h>
#include <string.h>

float matriz[12][12];
int contLinha, contColuna, linhaOp;
char letraOp;

void operacoes(int operacao, int linha){

    float somatorio, media;

    somatorio = matriz[linha][0];

    for (int i = 1; i < 12; i++){
        
        somatorio += matriz[linha][i];
    
    }

    if(operacao == 0){
        
        printf("%.1f\n", somatorio);

    } else{

        media = somatorio / 12;
        printf("%.1f\n", media);

    }

}

int coletaString(char *op){

    int verificacao1, verificacao2;

    while(1){

        scanf(" %c", op);

        strupr(op);

        verificacao1 = strcmp(op, "S");
        verificacao2 = strcmp(op, "M");

        if(verificacao1 == 0 || verificacao2 == 0){

            break;

        } else{

            continue;

        }

    }

    return verificacao1;

}

int main(){

    int returnOp;

    scanf("%d", &linhaOp);

    returnOp = coletaString(&letraOp);

    for (int i = 0; i < 12; i++){
        
        for (int j = 0; j < 12; j++){
            
            scanf("%f", &matriz[i][j]);

        }
        
    }

    operacoes(returnOp, linhaOp);
    
}
