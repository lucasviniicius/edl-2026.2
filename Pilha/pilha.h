typedef struct pilha Pilha;

Pilha* criar();
int empilhar(Pilha* p, int valor);
int acessarTopo(Pilha* p);
int desempilhar(Pilha* p);
void destruir(Pilha* p);
