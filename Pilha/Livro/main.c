#include <stdio.h>
#include <stdlib.h>
#include "livro.h"

// Função auxiliar para exibir um livro formatado
void exibe_livro(struct livro li) {
    printf("ID: %d | Titulo: %s | Autor: %s\n", li.id, li.titulo, li.autor);
}

/* 
 * DESAFIO: Função que exibe os elementos da pilha (do topo até a base)
 * e garante que, ao final, a pilha original permaneça idêntica.
 * Utiliza o seu padrão de nomenclatura (camelCase).
 */
void exibe_e_preserva_Pilha(Pilha* pi) {
    if (pi == NULL || pilhaVazia(pi)) {
        printf("A pilha esta vazia ou nao foi inicializada.\n");
        return;
    }

    // Cria uma pilha auxiliar para armazenar temporariamente os livros removidos
    Pilha* pi_aux = criaPilha();
    if (pi_aux == NULL) {
        printf("Erro ao criar pilha auxiliar.\n");
        return;
    }

    struct livro l_aux;
    printf("\n--- EXIBINDO A PILHA (LIFO) ---\n");

    // 1. Esvazia a pilha original, exibindo cada topo e salvando na auxiliar
    while (!pilhaVazia(pi)) {
        if (acessaTopoPilha(pi, &l_aux)) {
            exibe_livro(l_aux);
            inserePilha(pi_aux, l_aux); // Guarda na auxiliar
            removePilha(pi);            // Remove da original para acessar o próximo
        }
    }
    printf("-------------------------------\n");

    // 2. Restaura a pilha original empilhando de volta a partir da auxiliar
    while (!pilhaVazia(pi_aux)) {
        if (acessaTopoPilha(pi_aux, &l_aux)) {
            inserePilha(pi, l_aux);     // Devolve à pilha principal
            removePilha(pi_aux);        // Remove da auxiliar
        }
    }

    // 3. Libera o espaço de memória alocado para a pilha auxiliar
    liberaPilha(pi_aux);
}

int main(){
    Pilha* p = criaPilha();

    struct livro l1 = {1, "O Senhor dos Aneis", "J.R.R. Tolkien"};
    struct livro l2 = {2, "Neuromancer", "William Gibson"};
    struct livro l3 = {3, "Duna", "Frank Herbert"};

    printf("Empilhando os livros...\n");
    if (inserePilha(p, l1)) printf("Inserido: %s\n", l1.titulo);
    if (inserePilha(p, l2)) printf("Inserido: %s\n", l2.titulo);
    if (inserePilha(p, l3)) printf("Inserido: %s\n", l3.titulo);

    int qtdLivro = tamanhoPilha(p);
    printf("\nQuantidade de livros na pilha: %d\n", qtdLivro);

    struct livro topo;
    if (acessaTopoPilha(p, &topo)) {
        printf("\nLivro atualmente no topo:\n");
        exibe_livro(topo);
    }

    // 4. Exibição Completa usando a Pilha Auxiliar (Preservando a original)
    exibe_e_preserva_Pilha(p);

    // Confirmando que a pilha foi restaurada com sucesso
    if (acessaTopoPilha(p, &topo)) {
        printf("\nConfirmando topo apos exibicao: %s\n", topo.titulo);
    }

    // 5. Testando a Remoção (Desempilhando o topo)
    printf("\nRemovendo o livro do topo...\n");
    if (removePilha(p)) {
        printf("Removido com sucesso!\n");
    }

    // Exibindo novamente para ver a nova configuração
    exibe_e_preserva_Pilha(p);

    // 6. Liberação da Memória final
    printf("\nLiberando memoria da pilha...\n");
    liberaPilha(p);

    printf("Programa finalizado com sucesso.\n");

    return 0;
}