#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct elemento {
    int dado;
    Elem* prox;
};

struct lista {
    int qtd;
    Elem* inicio;
};

Lista* criar_lista(){
    Lista* li = malloc(sizeof(Lista));
    if(li != NULL){
        li->inicio = NULL;
        li->qtd = 0;
    }

    return li;
}

int insere_inicio(Lista* li, int valor){
    if(li == NULL){
        return 0;
    }

    Elem* no = malloc(sizeof(Elem));

    if(no == NULL){
        return 0;
    }

    no->dado = valor;
    no->prox = li->inicio;
    li->inicio = no;
    li->qtd++;

    return 1;
}

int insere_final(Lista* li, int valor){
    if(li == NULL){
        return 0;
    }

    Elem* no = malloc(sizeof(Elem));

    if(no == NULL){
        return 0;
    }

    no->dado = valor;
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

int remover_inicio(Lista* li){
    if(li == NULL || li->inicio == NULL){
        return 0;
    }

    Elem* aux = li->inicio;
    li->inicio = aux->prox;
    free(aux);
    li->qtd--;

    return 1;
}

int remover_final(Lista* li){
    if(li == NULL || li->inicio == NULL){
        return 0;
    }

    Elem* aux = li->inicio;
    Elem* ant = NULL;

    while(aux->prox != NULL){
        ant = aux;
        aux = aux->prox;
    }

    if(ant == NULL){
        li->inicio = NULL;
    } else {
        ant->prox = NULL;
    }

    free(aux);
    li->qtd--;

    return 1;
}

int acessar_inicio(Lista* li, int *valor){
    if(li == NULL || li->qtd == 0){
        return 0;
    }

    *valor = li->inicio->dado;

    return 1;
}

void destruir(Lista* li){
    if(li != NULL){
        Elem* aux = li->inicio;

        while(aux != NULL){
            Elem* atual = aux;
            aux = aux->prox;
            free(atual);
        }

        free(li);
    }
}

void imprimir_lista(Lista* li){
    // 1. Verifica se a lista existe ou se está vazia
    if(li == NULL || li->inicio == NULL){
        printf("Lista vazia.\n");
        return;
    }

    Elem* aux = li->inicio;

    printf("Lista (%d elementos): ", li->qtd);

    // 2. Percorre todos os nós imprimindo o dado inteiro
    while(aux != NULL){
        printf("[%d] -> ", aux->dado);
        aux = aux->prox; // Avança para o próximo nó
    }
    
    printf("NULL\n");
}