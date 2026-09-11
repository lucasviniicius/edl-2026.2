#include <stdio.h>
#include <stdlib.h>
#include "venda.h"
#include "fila.h"

#define MAX 5

struct fila{
    Venda* vendas[MAX];
    int inicio;
    int fim;
    int qtd;
};

Fila* criarFila(){
    Fila* f = malloc(sizeof(struct fila));

    if(f != NULL){
        f->inicio = 0;
        f->fim = 0;
        f->qtd = 0;
    }

    return f;
}

int estaVazia(Fila* f){
    if(f->qtd == 0) return 1;

    return 0;
}

int estaCheia(Fila* f){
    if(f->qtd == MAX) return 1;

    return 0;
}

int qtdVendas(Fila* f){
    if(f == NULL) return -1;

    return f->qtd;
}

int inserirVenda(Venda* v, Fila* f){
    if(v == NULL || f == NULL || estaCheia(f)){
        return 0;
    }

    f->vendas[f->fim] = v;
    f->fim = (f->fim + 1) % MAX;
    f->qtd++;

    return 1;
}

int removerVenda(Fila* f){
    if(f == NULL || estaVazia(f)){
        return 0;
    }

    f->inicio = (f->inicio + 1) % MAX;
    f->qtd--;

    return 1;
}

Venda* consultarVendaFila(Fila* f){
    if(f != NULL && !estaVazia(f)){
        return f->vendas[f->inicio];
    }
}


void liberarFila(Fila* f){
    if(f != NULL){
        free(f);
    }
}