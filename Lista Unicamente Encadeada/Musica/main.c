#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"
#include "lista.h"

void adiciona_musica(Lista* li, Musica* m){
    if(inserir_final(li, m)){
        printf("Música adicionada ao final da playlist\n");
    } else {
        printf("Erro ao adicionar música\n");
    }
}

void adiciona_musica_posicao(Lista* li, int pos, Musica* m){
    if(inserir_posicao(li, pos, m)){
        printf("Música adicionada na posição %d\n", pos);
    } else {
        printf("Erro ao adicionar música\n");
    }
}

void remove_musica_posicao(Lista* li, int pos){
    if(remover_posicao(li, pos)){
        printf("Música removida na posição %d\n", pos);
    } else {
        printf("Erro ao remover música\n");
    }
}

void tempo_restante(Lista* li, int posAtual){
    int tempo = 0;
    int qtd = consultar_quantidade(li);

    for(int i = posAtual; i < qtd; i++){
        Musica* m = consulta_posicao(li, i);

        if(m != NULL){
            char t[30], a[30];
            int duracao;
            consultar_musica(m, t, a, &duracao);
            tempo += duracao;
        }
    }

    int min = tempo / 60; 
    int seg = tempo % 60; 
    printf("Tempo restante da playlist: %d segundos (%d min %d seg)\n", tempo, min, seg);
}

void play(Lista* li, int* posAtual){
    int qtd = consultar_quantidade(li);

    if(li == NULL || *posAtual >= qtd) { 
        printf("\nFim da playlist ou playlist vazia.\n"); 
        return; 
    }

    Musica* m = consulta_posicao(li, *posAtual);

    if(m != NULL){
        printf("\n--- Reproduzindo (Posição %d) ---\n", *posAtual);
        imprimir_musica(m);
        (*posAtual)++;
    }
}

void musicas_reproduzidas(int posAtual){
    printf("Músicas já reproduzidas: %d\n", posAtual);
}

int main(){
    SetConsoleOutputCP(65001);

    Lista* li = criar_lista();

    Musica* m1 = criar_musica("m1", "Wesley Safadao", 354);
    Musica* m2 = criar_musica("m2", "Xand Avião", 183);
    Musica* m3 = criar_musica("m3", "Zé Vaqueiro", 391);
    Musica* m4 = criar_musica("m4", "Gustavo Lima", 391);
    Musica* m5 = criar_musica("m5", "Henrique e Juliano", 391);
    Musica* m6 = criar_musica("m6", "Leo Foguete", 391);
    Musica* m7 = criar_musica("m7", "Rey Vaqueiro", 391);
    Musica* m8 = criar_musica("m8", "Lucas Vinicius", 391);
    Musica* m9 = criar_musica("m9", "CR7", 391);
    Musica* m10 = criar_musica("m10", "Neymar", 391);

    int posProximaMusica = 0;

    adiciona_musica(li, m1);
    adiciona_musica(li, m2);
    adiciona_musica(li, m3);
    adiciona_musica(li, m4);
    adiciona_musica(li, m5);
    adiciona_musica(li, m6);
    adiciona_musica(li, m7);
    adiciona_musica(li, m8);
    adiciona_musica(li, m9);
    adiciona_musica(li, m10);

    printf("\n=== OPERAÇÕES DA PLAYLIST ===\n");

    tempo_restante(li, posProximaMusica);

    play(li, &posProximaMusica);
    play(li, &posProximaMusica);

    musicas_reproduzidas(posProximaMusica);
    tempo_restante(li, posProximaMusica);

    Musica* m_new = criar_musica("m_new", "Manoel Gomes", 258);
    adiciona_musica_posicao(li, 2, m_new);

    remove_musica_posicao(li, 5);

    play(li, &posProximaMusica);

    printf("\n=== RESUMO ===\n");
    printf("Quantidade de músicas na playlist: %d\n", consultar_quantidade(li));
    printf("Posição da proxima musica: %d\n", posProximaMusica);

    destruir_lista(li);

    return 0;
}