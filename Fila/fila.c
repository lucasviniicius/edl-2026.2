#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

#define MAX 4

struct fila{
    int dados[MAX];
    int inicio;
    int fim;
    int qtd;
};

Fila* criar(){
    Fila* f = malloc(sizeof(struct fila));

    if(f != NULL){
        f->inicio = 0;
        f->fim = 0;
        f->qtd = 0;
    }

    return f;
}

int enfileirar(Fila* f, int valor){
    if(f->qtd == MAX){
        return 0;
    }
    
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;
    f->qtd++;

    return 1;
}

int desinfileirar(Fila* f){
    if(f->qtd == 0){
        return 0;
    }

    f->inicio = (f->inicio + 1) % MAX;
    f->qtd--;

    return 1;
}

int acessar(Fila* f){
    if(f->qtd == 0){
        return 0;
    }

    return f->dados[f->inicio];
}

void destruir(Fila* f){
    if(f != NULL){
        free(f);
    }
}