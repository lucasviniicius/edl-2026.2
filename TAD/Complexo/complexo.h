typedef struct complexo Complexo;

Complexo* criar(double real, double imaginaria);
void destruir(Complexo* c);
Complexo* soma(Complexo* c1, Complexo* c2);
Complexo* subtracao(Complexo* c1, Complexo* c2);
Complexo* multiplicacao(Complexo* c1, Complexo* c2);
Complexo* divisao(Complexo* c1, Complexo* c2);
int acessar(Complexo* c, double* real, double* imaginaria);