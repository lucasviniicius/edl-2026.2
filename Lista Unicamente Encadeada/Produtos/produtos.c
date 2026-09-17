#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"

struct elemento {
    struct produto dados;
    Elem* prox;
};

struct lista {
    int qtd;
    Elem* inicio;
};

Lista* criar_lista(){
    Lista* li = malloc(sizeof(Lista));

    if(li != NULL){
        li->qtd = 0;
        li->inicio = NULL;
    }

    return li;
}

int insere_inicio(Lista* li, struct produto p){
    if(li == NULL){
        return 0;
    }

    Elem* no = malloc(sizeof(Elem));

    if(no == NULL){
        return 0;
    }

    no->dados = p;
    no->prox = li->inicio;
    li->inicio = no;
    li->qtd++;

    return 1;
}

int insere_final(Lista* li, struct produto p){
    if(li == NULL){
        return 0;
    }

    Elem* no = malloc(sizeof(Elem));

    if(no == NULL){
        return 0;
    }

    no->dados = p;
    no->prox = NULL;

    if(li->inicio == NULL){
        li->inicio = no;
        li->qtd++;

        return 1;
    }

    Elem* aux = li->inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = no;
    li->qtd++;

    return 1;
}

int acessar_inicio(Lista* li, struct produto* p){
    if(li == NULL){
        return 0;
    }

    if(li->inicio == NULL){
        return 0;
    }

    Elem* no = li->inicio;
    *p = no->dados;

    return 1;
}

int remover_inicio(Lista* li){
    if(li == NULL){
        return 0;
    }

    if(li->inicio == NULL){
        return 0;
    }

    Elem* no = li->inicio;
    li->inicio = no->prox;
    free(no);
    li->qtd--;

    return 1;
}

int remover_final(Lista* li){
    if(li == NULL){
        return 0;
    }

    if(li->inicio == NULL){
        return 0;
    }

    Elem* no = li->inicio;
    Elem* ant = NULL;

    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(ant == NULL){
        li->inicio = NULL;
    } else {
        ant->prox = NULL;
    }

    free(no);
    li->qtd--;

    return 1;
}

void imprimir_lista(Lista* li){
    Elem* no = li->inicio;
    printf("Quantidade de Produto: %d\n", li->qtd);

    while(no != NULL){
        printf(" -> [Codigo: %d | Preco: R$ %.2f]\n", no->dados.codigo, no->dados.preco);
        no = no->prox; 
    }

    printf(" -> [NULL]\n");
}

void destruir_lista(Lista* li){
    if(li != NULL){
        Elem* no = li->inicio;

        while(no != NULL){
            Elem* atual = no;
            no = no->prox;
            free(atual);
        }

        free(li);
    }
}