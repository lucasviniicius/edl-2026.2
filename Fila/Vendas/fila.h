typedef struct fila Fila;

Fila* criarFila();
int estaVazia(Fila* f);
int estaCheia(Fila* f);
int qtdVendas(Fila* f);
int inserirVenda(Venda* v, Fila* f);
int removerVenda(Fila* f);
Venda* consultarVendaFila(Fila* f);
void liberarFila(Fila* f);