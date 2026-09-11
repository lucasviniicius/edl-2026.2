typedef struct venda Venda;

Venda* criarVenda(int codigoProduto, double valor, int qtd);
void consultaVenda(Venda* v, int *codigoProduto, double *valor, int *qtd);
void imprimirVenda(Venda* v);
void liberarVenda(Venda* v);