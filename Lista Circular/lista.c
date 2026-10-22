#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct elem{
    int valor;
    Elem* prox;
};

struct lista{
    int qtd;
    Elem* final;
};

Lista* criar(){
    Lista* li = malloc(sizeof(Lista));
    
    if(li != NULL){
        li->qtd = 0;
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

    if(li->final == NULL){
        li->final = no;
        no->prox = no;
    } else {
        no->prox = li->final->prox;
        li->final->prox = no;
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

    if(li->final == NULL){
        li->final = no;
        no->prox = no;
    } else {
        no->prox = li->final->prox;
        li->final->prox = no;
    }

    li->final = no;
    li->qtd++;

    return 1;
}

int remover_inicio(Lista* li){
    if(li == NULL || li->final == NULL){
        return 0;
    }

    Elem* aux = li->final->prox;

    if(li->final == aux){
        li->final = NULL;
    } else {
        li->final->prox = aux->prox;
    }

    free(aux);
    li->qtd--;

    return 1;
}

int remover_final(Lista* li){
    if(li == NULL || li->final == NULL){
        return 0;
    }

    Elem* aux = li->final->prox;

    if(li->final == aux){
        li->final = NULL;
    } else {
        Elem* ant = NULL;
        
        while(aux->prox != li->final->prox){
            ant = aux;
            aux = aux->prox;
        }

        ant->prox = li->final->prox;
        li->final = ant;
    }

    free(aux);
    li->qtd--;

    return 1;
}

int acessar_inicio(Lista* li, int *valor){
    if(li == NULL || li->final == NULL){
        return 0;
    }

    *valor = li->final->prox->valor;

    return 1;
}

int acessar_final(Lista* li, int *valor){
    if(li == NULL || li->final == NULL){
        return 0;
    }

    *valor = li->final->valor;

    return 1;
}

void destruir(Lista* li){
    if(li == NULL){
        return;
    }

    if(li->final != NULL){
        Elem* aux = li->final->prox;

        for(int i = 0; i < li->qtd; i++){
            Elem* atual = aux;
            aux = aux->prox;
            free(atual);
        }
    }

    free(li);
}