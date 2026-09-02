#include <stdio.h>
#include <stdlib.h>
#include "livro.h"

#define MAX 10

struct pilha {
    struct livro dados[MAX];
    int qtd;
};

Pilha* criaPilha(){
    Pilha* p = malloc(sizeof(struct pilha));

    if(p != NULL){
        p->qtd = 0;
    }

    return p;
}

void liberaPilha(Pilha* p){
    if(p != NULL){
        free(p);
    }
}

int tamanhoPilha(Pilha* p){
    if(p == NULL){
        return -1;
    }

    return p->qtd;
}

int pilhaCheia(Pilha* p){
    if(p == NULL){
        return -1;
    }

    if(p->qtd == MAX){
        return 1;
    }

    return 0;
}

int pilhaVazia(Pilha* p){
    if(p == NULL){
        return -1;
    }

    if(p->qtd == 0){
        return 1;
    }

    return 0;
}

int inserePilha(Pilha* p, struct livro li){
    if(p == NULL){
        return 0;
    }

    if(p->qtd == MAX){
        return 0;
    }

    p->dados[p->qtd] = li;
    p->qtd++;

    return 1;
}

int removePilha(Pilha* p){
    if(p == NULL){
        return 0;
    }

    if(p->qtd == 0){
        return 0;
    }

    p->qtd--;

    return 1;
}

int acessaTopoPilha(Pilha* p, struct livro *li){
    if(p == NULL || p->qtd == 0){
        return -1;
    }

    *li = p->dados[p->qtd - 1];

    return 1;
}