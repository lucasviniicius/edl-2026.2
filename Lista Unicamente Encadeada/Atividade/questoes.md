# Lista de exercícios: Listas Encadeadas

1. O que é uma lista encadeada e como ela é estruturada?

**Resposta:** Um lista encandeada é uma estrutura de dados que possui tamanho dinâmico, ou seja, não possui tamanho fixo, e cada elemento da lista possui um ponteiro para o próximo elemento.

2. Qual a diferença entre uma lista encadeada e um vetor?

**Resposta:** Na lista encadeada o tamanho é dinâmico, ou seja, não possui tamanho fixo, pode aumentar ou diminuir de acordo com as operações feitas. No vetor é necessário definir um tamanho máximo.

3. Quais as vantagens de utilizar listas encadeadas em relação a vetores?

**Resposta:** Utilizar listas encadeadas em relação a vetores é mais vantajoso, pois podemos inserir quantos elementos quisermos, sem tamanho fixo.

4. O que é um nó em uma lista encadeada e quais informações ele armazena?

**Resposta:** Um nó em uma lista encadeada consiste no elemento que vai ser manipulado na lista. Um nó armazena o dado e ponteiro para o próximo elemento.

5. Implemente uma lista unicamente encadeada, que deve conter os métodos: cria_lista, libera_lista, lista_vazia, tamanho_lista, insere_inicio, insere_final, remove_inicio, remove_final, imprime_lista, imprime_lista_reverso, busca_valor, consulta_lista_posicao.

**Resposta:**

```c
typedef struct elem Elem;
typedef struct lista Lista;
typedef struct exemplo Exemplo;

struct elem {
    Exemplo dado;
    Elem* prox;
};

struct lista {
    int qtd;
    Elem* inicio;
};

Lista* cria_lista(){
    Lista* li = malloc(sizeof(Lista));
    if(li != NULL){
        li->qtd = 0;
        li->inicio = NULL;
    }
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* aux = li->inicio;

        while(aux != NULL){
            Elem* atual = aux;
            aux = aux->prox;
            free(atual);
        }
        free(li);
    }
}

int lista_vazia(Lista* li){
    if(li->qtd == 0){
        return 1;
    }
    return 0;
}

int tamanho_lista(Lista* li){
    return li->qtd;
}

int insere_inicio(Lista* li, Exemplo dado){
    if(li == NULL){
        return 0;
    }

    Elem* no = malloc(sizeof(Elem));
    no->dado = dado;
    no->prox = li->inicio;
    li->inicio = no;
    li->qtd++;

    return 1;
}

int insere_final(Lista* li, Exemplo dado){
    if(li == NULL){
        return 0;
    }

    Elem* no = malloc(sizeof(Elem));
    no->dado = dado;
    no->prox = NULL;

    if(li->inicio == NULL){
        li->inicio = no;
        li->qtd++;
        return 1;
    }

    Elem* aux = li->inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = no;
    li->qtd++;
    return 1;
}

int remove_inicio(Lista* li){
    if(li == NULL){
        return 0;
    }

    if(li->inicio == NULL){
        return 0;
    }

    Elem* aux = li->inicio;
    li->inicio = aux->prox;
    free(aux);
    li->qtd--;

    return 1;
}

int remove_final(Lista* li){
    if(li == NULL){
        return 0;
    }

    if(li->inicio == NULL){
        return 0;
    }

    Elem* aux = li->inicio;
    Elem* ant = NULL;
    while(aux->prox != NULL){
        ant = aux;
        aux = aux->prox;
    }

    if(ant == NULL){
        li->inicio = NULL;
    } else {
        ant->prox = NULL;
    }

    free(aux);
    li->qtd--;

    return 1;
}

void imprime_lista(Lista* li){
    if(li == NULL){
        return;
    }

    Elem* aux = li->inicio;

    while(aux != NULL){
        printf("Exemplo: %s", aux->dado.nome);
        printf("Exemplo: %d", aux->dado.valor);
        aux = aux->prox;
    }
}

void imprime_lista_reverso(Elem* aux){
    if(aux == NULL){
        return;
    }

    imprime_lista_reverso(aux->prox);

    printf("Exemplo: %s", aux->dado.nome);
    printf("Exemplo: %d", aux->dado.valor);
}

void busca_valor(Lista* li, int valor){
    if(li == NULL){
        return;
    }

    Elem* aux = li->inicio;
    while(aux != NULL && aux->dado.valor != valor){
        aux = aux->prox;
    }

    if(aux != NULL){
        printf("Exemplo: %s", aux->dado.nome);
        printf("Exemplo: %d", aux->dado.valor);
    } else {
        printf("Elemento não encontrado.");
    }
}

void consulta_lista_posicao(Lista* li, int pos){
    if(li == NULL || pos < 0 || li->inicio == NULL){
        return;
    }

    Elem* aux = li->inicio;
    for(int i = 0; i < pos; i++){
        aux = aux->prox;
    }

    if(aux == NULL){
        return;
    }

    printf("Exemplo: %s", aux->dado.nome);
    printf("Exemplo: %d", aux->dado.valor);
}
```

6. Faça um programa que possua uma lista que armazene números inteiros. O programa deve executar os seguintes passos:

   (a) Inserir os seguintes valores na lista: 1, 0, 5, -2, -5, 7.  
   (b) Calcular a soma entre o primeiro, o segundo e o último elemento da lista.  
   (c) Modificar um elemento da lista.  
   (d) Imprimir todos os valores da lista.

**Resposta:**

```c
typedef struct elem Elem;
typedef struct lista Lista;

struct elem {
    int dado;
    Elem* prox;
};

struct lista {
    int qtd;
    Elem* inicio;
};

(a)
int inserir_final(Lista* li, int valor){
    if(li == NULL){
        return 0;
    }

    Elem* no = malloc(sizeof(Elem));
    no->dado = valor;
    no->prox = NULL;

    if(li->inicio == NULL){
        li->inicio = no;
        li->qtd++;
        return 1;
    }

    Elem* aux = li->inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = no;
    li->qtd++;

    return 1;
}

Main

inserir_final(li, 1);
inserir_final(li, 0);
inserir_final(li, 5);
inserir_final(li, -2);
inserir_final(li, -5);
inserir_final(li, 7);

(b)
int consulta_lista_posicao(Lista* li, int pos){
    if(li == NULL || li->inicio == NULL || pos < 0){
        return -1;
    }

    Elem* aux = li->inicio;
    for(int i = 0; i < pos; i++){
        aux = aux->prox;
    }

    if(aux != NULL){
        return aux->dado;
    } else {
        return -1;
    }
}

int consulta_lista_final(Lista* li){
    if(li == NULL || li->inicio == NULL){
        return;
    }

    Elem* aux = li->inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    return aux->dado;
}

Main

consulta_lista_posicao(li, 0);
consulta_lista_posicao(li, 1);
consulta_lista_final(li);

(c)
int modificar_elemento_lista(Lista* li, int pos, int valor){
    if(li == NULL || li->inicio == NULL){
        return 0;
    }

    Elem* aux = li->inicio;
    for(int i = 0; i < pos; i++){
        aux = aux->prox;
    }

    if(aux != NULL){
        aux->dado = valor;
    }

    return 1;
}

(d)
void imprimir_valor_lista(Lista* li){
    if(li == NULL || li->inicio == NULL){
        return;
    }

    Elem* aux = li->inicio;
    while(aux != NULL){
        printf("Valor: %d", aux->dado);
        aux = aux->prox;
    }
}
```

7. Crie um programa que leia valores inteiros e armazene em uma lista encadeada. Em seguida, mostre na tela os valores lidos.

**Resposta:**

```c
typedef struct elem Elem;
typedef struct lista Lista;

struct elem {
    int valor;
    Elem* prox;
}

struct lista {
    int qtd;
    Elem* inicio;
}

Lista* criar_lista(){
    Lista* li = malloc(sizeof(Lista));
    if(li != NULL){
        li->qtd = 0;
        li->inicio = NULL;
    }

    return li;
}

int armazenar_valor_final(Lista* li, int valor){
    if(li == NULL){
        return 0;
    }

    Elem* no = malloc(sizeof(Elem));
    no->valor = valor;
    no->prox = NULL;

    if(li->inicio == NULL){
        li->inicio = no;
        li->qtd++;
        return 1;
    }

    Elem* aux = li->inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = no;
    li->qtd++;

    return 1;
}

void imprime_valor_lista(Lista* li){
    if(li == NULL || li->inicio == NULL){
        return;
    }

    Elem* aux = li->inicio;
    while(aux != NULL){
        printf("Valor: %d", aux->valor);
        aux = aux->prox;
    }
}
```

8. Ler um conjunto de números reais, armazenando-os em uma lista encadeada e calcular o quadrado de cada elemento, armazenando o resultado em outra lista. Imprimir ambas as listas.

**Resposta:**

```c
int armazenar_valor_lista(Lista* li, int valor){
    if(li == NULL){
        return 0;
    }

    Elem* no = malloc(sizeof(Elem));
    no->valor = valor * valor;
    no->prox = NULL;

    if(li->inicio == NULL){
        li->inicio = no;
        li->qtd++;
        return 1;
    }

    Elem* aux = li->inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = no;
    li->qtd++;
    return 1;
}
```

10. Faça um programa que leia uma lista de valores inteiros. Em seguida, deverá contar e escrever quantos valores negativos ela possui.

**Resposta:**

```c
int valor_negativo_lista(Lista* li){
    int qtdNegativos = 0;

    if(li == NULL || li->inicio == NULL){
        return -1;
    }

    Elem* aux = li->inicio;
    while(aux != NULL){
        if(aux->valor < 0){
            qtdNegativos++;
        }
        aux = aux->prox;
    }

    return qtdNegativos;
}
```

11. Faça um programa que receba uma lista de inteiros. Em seguida, deverá ser impresso o maior e o menor elemento da lista.

**Resposta:**

```c
int maior_lista(Lista* li){
    if(li == NULL || li->inicio == NULL){
        return -1;
    }

    Elem* aux = li->inicio;
    int maior = aux->valor;
    while(aux != NULL){
        if(aux->valor > maior){
            maior = aux->valor;
        }
        aux = aux->prox;
    }

    return maior;
}

int menor_lista(Lista* li){
    if(li == NULL || li->inicio == NULL){
        return 0;
    }

    Elem* aux = li->inicio;
    int menor = aux->valor;
    while(aux != NULL){
        if(aux->valor < menor){
            menor = aux->valor;
        }
        aux = aux->prox;
    }

    return menor;
}
```
