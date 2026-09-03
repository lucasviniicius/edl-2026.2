#include <stdio.h>
#include "conjunto.h"

int main(){

    Conjunto* c1 = criar();
    Conjunto* c2 = criar();

    // Inserindo elementos em c1
    inserir(c1, 10);
    inserir(c1, 20);
    inserir(c1, 30);
    inserir(c1, 40);

    // Inserindo elementos em c2
    inserir(c2, 30);
    inserir(c2, 40);
    inserir(c2, 50);
    inserir(c2, 60);

    printf("Tamanho de c1: %d\n", tamanho(c1));
    printf("Tamanho de c2: %d\n", tamanho(c2));

    // Testando pertence
    if(pertence(c1, 20)){
        printf("20 pertence a c1\n");
    }else{
        printf("20 nao pertence a c1\n");
    }

    if(pertence(c2, 20)){
        printf("20 pertence a c2\n");
    }else{
        printf("20 nao pertence a c2\n");
    }

    // Menor e maior
    printf("Menor de c1: %d\n", menor(c1));
    printf("Maior de c1: %d\n", maior(c1));

    // Testando vazio
    if(vazio(c1)){
        printf("c1 esta vazio\n");
    }else{
        printf("c1 nao esta vazio\n");
    }

    // Testando conjuntos iguais
    if(iguais(c1, c2)){
        printf("c1 e c2 sao iguais\n");
    }else{
        printf("c1 e c2 sao diferentes\n");
    }

    // Uniao
    Conjunto* r = uniao(c1, c2);

    printf("Tamanho da uniao: %d\n", tamanho(r));

    // Removendo elemento de c1
    if(remover(c1, 20)){
        printf("20 foi removido de c1\n");
    }else{
        printf("20 nao foi removido de c1\n");
    }

    printf("Novo tamanho de c1: %d\n", tamanho(c1));

    // Tentando inserir elemento repetido
    if(inserir(c1, 10)){
        printf("10 foi inserido novamente\n");
    }else{
        printf("10 nao foi inserido, pois ja existe\n");
    }

    destruir(c1);
    destruir(c2);
    destruir(r);

    return 0;
}