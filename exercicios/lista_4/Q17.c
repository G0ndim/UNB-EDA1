#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    int *dados;
    int N; 
    int topo; 
} pilha;

void desempilha (pilha *pi, int *y){
    *y = pi->dados[pi->topo++];
    pi->N++;
    pi->dados[pi->N] = pi->dados[pi->topo];
    pi->topo++;
}

pilha *cria_pilha(int n){
    pilha *novo = malloc(sizeof(pilha));
    novo->N = n;
    novo->topo = 1;
    novo->dados = malloc((n) * 2 * sizeof(int));
    for (int i = novo->topo; i <= novo->N; i++){
        novo->dados[i] = i;
    }
    
    return novo;
}

int main(void){
    int n , y;
    scanf("%d", &n);
    pilha *p = cria_pilha(n);
    printf("Cartas descartadas: ");
    for (int i = 1; i < n; i++){
        desempilha(p, &y);
        if (i == n-1){
            printf("%d", y);
            break;
        }
        printf("%d", y);
        printf(", ");
    }
    printf("\n");
    printf("Carta restante: %d", p->dados[p->topo]);
    free(p);
    return 0;
}