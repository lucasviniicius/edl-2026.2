typedef struct elem Elem;
typedef struct fila Fila;

Fila* criar_fila();
int inserir(Fila* fi, int valor);
int remover(Fila* fi);
int acessar(Fila* fi, int *valor);
void destruir(Fila* fi);