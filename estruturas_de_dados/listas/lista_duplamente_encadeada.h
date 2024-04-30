#ifndef LISTA_DUPLAMENTE_ENCADEADA
#define LISTA_DUPLAMENTE_ENCADEADA

#include <stdio.h>
#include <stdlib.h>

typedef struct Node celula;
struct Node{
  int info;
  celula *prox;
  celula *ant;
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
  novo->ant = NULL;

  return novo;
}

celula *buscar(cabeca *lista, int x){
  celula *a;
  for(a=lista->prox; a && a->info != x; a=a->prox);
  return a;
}

void inserir_inicio(cabeca *lista, celula *elem){
  elem->ant = NULL;
  elem->prox = lista->prox;
  lista->prox = elem;
  
  if(elem->prox != NULL) elem->prox->ant = elem;
  else  lista->ultimo = elem;
  lista->num_itens++;
}

void inserir_depois(cabeca *lista, celula *ref, celula *elem){
  elem->ant = ref;
  elem->prox = ref->prox;
  ref->prox = elem;
  
  if(elem->prox != NULL) elem->prox->ant = elem;
  else  lista->ultimo = elem;
  
  lista->num_itens++;
}

void insere_antes(cabeca *lista, celula *ref, celula *elem){
  if(lista->prox == ref){
    return inserir_inicio(lista, elem);
  }
  inserir_depois(lista, ref->ant, elem);
}

void inserir_fim(cabeca *lista, celula *elem){
  if(lista->prox == NULL){
    return inserir_inicio(lista, elem);
  }
  inserir_depois(lista, lista->ultimo, elem);
}


void remover_celula(cabeca *lista, celula *lixo){
  if(lista->prox == lixo) lista->prox = lixo->prox;
  else  lixo->ant->prox = lixo->prox;

  if(lista->ultimo == lixo) lista->ultimo = lixo->ant;
  else  lixo->prox->ant = lixo->ant;

  lista->num_itens--;
 
  free(lixo);
}

#endif