#include <stdlib.h>
#include <stdio.h>


typedef struct celula {
int dado;
struct celula *prox;
} celula;

celula *enfileira(celula *f, int x){
  celula* nova = malloc(sizeof(celula));
  if (nova == NULL) return NULL;

  nova->prox = f->prox;
  f->prox = nova;
  f->dado = x;
  return nova;
}