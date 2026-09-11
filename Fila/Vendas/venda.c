#include <stdio.h>
#include <stdlib.h>
#include "venda.h"

struct venda{
    int codigoProduto;
    double valor;
    int qtd;
};

Venda* criarVenda(int codigoProduto, double valor, int qtd){
    Venda* v = malloc(sizeof(struct venda));

    if(v != NULL){
        v->codigoProduto = codigoProduto;
        v->valor = valor;
        v->qtd = qtd;
    }

    return v;
}

void consultaVenda(Venda* v, int *codigoProduto, double *valor, int *qtd){
    if(v != NULL){
        *codigoProduto = v->codigoProduto;
        *valor = v->valor;
        *qtd = v->qtd;
    }
}

void imprimirVenda(Venda* v){
    if(v != NULL){
        printf("====Venda====\n");
        printf("Código do produto: %d\n", v->codigoProduto);
        printf("Valor: %lf\n", v->valor);
        printf("Quantidade: %d\n", v->qtd);
    }
}

void liberarVenda(Venda* v){
    if(v != NULL){
        free(v);
    }
}