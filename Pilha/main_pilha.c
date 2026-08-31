#include <stdio.h>
#include "pilha.h"

int main(){
    Pilha* p = criar();
    empilhar(p, 10);
    empilhar(p, 20);
    empilhar(p, 50);
    empilhar(p, 30);
    printf("Topo: %d\n", acessarTopo(p));
    desempilhar(p);
    printf("Topo: %d\n", acessarTopo(p));   
    printf("Topo: %d\n", acessarTopo(copiaPilha(p)));
    destruir(p); 

    return 0;
}