#include <stdio.h>
#include "complexo.h"

void imprimir(Complexo* c) {
    double real;
    double imaginaria;

    acessar(c, &real, &imaginaria);

    printf("%.2lf + %.2lfi\n", real, imaginaria);
}

int main() {

    Complexo* c1 = criar(2, 3);
    Complexo* c2 = criar(4, 5);

    Complexo* resultado;

    printf("C1: ");
    imprimir(c1);

    printf("C2: ");
    imprimir(c2);

    resultado = soma(c1, c2);
    printf("Soma: ");
    imprimir(resultado);
    destruir(resultado);

    resultado = subtracao(c1, c2);
    printf("Subtracao: ");
    imprimir(resultado);
    destruir(resultado);

    resultado = multiplicacao(c1, c2);
    printf("Multiplicacao: ");
    imprimir(resultado);
    destruir(resultado);

    resultado = divisao(c1, c2);

    if (resultado != NULL) {
        printf("Divisao: ");
        imprimir(resultado);
        destruir(resultado);
    } else {
        printf("Nao e possivel dividir por zero.\n");
    }

    destruir(c1);
    destruir(c2);

    return 0;
}