#include <stdio.h>

typedef struct Conta{
    char nomeTitular[50];
    int idConta;
    float saldo;
}Conta;

void deposito(Conta* conta, float deposito){
    if(conta != NULL){
        conta->saldo += deposito;
        printf("\ndeposito realizado com sucesso!\n");
    }
}
int saque(Conta*conta, float saque){
    if(conta != NULL){
        if(saque <= conta->saldo){
            conta->saldo -= saque;
            return 1;
        }
        return 0;
    }
    return 0;
}
float getDados(Conta* conta){
    if(conta != NULL){
        printf("\nnome do titular da conta: %s", conta->nomeTitular);
        printf("\nid da conta: %d", conta->idConta);
        printf("\nsaldo atual: R$%.2f\n", conta->saldo);
    }
}

int main(int argc, char const *argv[]){
    Conta conta;
    int userResponse = 0;
    float novoDeposito;
    float novoSaque;
    
    printf("\ndigite o seu nome: ");
    scanf(" %s", conta.nomeTitular);
    conta.idConta = 10;
    conta.saldo = 10000.00;
    
    printf("\nbem vindo ao nosso sistema bancario %s!\n", conta.nomeTitular);
    while(userResponse != 4){
        int saqueVerificador = 0;

        printf("\no que voce deseja fazer?\n\n[1] realizar um deposito\n[2] realizar um saque\n[3] consultar os dados da conta\n[4] sair do programa\n\n");
        scanf(" %d", &userResponse);

        switch (userResponse){

        case 1:
            printf("\ndigite o valor do deposito que voce deseja realizar: R$");
            scanf(" %f", &novoDeposito);

            deposito(&conta, novoDeposito);
            break;

        case 2:
            while(saqueVerificador != 1){
                printf("\ndigite o valor do saque que voce deseja realizar: R$");
                scanf(" %f", &novoSaque);

                if(saque(&conta, novoSaque)){
                    printf("\nsaque realizado com sucesso!\n");
                    saqueVerificador = 1;
                } else{
                    printf("\no valor digitado e maior que seu saldo atual ou parametro nulo\n");
                }
            }
            break;

        case 3:
            getDados(&conta);
            break;
        
        default:
            if(userResponse != 4){
                printf("\nsua resposta deve contemplar aguma das opcoes numericas descritas acima, tente novamente\n");
            }
            break;
        }
    }
    return 0;
}

