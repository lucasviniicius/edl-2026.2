#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

#define MAX 4

struct pilha{
    int dados[MAX];
    int topo;
};

Pilha* criar(){
    Pilha* p = malloc(sizeof(struct pilha));

    if(p != NULL){
        p->topo = 0;
    }

    return p;
}

int empilhar(Pilha* p, int valor){
    if(p->topo == MAX){
        return 0;
    }

    p->dados[p->topo] = valor;
    p->topo++;

    return 1;
} 

int acessarTopo(Pilha* p){
    if(p->topo == 0){
        return 0;
    }

    return p->dados[p->topo - 1];
}

int desempilhar(Pilha* p){
    if(p->topo == 0){
        return 0;
    }

    p->topo--;
    return 1;
}

void destruir(Pilha* p){
    if(p != NULL){
        free(p);
    }
}

Pilha* copiaPilha(Pilha* p){
    Pilha* copia = criar();

    if(copia != NULL){
        copia->topo = p->topo;
    }

    for(int i = 0; i < p->topo; i++){
        copia->dados[i] = p->dados[i];
    }

    return copia;
}