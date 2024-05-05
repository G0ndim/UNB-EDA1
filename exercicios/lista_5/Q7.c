#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void enfileira (celula **f, int x){
    celula *temp = *f;
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    if (*f == NULL){
        *f = novo;
        novo->prox = novo;
    }

    else{
        while (temp->prox != (*f)){
            temp = temp->prox;
        }
        temp->prox = novo;
        novo->prox = (*f);
    }
}

int desenfileira (celula *f, int *y){
    if (f->prox == f){
        return 0;
    }
    celula *temp = f->prox;
    *y = temp->dado;
    f->prox = temp->prox;
    free(temp);
    
    return 1;
}