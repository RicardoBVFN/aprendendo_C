#include <stdio.h>

int nTermos;

void fibonacci(int numberTerms){

    int x, y, z;

    x = 0;
    y = 1;

    switch (numberTerms)
    {
    case 1:
        
        printf("%d\n", x);

        break;

    case 2:

        printf("%d %d\n", x, y);

        break;
    
    default:

        printf("%d %d", x, y);

        for (int i = 2; i < numberTerms; i++){

            z = x + y;

            if(i == (numberTerms - 1)){

               printf(" %d\n", z); 

            } else{

                printf(" %d", z);

            }
            
            x = y;
            y = z;

        }
        
        break;
    }

}

int main(){
    
    scanf("%d", &nTermos);

    fibonacci(nTermos);

    return 0;
}
