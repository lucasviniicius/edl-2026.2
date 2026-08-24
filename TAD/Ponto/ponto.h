typedef struct ponto Ponto;

Ponto* criar(float x, float y);
float calculaDistacia(Ponto* p1, Ponto* p2);
void destruir(Ponto* p);