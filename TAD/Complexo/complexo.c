#include <stdio.h>
#include <stdlib.h>
#include "complexo.h"

struct complexo {
    double real;
    double imaginaria;
};

Complexo* criar(double real, double imaginaria){
    Complexo* c = malloc(sizeof(Complexo));

    if(c != NULL){
        c->real = real;
        c->imaginaria = imaginaria;
    }

    return c;
}

void destruir(Complexo* c){
    if(c != NULL){
        free(c);
    }
}

Complexo* soma(Complexo* c1, Complexo* c2){
    double real = c1->real + c2->real;
    double imaginaria = c1->imaginaria + c2->imaginaria;

    return criar(real, imaginaria);
}

Complexo* subtracao(Complexo* c1, Complexo* c2){
    double real = c1->real - c2->real;
    double imaginaria = c1->imaginaria - c2->imaginaria;

    return criar(real, imaginaria);
}

Complexo* multiplicacao(Complexo* c1, Complexo* c2){
    double real = (c1->real * c2->real) -
                  (c1->imaginaria * c2->imaginaria);

    double imaginaria = (c1->real * c2->imaginaria) +
                        (c1->imaginaria * c2->real);

    return criar(real, imaginaria);
}

Complexo* divisao(Complexo* c1, Complexo* c2){
    double denominador =
        (c2->real * c2->real) +
        (c2->imaginaria * c2->imaginaria);

    if (denominador == 0) {
        return NULL;
    }

    double real =
        ((c1->real * c2->real) +
         (c1->imaginaria * c2->imaginaria))
        / denominador;

    double imaginaria =
        ((c1->imaginaria * c2->real) -
         (c1->real * c2->imaginaria))
        / denominador;

    return criar(real, imaginaria);
}

int acessar(Complexo* c, double* real, double* imaginaria){
    if(c == NULL){
        return 0;
    }

    *real = c->real;
    *imaginaria = c->imaginaria;

    return 1;
}