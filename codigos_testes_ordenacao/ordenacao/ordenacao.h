#ifndef _ORDENACAO_H_
#define _ORDENACAO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef long Item;
static Item *pq; //fila de prioridades
static int N;    //qtde. de elementos na fila de prioridades

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define lesseq(A, B) (key(A) <= key(B))
#define exch(A, B) { Item t=A; A=B; B=t; }
#define compexch(A, B) if(comp(&B, &A)) exch(A, B)
#define insertion_sort(A, B, C) insertion_otimizado(A, B, C);

#define bitsbyte 8
#define bytesword 8

#define R (1 << bitsbyte) //00000001 << 8 = 00000001 00000000 = 2^8 = 256
#define digit(N,D) (((N) >> ((D)*bitsbyte)) & (R-1))


void show(Item [], int, int);
int is_sorted(Item [], int, int);
int cless(const void*, const void*);

//elementares
void selection(Item v[], int l, int r);
void selection_r(Item v[], int l, int r);
void bubble(Item v[], int l, int r);
void shaker(Item v[], int l, int r);
void insertion_simples(Item v[], int l, int r);
void insertion_otimizado(Item v[], int l, int r);
void insertion_otimizado_pre(Item v[], int l, int r);
void shell(Item v[], int l, int r);

//eficientes



#endif
