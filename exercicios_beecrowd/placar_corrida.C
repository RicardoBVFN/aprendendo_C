#include <stdio.h>

typedef struct dados_piloto{
    char nome[100];
    int numero;
    float tempo;
} dados_piloto;

void cadastro_pilotos(dados_piloto *lista, int numero_pilotos){

    for (int i = 0; i < numero_pilotos; i++){
        
        scanf(" %s %d %f", lista[i].nome, &lista[i].numero, &lista[i].tempo);

    }
    

}

void sort(dados_piloto *lista, int nElementos){

    dados_piloto controle;

    for (int i = 0; i < nElementos; i++){
        
        for (int j = 0; j < nElementos; j++){
            
            if(lista[i].tempo < lista[j].tempo){

                controle = lista[i];

                lista[i] = lista[j];
                lista[j] = controle;

            }

        }
        
    }
    
}

void print_placar(dados_piloto *lista, int tamanho_lista){

    printf("Vencedor: %s %d\n", lista[0].nome, lista[0].numero);

    for (int i = 0; i < tamanho_lista; i++){

        printf("%s %d %.2f\n", lista[i].nome, lista[i].numero, lista[i].tempo);

    }
    
}

int main(){

    int tamanho_lista;

    scanf("%d", &tamanho_lista);

    dados_piloto pilotos_cadastrados[tamanho_lista];

    cadastro_pilotos(pilotos_cadastrados, tamanho_lista);
    sort(pilotos_cadastrados, tamanho_lista);
    print_placar(pilotos_cadastrados, tamanho_lista);

    return 0;

}