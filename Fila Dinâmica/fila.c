#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct elem {
    int valor;
    Elem* prox;
};

struct fila {
    int qtd;
    Elem* inicio;
    Elem* final;
};

Fila* criar_fila(){
    Fila* fi = malloc(sizeof(Fila));

    if(fi != NULL){
        fi->qtd = 0;
        fi->inicio = NULL;
        fi->final = NULL;
    }

    return fi;
}

int inserir(Fila* fi, int valor){
    if(fi == NULL){
        return 0;
    }

    Elem* no = malloc(sizeof(Elem));
    no->valor = valor;
    no->prox = NULL;

    if(fi->qtd == 0){
        fi->inicio = no;
        fi->final = no;
    } else {
        fi->final->prox = no;
        fi->final = no;
    }

    fi->qtd++;

    return 1;
}

int remover(Fila* fi){
    if(fi == NULL || fi->qtd == 0){
        return 0;
    }

    Elem* atual = fi->inicio;
    fi->inicio = atual->prox;

    if(fi->inicio == NULL){
        fi->final = NULL;
    }

    free(atual);
    fi->qtd--;

    return 1;
}

int acessar(Fila* fi, int *valor){
    if(fi == NULL || fi->qtd == 0){
        return 0;
    }

    *valor = fi->inicio->valor;

    return 1;
}

void destruir(Fila* fi){
    if(fi == NULL){
        return;
    }

    Elem* aux = fi->inicio;

    for(int i = 0; i < fi->qtd; i++){
        Elem* atual = aux;
        aux = aux->prox;
        free(atual);
    }

    free(fi);
}