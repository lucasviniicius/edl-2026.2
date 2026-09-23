#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "musica.h"

struct elem {
    Musica* musica;
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

int inserir_inicio(Lista* li, Musica* musica){
    if(li == NULL){
        return 0;
    }

    Elem* no = malloc(sizeof(Elem));
    no->musica = musica;
    no->prox = li->inicio;

    li->inicio = no;
    li->qtd++;

    return 1;
}

int inserir_final(Lista* li, Musica* musica){
    if(li == NULL){
        return 0;
    }

    Elem* no = malloc(sizeof(Elem));
    no->musica = musica;
    no->prox = NULL;

    if(li->qtd == 0){
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

int inserir_posicao(Lista* li, int pos, Musica* musica){
    if(li == NULL || pos < 0 || pos > li->qtd){
        return 0;
    }

    if(pos == 0){
        return inserir_inicio(li, musica);
    }

    if(pos == li->qtd){
        return inserir_final(li, musica);
    }

    Elem* no = malloc(sizeof(Elem));
    Elem* ant = li->inicio;

    no->musica = musica;

    for(int i = 0; i < pos - 1; i++){
        ant = ant->prox;
    }

    no->prox = ant->prox;
    ant->prox = no;
    li->qtd++;

    return 1;
}

int remover_inicio(Lista* li){
    if(li == NULL){
        return 0;
    }

    if(li->qtd == 0){
        return 0;
    }

    Elem* aux = li->inicio;
    li->inicio = aux->prox;
    destruir_musica(aux->musica);
    free(aux);
    li->qtd--;

    return 1;
}

int remover_final(Lista* li){
    if(li == NULL){
        return 0;
    }

    if(li->qtd == 0){
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

    destruir_musica(aux->musica);
    free(aux);
    li->qtd--;

    return 1;
}

int remover_posicao(Lista* li, int pos){
    if(li == NULL || pos < 0 || pos >= li->qtd){
        return 0;
    }

    if(li->qtd == 0){
        return 0;
    }

    if(pos == 0){
        return remover_inicio(li);
    }

    if(pos == li->qtd - 1){
        return remover_final(li);
    }

    Elem* ant = li->inicio;
    for(int i = 0; i < pos - 1; i++){
        ant = ant->prox;
    }

    Elem* aux = ant->prox;
    ant->prox = aux->prox;
    destruir_musica(aux->musica);
    free(aux);
    li->qtd--;

    return 1;
}

Musica* consultar_inicio(Lista* li){
    if(li == NULL){
        return NULL;
    }

    if(li->qtd == 0){
        return NULL;
    }

    return li->inicio->musica;
}

Musica* consulta_posicao(Lista* li, int pos){
    if(li == NULL || pos < 0 || pos >= li->qtd){
        return NULL;
    }

    if(pos == 0){
        Musica* m = consultar_inicio(li);
        return m;
    }

    Elem* aux = li->inicio;
    for(int i = 0; i < pos; i++){
        aux = aux->prox;
    }

    return aux->musica;
}

int consultar_quantidade(Lista* li){
    if(li == NULL){
        return -1;
    }

    return li->qtd;
}

void destruir_lista(Lista* li){
    if(li != NULL){
        Elem* aux = li->inicio;
        while(aux != NULL){
            Elem* atual = aux;
            aux = aux->prox;
            destruir_musica(atual->musica);
            free(atual);
        }

        free(li);
    }
}