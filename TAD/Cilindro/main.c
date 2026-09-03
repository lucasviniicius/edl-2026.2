#include <stdlib.h>
#include <stdio.h>
#include "cilindro.h"

int main(){
    double raio;
    double altura;

    // Criando o cilindro
    Cilindro* c = criar(5.0, 10.0);

    // Testando acessar()
    if (acessar(c, &raio, &altura)) {
        printf("Raio: %.2lf\n", raio);
        printf("Altura: %.2lf\n", altura);
    }

    // Testando area
    printf("Area: %.2lf\n", calculaArea(c));

    // Testando volume
    printf("Volume: %.2lf\n", calculaVolume(c));

    // Destruindo o cilindro
    destruir(c);

    return 0;
}