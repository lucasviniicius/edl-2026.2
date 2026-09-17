#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    // 1. Criação da Lista
    Lista* li = criar_lista();
    printf("Lista criada com sucesso!\n\n");

    // 3. Teste de Inserção no Início e Fim
    printf("--- Inserindo ---\n");
    insere_inicio(li, 1);
    insere_inicio(li, 12);
    insere_final(li, 22); 

    imprimir_lista(li);
    printf("\n");

    printf("--- Acessando o Primeiro Elemento ---\n");
    int valor;
    if (acessar_inicio(li, &valor)) {
        printf("Primeiro: %d\n", valor);
    } else {
        printf("Falha ao acessar o inicio da lista.\n\n");
    }

    // 5. Teste de Remoção no Início
    printf("--- Removendo do Inicio ---\n");
    remover_inicio(li);
    imprimir_lista(li);
    printf("\n");

    // 6. Teste de Remoção no Fim
    printf("--- Removendo do Fim ---\n");
    remover_final(li);
    imprimir_lista(li);
    printf("\n");

    // 7. Destruição da Lista
    printf("--- Destruindo a Lista ---\n");
    destruir(li);
    printf("Memoria liberada com sucesso!\n");

    return 0;
}