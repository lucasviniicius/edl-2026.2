typedef struct fila Fila;

Fila* criar();
int enfileirar(Fila* f, int valor);
int desinfileirar(Fila* f);
int acessar(Fila* f);
void destruir(Fila* f);