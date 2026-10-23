typedef struct elem Elem;
typedef struct lista Lista;

Lista* criar_lista();
int inserir_inicio(Lista* li, int valor);
int inserir_final(Lista* li, int valor);
int remover_inicio(Lista* li);
int remover_final(Lista* li);
int acessar_inicio(Lista* li, int *valor);
int acessar_final(Lista* li, int *valor);
void destruir(Lista* li);