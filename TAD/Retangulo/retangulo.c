#include <stdlib.h>
#include <stdio.h>
#include "retangulo.h"

struct retangulo {
    float x;
    float y;
    float largura;
    float altura;
};

Retangulo* criaRetangulo(float x, float y, float largura, float altura){
    Retangulo* r = malloc(sizeof(Retangulo));

    if(r != NULL){
        r->x = x;
        r->y = y;
        r->largura = largura;
        r->altura = altura;
    }

    return r;
}

void liberaRetangulo(Retangulo* r){
    if(r != NULL){
        free(r);
    }
}

int acessaRetangulo(Retangulo* r, float* x, float* y, float* largura, float* altura){
    if(r == NULL){
        return 0;
    }

    *x = r->x;
    *y = r->y;
    *largura = r->largura;
    *altura = r->altura;

    return 1;
}

int atribuiRetangulo(Retangulo* r, float x, float y, float largura, float altura){
    if(r == NULL){
        return 0;
    }

    r->x = x;
    r->y = y;
    r->largura = largura;
    r->altura = altura;

    return 1;
}

float areaRetangulo(Retangulo* r){
    if(r == NULL){
        return -1;
    }

    float area = r->altura * r->largura;

    return area;
}

float perimetroRetangulo(Retangulo* r){
    if(r == NULL){
        return -1;
    }

    float perimetro = 2 * (r->largura + r->altura);

    return perimetro;
}
