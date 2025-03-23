#include <stdio.h>
#include <stdlib.h>


int busca_binaria(int *v, int n, int x) {
    int inicio = 0, fim = n - 1;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (v[meio] >= x) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return inicio;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int *v = (int *)malloc(N * sizeof(int));
    if (v == NULL)  return;

    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        int j = busca_binaria(v, N, x);
        printf("%d\n", j);
    }

    free(v);

    return 0;
}
