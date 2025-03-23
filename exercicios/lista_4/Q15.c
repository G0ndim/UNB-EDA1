#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
  int *v;
  int N, topo;
} pilha;


void empilha(pilha *p, int x){
  
  if (p->topo == p->N){ 
        p->N *= 2;
        int *novo = realloc(p->v, p->N * sizeof(int));
        if (novo == NULL){
            return;
        }
        p->v = novo;
    }

  p->v[p->topo++] = x;
}


int desempilha(pilha *p, int *y){
  if (p->topo == 0) return 0;

  *y = p->v[--p->topo];

  return 1;
}