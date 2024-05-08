#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

no* criar_no(int dado) {
    no *novo_no = malloc(sizeof(no));
    novo_no->dado = dado;
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    return novo_no;
}

no* inserir_no(no *raiz, int dado) {
    if (raiz == NULL)
        return criar_no(dado);

    if (dado < raiz->dado)
        raiz->esq = inserir_no(raiz->esq, dado);
    else if (dado > raiz->dado)
        raiz->dir = inserir_no(raiz->dir, dado);

    return raiz;
}


void pre_ordem(no *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}


void em_ordem(no *raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esq);
        printf("%d ", raiz->dado);
        em_ordem(raiz->dir);
    }
}


void pos_ordem(no *raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d ", raiz->dado);
    }
}


int main() {
    no *raiz = NULL;
    int dado;

    while (scanf("%d", &dado) != EOF) {
        raiz = inserir_no(raiz, dado);
    }

    
    pre_ordem(raiz);
    printf(".\n");

    em_ordem(raiz);
    printf(".\n");

    pos_ordem(raiz);
    printf(".\n");

    free(raiz);

    return 0;
}
