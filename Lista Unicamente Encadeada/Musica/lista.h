#include "musica.h"

typedef struct elem Elem;
typedef struct lista Lista;

Lista* criar_lista();
int inserir_inicio(Lista* li, Musica* musica);
int inserir_final(Lista* li, Musica* musica);
int inserir_posicao(Lista* li, int pos, Musica* musica);
int remover_inicio(Lista* li);
int remover_final(Lista* li);
int remover_posicao(Lista* li, int pos);
Musica* consultar_inicio(Lista* li);
Musica* consulta_posicao(Lista* li, int pos);
int consultar_quantidade(Lista* li);
void destruir_lista(Lista* li);