#include <stdio.h>
#include <stdlib.h>
#include "venda.h"
#include "fila.h"

void registraVenda(Fila* f, int codigoProduto, double valor, int qtd){
    if(f == NULL){
        printf("Fila inválida\n");
        return;
    }

    Venda* v = criarVenda(codigoProduto, valor, qtd);
    int insereVenda = inserirVenda(v, f);

    if(insereVenda){
        printf("Venda registrada\n");
    } else {
        printf("Venda não registrada\n");
    }
}

void consultaProximaVenda(Fila* f){
    if(f == NULL){
        printf("Fila inválida\n");
        return;
    }

    Venda* v = consultarVendaFila(f);
    imprimirVenda(v);
}

void processaVenda(Fila* f){
    int codigoProduto;
    double valor;
    int qtd;
    double valorVenda = 0;

    if(f == NULL){
        printf("Fila inválida\n");
        return;
    }
    
    Venda* v = consultarVendaFila(f);

    if(v == NULL){
        printf("Venda inválida\n");
        return;
    }

    consultaVenda(v, &codigoProduto, &valor, &qtd);

    valorVenda = valor * qtd;

    printf("====Venda Processada====\n");
    printf("Valor total: %.2lf\n", valorVenda);
    printf("Quantidade: %d", qtd);

    removerVenda(f);
    liberarVenda(v);
}

int main(){
    Fila* f = criarFila();

    registraVenda(f, 1, 12.0, 2);
    registraVenda(f, 2, 24.0, 2);

    consultaProximaVenda(f);

    processaVenda(f);

    return 0;
}