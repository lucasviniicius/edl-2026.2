#include <stdio.h>
#include "pilha.h"

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