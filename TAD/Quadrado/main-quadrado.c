#include <stdio.h>
#include "quadrado.h"

int main(){
    float lado = 4;

    Quadrado* q = criar(lado);

    printf("Lado do quadrado: %.2f\n", acessar(q, 'L'));
    printf("Área do quadrado: %.2f\n", acessar(q, 'A'));
    printf("Perímetro do quadrado: %.2f", acessar(q, 'P'));

    destruir(q);

    return 0;
}