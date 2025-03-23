#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pista pista;
struct pista {
    int identificador;
    int valor;
    int identificador_prox;
};

typedef struct no no;
struct no {
    pista p;
    no *prox;
};

typedef struct cabeca cabeca;
struct cabeca {
    no *inicio;
    no *fim;
};

void inicia_fila(cabeca *c){
   c->inicio = NULL;
   c->fim = NULL; 
}

no *cria_no(pista p){
    no *novo = malloc(sizeof(no));
    novo->p = p;
    novo->prox = NULL;
    return novo;
}

void enfileira(cabeca *c, pista p){
    no *novo = cria_no(p);
    
    if (c->inicio == NULL) c->inicio = novo;
    else c->fim->prox = novo;
    
    c->fim = novo;
}


int main(){
    int n;
    int id, val, idp;
    scanf("%d", &n);
    cabeca head;
    inicia_fila(&head);
    for (int i = 0; i < n; i++){
        scanf("%d %d %d", &id, &val, &idp);
        pista p = {id, val, idp};
        enfileira(&head, p);
    }
    
    no *aux = head.inicio;
    while (aux->p.identificador_prox != -1){
        printf("%d\n", aux->p.valor);
        no *aux2 = head.inicio;
        while (aux2->p.identificador != aux->p.identificador_prox)
        {
            aux2 = aux2->prox;
        }

        aux = aux2;
    }
    printf("%d\n", aux->p.valor);

    return 0;
}