struct livro {
    int id;
    char titulo[30];
    char autor[30];
};

typedef struct pilha Pilha;

Pilha* criaPilha();
void liberaPilha(Pilha* p);
int tamanhoPilha(Pilha* p);
int pilhaCheia(Pilha* p);
int pilhaVazia(Pilha* p);
int inserePilha(Pilha* p, struct livro li);
int removePilha(Pilha* p);
int acessaTopoPilha(Pilha* p, struct livro *li);