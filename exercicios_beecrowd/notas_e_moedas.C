#include <stdio.h>

double valorEntrada;

float valoresParaImpressao[] = {100, 50, 20, 10, 5, 2, 1, 0.5, 0.25, 0.1, 0.05, 0.01};

int notasMoedas [] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1}, 
contadorNotasMoedas[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 

void divisorNotasMoedas(double valorDeEntrada){

    int num = valorDeEntrada * 100;
    int verificador;

    for (int i = 0; i < 12; i++){

        contadorNotasMoedas[i] = num / notasMoedas[i];
        verificador = (num % notasMoedas[i]);
        num -= contadorNotasMoedas[i] * notasMoedas[i];

        if(verificador == 0){

            break;

        } else{

            continue;

        }
    
    }

}

void impresaoResultados(){

    printf("NOTAS:\n");

    for (int i = 0; i < 6; i++){

        printf("%d nota(s) de R$ %.2f\n", contadorNotasMoedas[i], valoresParaImpressao[i]);

    }

    printf("MOEDAS:\n");

    for (int i = 6; i < 12; i++){

       printf("%d moeda(s) de R$ %.2f\n", contadorNotasMoedas[i], valoresParaImpressao[i]); 

    }

}

int main(){

    scanf("%lf", &valorEntrada);

    divisorNotasMoedas(valorEntrada);
    impresaoResultados();

    return 0;

}
