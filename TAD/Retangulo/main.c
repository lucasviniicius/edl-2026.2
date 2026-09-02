#include <stdio.h>
#include "retangulo.h"

int main(){
    Retangulo* r = criaRetangulo(1.0, 2.0, 5.0, 3.0);

    printf("Area esperada: 15.00 | Calculada: %.2f\n", areaRetangulo(r));
    printf("Perimetro esperado: 16.00 | Calculado: %.2f\n", perimetroRetangulo(r));

    float x, y, larg, alt;
    if (acessaRetangulo(r, &x, &y, &larg, &alt)) {
        printf("Valores acessados: Origem(%.1f, %.1f), L=%.1f, A=%.1f\n", x, y, larg, alt);
    }

    // 4. Modificando valores
    if (atribuiRetangulo(r, 0.0, 0.0, 10.0, 4.0)) {
        printf("Novos valores atribuidos com sucesso!\n");
        printf("Nova Area esperada: 40.00 | Calculada: %.2f\n", areaRetangulo(r));
    }

    return 0;
}