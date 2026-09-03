#include <stdlib.h>
#include <stdio.h>
#include "conjunto.h"

#define MAX 10

struct conjunto {
    int dados[MAX];
    int qtd;
};

Conjunto* criar(){
    Conjunto* c = malloc(sizeof(Conjunto));

    if(c != NULL){
        c->qtd = 0;
    }

    return c;
}

void destruir(Conjunto* c){
    if(c != NULL){
        free(c);
    }
}

int pertence(Conjunto* c, int valor){
    if(c == NULL){
        return 0;
    }

    for(int i = 0; i < c->qtd; i++){
        if(c->dados[i]  == valor){
            return 1;
        }
    }

    return 0;
}

int inserir(Conjunto* c, int valor){
    if(c == NULL || c->qtd == MAX){
        return 0;
    }

    if(pertence(c, valor)){
        return 0;
    }

    c->dados[c->qtd] = valor;
    c->qtd++;

    return 1;
}

int remover(Conjunto* c, int valor){
    int pos = 0;

    if(c == NULL){
        return 0;
    }

    if(!pertence(c, valor)){
        return 0;
    }

    for(int i = 0; i < c->qtd; i++){
        if(c->dados[i] == valor){
            pos = i;
        }
    }

    for(int i = pos; i < c->qtd - 1; i++){
        c->dados[i] = c->dados[i + 1];
    }

    c->qtd--;

    return 1;
}

int tamanho(Conjunto* c){
    if(c == NULL){
        return 0;
    }

    return c->qtd;
}

int vazio(Conjunto* c){
    if(c == NULL){
        return 0;
    }

    if(c->qtd == 0){
        return 1;
    }

    return 0;
}

int menor(Conjunto* c){
    if(c == NULL || c->qtd == 0){
        return 0;
    }

    int menor = c->dados[0];

    for(int i = 0; i < c->qtd; i++){
        if(c->dados[i] < menor){
            menor = c->dados[i];
        }
    }

    return menor;
}

int maior(Conjunto* c){
    if(c == NULL || c->qtd == 0){
        return 0;
    }

    int maior = c->dados[0];

    for(int i = 0; i < c->qtd; i++){
        if(c->dados[i] > maior){
            maior = c->dados[i];
        }
    }

    return maior;
}

int iguais(Conjunto* c1, Conjunto* c2){
    if(c1 == NULL || c2 == NULL){
        return 0;
    }

    if(c1->qtd != c2->qtd){
        return 0;
    }

    for(int i = 0; i < c1->qtd; i++){
        if(!pertence(c2, c1->dados[i])){
            return 0;
        };
    }

    return 1;
}

Conjunto* uniao(Conjunto* c1, Conjunto* c2){
    Conjunto* r = criar();

    for(int i = 0; i < c1->qtd; i++){
        inserir(r, c1->dados[i]);
    }

    for(int i = 0; i < c2->qtd; i++){
        inserir(r, c2->dados[i]);
    }

    return r;
}