#include <stdio.h>

typedef struct circulo{
        
    float raio;
    float area;

} circulo;

int main(){
    
    circulo solido1;

    scanf("%f", &solido1.raio);

    solido1.area = 3.14159 * (solido1.raio * solido1.raio);

    printf("A=%.4f\n", solido1.area);

    return 0;

}

