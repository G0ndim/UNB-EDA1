#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10000000

typedef struct no {
    int valor, cont;
    struct no *prox;
} no;

no *cria_fila(){
    no *novo = (no *)malloc(sizeof(no));
    novo->prox = NULL;
    return novo;
}

no* enfileira(no *ultimo, int x, int y){
    no *novo = cria_fila();
    novo->prox = ultimo->prox;
    ultimo->prox = novo;
    ultimo->valor = x;
    ultimo->cont = y;
    return novo;
}

void desenfileira(no *f){
    f->prox = f->prox->prox;
}

no *primeiro_elem(no *f){
    return f->prox;
}

bool fila_vazia(no *f){
    return f == NULL || f->prox == NULL;
}


int visitados[MAX];
int main(void){
    int f, s, g, u, d;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

    no *inicio = cria_fila();
    no *cabeca = cria_fila();
    cabeca->prox = inicio;
    no *atual = inicio;

    atual = enfileira(atual, s, 0);
    visitados[s] = 1;

    while (!fila_vazia(cabeca))
    {
        no *aux = primeiro_elem(cabeca);
        desenfileira(cabeca);
        if (aux->valor == g)
        {
            printf("%d\n", aux->cont);
            return 0;
        }
        
        if (u != 0 && aux->valor + u <= f && !visitados[aux->valor + u])
        {
            atual = enfileira(atual, aux->valor + u, aux->cont + 1);
            visitados[aux->valor + u] = 1;
        }
        
        if (d != 0 && aux->valor - d >= 1 && !visitados[aux->valor - d])
        {
            atual = enfileira(atual, aux->valor - d, aux->cont + 1);
            visitados[aux->valor - d] = 1; 
        }
    }
    
    printf("use the stairs\n");

    return 0;
}