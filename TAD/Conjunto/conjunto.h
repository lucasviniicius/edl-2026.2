typedef struct conjunto Conjunto;

Conjunto* criar();
void destruir(Conjunto* c);
int pertence(Conjunto* c, int valor);
int inserir(Conjunto* c, int valor);
int remover(Conjunto* c, int valor);
int tamanho(Conjunto* c);
int vazio(Conjunto* c);
int menor(Conjunto* c);
int maior(Conjunto* c);
int iguais(Conjunto* c1, Conjunto* c2);
Conjunto* uniao(Conjunto* c1, Conjunto* c2);