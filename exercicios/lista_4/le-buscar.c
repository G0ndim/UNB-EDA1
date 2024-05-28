#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *busca(celula *le, int x){
    celula *temp = le->prox;
    while (temp != NULL && temp->dado != x){
        temp = temp->prox;
    }
    if (temp != NULL){
        return temp;
    }
}

celula *busca_rec(celula *le, int x){
    if (le == NULL){
        return NULL;
    }
    else{
        if (le->dado == x)
        {
            return le;
        }
    }
    return busca_rec(le->prox, x);
}


