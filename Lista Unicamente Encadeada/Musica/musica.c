#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"

struct musica {
    char titulo[30];
    char artista[30];
    int duracao; // duração dado em segundos
};

Musica* criar_musica(char titulo[30], char artista[30], int duracao){
    Musica* m = malloc(sizeof(Musica));
    if(m != NULL){
        strcpy(m->titulo, titulo);
        strcpy(m->artista, artista);
        m->duracao = duracao;
    }

    return m;
}

int consultar_musica(Musica* m, char *titulo, char *artista, int *duracao){
    if(m == NULL){
        return 0;
    }

    strcpy(titulo, m->titulo);
    strcpy(artista, m->artista);
    *duracao = m->duracao;

    return 1;
}

int imprimir_musica(Musica* m){
    if(m == NULL){
        return 0;
    }

    printf("Título: %s\n", m->titulo);
    printf("Artista: %s\n", m->artista);
    printf("Duração: %d\n", m->duracao);

    return 1;
}

void destruir_musica(Musica* m){
    if(m != NULL){
        free(m);
    }
}