#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int enfileira (fila *f, int x){
    if (f->p == 0 && f->u == f->N - 1){
        f->N *= 2;
        f->dados = realloc(f->dados, f->N * sizeof(int));
        if (f->dados == NULL)   return 0;
    }
    
    else if (f->p > 0 && f->u == f->p - 1){
        if (f->u <= f->N - f->p){
            int tamanho = f->N;
            f->N *= 2;
            f->dados = realloc(f->dados, f->N * sizeof(int));
            if (f->dados == NULL)   return 0;

            for (int i = 0; i < f->u; i++, tamanho++){
                f->dados[tamanho] = f->dados[i];
            }
            f->u = tamanho;
        }
        
        else if (f->u > f->N - f->p){
            int tamanho = f->N;
            f->N *= 2;
            f->dados = realloc(f->dados, f->N * sizeof(int));
            if (f->dados == NULL)   return 0;

            int aux = f->N - 1;
            for (int i = tamanho - 1; i > f->u; i--, aux--){
                f->dados[aux] = f->dados[i];
            }
            f->p = aux + 1;
        }
    }
    
    f->dados[f->u] = x;
    f->u++;
    if (f->u == f->N){
        f->u %= f->N;
    }
    
    return 1;
}

