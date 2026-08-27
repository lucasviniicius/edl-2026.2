#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 4

struct pilha{
    int dados[MAX];
    int topo;
};

typedef struct pilha Pilha;

Pilha* criar(){
    Pilha* p = malloc(sizeof(struct pilha));

    if(p != NULL){
        p->topo = 0;
    }

    return p;
}

int empilhar(Pilha* p, int valor){
    if(p->topo == MAX){
        return 0;
    }

    p->dados[p->topo] = valor;
    p->topo++;

    return 1;
} 

int acessarTopo(Pilha* p){
    if(p->topo == 0){
        return 0;
    }

    return p->dados[p->topo - 1];
}

int desempilhar(Pilha* p){
    if(p->topo == 0){
        return 0;
    }

    p->topo--;
    return 1;
}

void destruir(Pilha* p){
    if(p != NULL){
        free(p);
    }
}

int main(){
    Pilha* p = criar();
    empilhar(p, 10);
    empilhar(p, 20);
    printf("Topo: %d\n", acessarTopo(p));
    desempilhar(p);
    printf("Topo: %d\n", acessarTopo(p));
    destruir(p);    

    return 0;
}