#include <stdio.h>
#include "produtos.h"

int main(){
    Lista* li = criar_lista();

    struct produto p1 = {10, 25.50};
    struct produto p2 = {20, 40.00};
    struct produto p3 = {30, 100.00};

    insere_inicio(li, p2);
    insere_inicio(li, p1);
    insere_final(li, p3);

    printf("--- Estado Inicial ---\n");
    imprimir_lista(li);

    struct produto inicio;
    if(acessar_inicio(li, &inicio)){
        printf("\nPrimeiro produto: Codigo %d - R$ %.2f\n\n", inicio.codigo, inicio.preco);
    }

    remover_inicio(li);
    remover_final(li);

    printf("--- Apos Remocoes ---\n");
    imprimir_lista(li);

    destruir_lista(li);
    return 0;
}