typedef struct retangulo Retangulo;

Retangulo* criaRetangulo(float x, float y, float largura, float altura);
void liberaRetangulo(Retangulo* r);
int acessaRetangulo(Retangulo* r, float* x, float* y, float* largura, float* altura);
int atribuiRetangulo(Retangulo* r, float x, float y, float largura, float altura);
float areaRetangulo(Retangulo* r);
float perimetroRetangulo(Retangulo* r);