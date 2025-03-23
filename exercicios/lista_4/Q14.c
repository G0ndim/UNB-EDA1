#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
  int dado;
  struct celula *prox;
} celula;

void empilha(celula *p, int x){
  celula *novo = malloc(sizeof(novo));
  if(novo == NULL) return;
  novo->dado = x;
  novo->prox = p->prox;
  p->prox = novo;
}

int desempilha(celula *p, int *y){
  if (p == NULL || p->prox == NULL) return 0;

  *y = p->prox->dado;
  p->prox = p->prox->prox;
  return 1;
}