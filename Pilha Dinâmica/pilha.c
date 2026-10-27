#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct elem {
    int valor;
    Elem* prox;
};

struct pilha {
    int qtd;
    Elem* topo;
};

Pilha* criar_pilha(){
    Pilha* pi = malloc(sizeof(Pilha));

    if(pi != NULL){
        pi->qtd = 0;
        pi->topo = NULL;
    }

    return pi;
}

int inserir(Pilha* pi, int valor){
    if(pi == NULL){
        return 0;
    }

    Elem* no = malloc(sizeof(Elem));
    no->valor = valor;

    if(pi->topo == NULL){
        pi->topo = no;
        no->prox = NULL;
    } else {
        no->prox = pi->topo;
        pi->topo = no;
    }

    pi->qtd++;

    return 1;
}

int remover(Pilha* pi){
    if(pi == NULL || pi->qtd == 0){
        return 0;
    }

    Elem* atual = pi->topo;
    pi->topo = atual->prox;
    free(atual);
    pi->qtd--;

    return 1;
}

int acessar(Pilha* pi, int *valor){
    if(pi == NULL || pi->qtd == 0){
        return 0;
    }

    *valor = pi->topo->valor;

    return 1;
}

void destruir(Pilha* pi){
    if(pi == NULL){
        return;
    }

    Elem* aux = pi->topo;
    for(int i = 0; i < pi->qtd; i++){
        Elem* atual = aux;
        aux = aux->prox;
        free(atual);
    }

    free(pi);
}