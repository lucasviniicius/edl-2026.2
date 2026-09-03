#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

int main(){
    Fila* f = criar();

    enfileirar(f, 30);
    enfileirar(f, 40);
    enfileirar(f, 50);
    enfileirar(f, 50);

    int vetor[4];

    for(int i = 0; i < 4; i++){
        vetor[i] = acessar(f);
        desinfileirar(f);
    }

    for(int i = 3; i >= 0; i--){
        enfileirar(f, vetor[i]);
    }

    printf("Início: %d\n", acessar(f));

    desinfileirar(f);

    printf("Início: %d\n", acessar(f));
    
    if(enfileirar(f, 80)){
        printf("Enfileirou\n");
    } else {
        printf("Não enfileirou\n");
    }

    printf("Início: %d\n", acessar(f));

    return 0;
}