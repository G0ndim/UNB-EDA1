#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
int *dados;
int N, p, u;
} fila;


int desenfileira(fila *f, int *y){
  if (f == NULL || f->p == f->u){
    return 0;
  }

  *y = f->dados[f->p];
  f->p = f->p +1;
  
  return 1;
}