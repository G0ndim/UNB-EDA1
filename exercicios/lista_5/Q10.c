#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
  int dado;
  struct celula *prox;
} celula;

int desempilha(celula *p, int *y){
  if (p == NULL || p->prox == NULL) return 0;

  *y = p->prox->dado;
  p->prox = p->prox->prox;
  return 1;
}