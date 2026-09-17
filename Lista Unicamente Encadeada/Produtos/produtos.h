struct produto {
    int codigo;
    double preco;
};

typedef struct produto Produto;
typedef struct elemento Elem;
typedef struct lista Lista;

Lista* criar_lista();
int insere_inicio(Lista* li, struct produto p);
int insere_final(Lista* li, struct produto p);
int acessar_inicio(Lista* li, struct produto* p);
int remover_inicio(Lista* li);
int remover_final(Lista* li);
void imprimir_lista(Lista* li);
void destruir_lista(Lista* li);