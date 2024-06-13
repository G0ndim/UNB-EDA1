#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int encontraMenor(int *v, int n, int i, int menorIndex) {
    if (i == n)
        return menorIndex;
    if (v[i] < v[menorIndex])
        menorIndex = i;
    return encontraMenor(v, n, i + 1, menorIndex);
}

void selectionSortRecursivo(int *v, int n, int index) {
    if (index == n)
        return;

    int menorIndex = encontraMenor(v, n, index, index);

    if (menorIndex != index)
        swap(&v[index], &v[menorIndex]);

    selectionSortRecursivo(v, n, index + 1);
}

void ordena(int *v, int n) {
    selectionSortRecursivo(v, n, 0);
}

