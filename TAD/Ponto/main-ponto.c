#include <stdio.h>
#include "ponto.h"

int main(){
    Ponto* p1 = criar(2, 2);
    Ponto* p2 = criar(5, 5);

    float resultado = calculaDistacia(p1, p2);
    printf("Resultado: %.2f", resultado);

    destruir(p1);
    destruir(p2);

    return 0;
}