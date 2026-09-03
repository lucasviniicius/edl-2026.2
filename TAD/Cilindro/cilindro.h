typedef struct cilindro Cilindro;

Cilindro* criar(double raio, double altura);
void destruir(Cilindro* c);
int acessar(Cilindro* c, double* raio, double* altura);
double calculaArea(Cilindro* c);
double calculaVolume(Cilindro* c);