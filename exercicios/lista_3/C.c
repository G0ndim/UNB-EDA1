#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime (celula *le){
    celula *temp = le->prox;
    while (temp){
        printf("%d -> ", temp->dado);
        temp = temp->prox;
    }
    printf("NULL\n");
}

void imprime_rec (celula *le){
    
    if (le->prox == NULL){
        printf("NULL\n");
    }
    else{
        printf("%d -> ", le->prox->dado);
        imprime_rec(le->prox);
    }
}