typedef struct elemento Elem;
typedef struct lista Lista;

Lista* criar_lista();
int insere_inicio(Lista* li, int valor);
int insere_final(Lista* li, int valor);
int remover_inicio(Lista* li);
int remover_final(Lista* li);
int acessar_inicio(Lista* li, int *valor);
void destruir(Lista* li);
void imprimir_lista(Lista* li);