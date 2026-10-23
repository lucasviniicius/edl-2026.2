#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct elem {
    int valor;
    Elem* prox;
    Elem* ant;
};

struct lista {
    int qtd;
    Elem* inicio;
    Elem* final;
};

Lista* criar_lista(){
    Lista* li = malloc(sizeof(Lista));
    if(li != NULL){
        li->qtd = 0;
        li->inicio = NULL;
        li->final = NULL;
    }

    return li;
}

int inserir_inicio(Lista* li, int valor){
    if(li == NULL){
        return 0;
    }

    Elem* no = malloc(sizeof(Elem));
    no->valor = valor;

    if(li->qtd == 0){
        li->inicio = no;
        li->final = no;
        no->prox = NULL;
        no->ant = NULL;
    } else {
        no->ant = NULL;
        no->prox = li->inicio;
        li->inicio->ant = no;
        li->inicio = no;
    }

    li->qtd++;

    return 1;
}

int inserir_final(Lista* li, int valor){
    if(li == NULL){
        return 0;
    }

    Elem* no = malloc(sizeof(Elem));
    no->valor = valor;

    if(li->qtd == 0){
        no->ant = NULL;
        no->prox = NULL;
        li->inicio = no;
        li->final = no;
    } else {
        no->prox = NULL;
        no->ant = li->final;
        li->final->prox = no;
        li->final = no;
    }

    li->qtd++;

    return 1;
}

int remover_inicio(Lista* li){
    if(li == NULL || li->qtd == 0){
        return 0;
    }

    
    Elem* aux = li->inicio;
    li->inicio = aux->prox;

    if(li->inicio != NULL){
        li->inicio->ant = NULL;
    } else {
        li->final = NULL;
    }

    free(aux);
    li->qtd--;

    return 1;
}

int remover_final(Lista* li){
    if(li == NULL || li->qtd == 0){
        return 0;
    }

    Elem* aux = li->final;
    li->final = aux->ant;

    if(li->final != NULL){
        li->final->prox = NULL;
    } else {
        li->inicio = NULL;
    }

    free(aux);
    li->qtd--;

    return 1;
}

int acessar_inicio(Lista* li, int *valor){
    if(li == NULL || li->qtd == 0){
        return 0;
    }

    *valor = li->inicio->valor;

    return 1;
}

int acessar_final(Lista* li, int *valor){
    if(li == NULL || li->qtd == 0){
        return 0;
    }

    *valor = li->final->valor;

    return 1;
}

void destruir(Lista* li){
    if(li == NULL){
        return;
    }

    if(li->qtd > 0){
        Elem* aux = li->inicio;
        for(int i = 0; i < li->qtd; i++){
            Elem* atual = aux;
            aux = aux->prox;
            free(atual);
        }
    }

    free(li);
}