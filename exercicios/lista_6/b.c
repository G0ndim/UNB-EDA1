#include <stdio.h>
#include <stdlib.h>

typedef int Key;
typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))


typedef struct {
    int valor;
    int indice;
} Elemento;

void selectionsort(Elemento *v, int l, int r){
    for (int i = l; i < r; i++) {
        int menor = i;
        for (int j = i + 1; j <= r; j++) {
            if (less(v[j].valor,v[menor].valor)) {
                menor = j;
            }
        }
        Elemento temp = v[i];
        v[i] = v[menor];
        v[menor] = temp;
    }
}

int busca_binaria(Elemento *v, int l , int r, Key k){
    while (l <= r) {
        int meio = l + (r - l) / 2;
        if (v[meio].valor == k) {
            return v[meio].indice; 
        }
        if (v[meio].valor < k) {
            l = meio + 1;
        } 
        else {
            r = meio - 1;
        }
    }
    return -1; 
}

int main(){
    int n, m, num;
    scanf("%d %d", &n, &m);

    Elemento *vet = (Elemento *)malloc(n * sizeof(Elemento));
    if (vet == NULL) {
        printf("Erro de alocação de memória\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i].valor);
        vet[i].indice = i;
    }

    selectionsort(vet, 0, n-1);
    
    for (int i = 0; i < m; i++) {
        scanf("%d", &num);
        int indice = busca_binaria(vet, 0, n-1, num);
        printf("%d\n", indice);
    }
    
    free(vet);
    return 0;
}