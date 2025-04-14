#include <stdio.h>
#include <stdlib.h>

typedef struct Retangulo{
    float base;
    float altura;
}Retangulo;

float calcularArea(float base, float altura){
    return base * altura;
}
float calcularPerimetro(float base, float altura){
    return (2 * base) + (2 * altura);
}

int main(int argc, char const *argv[]){
    int userResponse = 0;
    while(userResponse != 2){
        printf("\no que deseja fazer?\n\n[1] cadastrar um novo retangulo\n[2] sair do programa\n\n");
        scanf(" %d", &userResponse);

        switch (userResponse){
        case 1:
            Retangulo* retangulo = (Retangulo*)malloc(sizeof(Retangulo));
            if(retangulo == NULL){
                printf("\nalgo de errado ocorreu ao definir o novo retangulo, tente novamente");
                break;
            }

            printf("\ndigite o valor da base do novo retangulo em centimetros: ");
            scanf(" %f", &retangulo->base);
            printf("digite o valor da altura do novo retangulo em centimetros: ");
            scanf(" %f", &retangulo->altura);

            int retanguloResponse = 0;
            while(retanguloResponse != 3){
                printf("\no que deseja fazer com o seu retangulo?\n\n[1] descobrir a sua area\n[2] descobrir seu perimetro\n[3] deletar este retangulo\n\n");
                scanf(" %d", &retanguloResponse);

                switch (retanguloResponse){
                    case 1:
                        printf("\na area do seu retangulo é de %.2fcm^2\n", calcularArea(retangulo->base, retangulo->altura));
                        break;

                    case 2:
                        printf("\no perimetro do seu retangulo é de %.2fcm\n", calcularPerimetro(retangulo->base, retangulo->altura));
                        break;
                    
                    default:
                        if(retanguloResponse != 3){
                            printf("\nsua resposta deve contemplar uma das opcoes numericas descritas acima, tente novamente");
                        }
                        break;
                }
            }

            free(retangulo);
            break;

        default:
            if(userResponse != 2){
                printf("\nsua resposta deve contemplar uma das opcoes numericas descritas acima, tente novamente");
            }
            break;
        }
    }
    
    return 0;
}
