#include <stdlib.h>
#include <string.h>

#define MAX 4

struct fila{
    int senha[MAX];
    int inicio;
    int fim;
};

typedef struct fila Fila;

Fila* criar(){
    Fila* f = malloc(sizeof(struct fila));

    if(f != NULL){
        f->inicio = 0;
        f->fim = 0;
    }

    return f;
}

int enfileirar(Fila* f, int valor){
    if(f->fim == MAX){
        return 0;
    }
    
    f->senha[f->fim] = valor;
    f->fim++;

    return 1;
}

int main(){
    return 0;
}