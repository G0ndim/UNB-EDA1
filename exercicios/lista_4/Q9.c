#include <stdio.h>
#include <stdlib.h>

typedef struct {
int *dados;
int N, p, u;
} fila;

int desenfileira(fila *f, int *y){
  if(f->p == f->u){
    f->N *= 2;
    int *novo = realloc(f->dados, f->N * sizeof(int));
    if (novo == NULL) return 0;
    
    f->dados = novo;
  }
  
  *y = f->dados[f->p];
  f->p = (f->p + 1) % f->N;

  return 1;
}