#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto {
    float x;
    float y;
};

Ponto* criar(float x, float y){
    Ponto* p = malloc(sizeof(Ponto));

    if(p == NULL){
        return NULL;
    }

    p->x = x;
    p->y = y;

    return p;
}

float calculaDistacia(Ponto* p1, Ponto* p2){
    float distancia = sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));

    return distancia;
}

void destruir(Ponto* p){
    if(p != NULL){
        free(p);
    }
}