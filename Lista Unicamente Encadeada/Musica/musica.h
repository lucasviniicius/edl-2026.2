typedef struct musica Musica;

Musica* criar_musica(char titulo[30], char artista[30], int duracao);
int consultar_musica(Musica* m, char *titulo, char *artista, int *duracao);
int imprimir_musica(Musica* m);
void destruir_musica(Musica* m);