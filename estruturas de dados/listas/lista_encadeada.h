#ifndef LISTA_ENCADEADA
#define LISTA_ENCADEADA
#include <stdio.h>
#include <stdlib.h>

typedef struct Node celula;
struct Node{
  int info;
  celula *prox;
};

typedef struct Head cabeca;
struct Head{
  int num_itens;
  celula *prox;
  celula *ultimo;
};

cabeca *criar_lista(){
  cabeca *le = (cabeca *)malloc(sizeof(cabeca));
  le->num_itens = 0;
  le->prox = NULL;
  le->ultimo = NULL;

  return le;
}

celula *criar_celula(int x){
  celula *novo = (celula *)malloc(sizeof(celula));
  novo->info = x;
  novo->prox = NULL;

  return novo;
}

void inserir_inicio(cabeca *lista, celula *elem){
  elem->prox = lista->prox;
  lista->prox = elem;
  lista->num_itens++;
  if(elem->prox == NULL) lista->ultimo = elem;
}

void inserir_depois(cabeca *lista, celula *ref, celula *elem){
  elem->prox = ref->prox;
  ref->prox = elem;
  lista->num_itens++;
  if(elem->prox == NULL) lista->ultimo = elem;
}

void inserir_fim(cabeca *lista, celula *elem){
  if (lista->ultimo == NULL){
    lista->prox = elem;
  }
  else{
    lista->ultimo->prox = elem;
  }
  elem->prox = NULL;
  lista->ultimo = elem;
  lista->num_itens++;
}

void remover_inicio(cabeca *lista){
  if(lista->prox == NULL) return;

  celula *lixo = lista->prox;
  lista->prox = lixo->prox;
  lista->num_itens--;
  free(lixo);
}

void remover_celula(cabeca *lista, celula *lixo){
  if(lista->prox == lixo){
    return remover_inicio(lista);
  }

  celula *ant;
  for(ant = lista->prox; ant != NULL && ant->prox != lixo; ant = ant->prox);

  if(ant){
    ant->prox = lixo->prox;
    lista->num_itens--;
    if(ant->prox == NULL) lista->ultimo = ant;
  }

  free(lixo);
}

celula *buscar(cabeca *lista, int x){
  celula *a;
  for(a=lista->prox; a && a->info != x; a=a->prox);
  return a;
}


#endif