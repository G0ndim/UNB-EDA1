#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void divide_lista (celula *l, celula *l1, celula *l2){
    celula *temp = l->prox;
    while (temp != NULL)
    {
        celula *nova_celula = malloc(sizeof(celula));
        nova_celula->dado = temp->dado;
        nova_celula->prox = NULL;
        if (temp->dado % 2 != 0){
            l1->prox = nova_celula;
            l1 = l1->prox;
        }
        else{
            l2->prox = nova_celula;
            l2 = l2->prox;
        }
        temp = temp->prox;
    }
}