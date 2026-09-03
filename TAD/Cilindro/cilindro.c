#include <stdio.h>
#include <stdlib.h>
#include "cilindro.h"

#define PI 3.14159265359

struct cilindro{
    double raio;
    double altura;
};

Cilindro* criar(double raio, double altura){
    Cilindro* c = malloc(sizeof(Cilindro));

    if(c != NULL){
        c->raio = raio;
        c->altura = altura;
    }

    return c;
}

void destruir(Cilindro* c){
    if(c != NULL){
        free(c);
    }
}

int acessar(Cilindro* c, double* raio, double* altura){
    if(c == NULL){
        return 0;
    }

    *raio = c->raio;
    *altura = c->altura;

    return 1;
}

double calculaArea(Cilindro* c){
    if(c == NULL){
        return -1;
    }

    double area = 2 * PI * c->raio * (c->raio + c->altura);

    return area;
}

double calculaVolume(Cilindro* c){
    if(c == NULL){
        return -1;
    }

    double volume = PI * (c->raio * c->raio) * c->altura;

    return volume;
}