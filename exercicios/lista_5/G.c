#include <stdio.h>
#include <stdlib.h>

typedef int Item;

void merge(Item *v, int l, int r1, int r2){
    Item *v2 = malloc(sizeof(Item) *(r2-l+1));
    int k = 0;
    int i = l;
    int j = r1 + 1;
    
    while (i <= r1 && j <= r2){
        if (v[i] <= v[j])
            v2[k++] = v[i++];
        else
            v2[k++] = v[j++]; 
    }
    
    while (i <= r1) v2[k++] = v[i++];
    while (j <= r2) v2[k++] = v[j++];

    for (int i = l, k = 0; i <= r2; i++, k++){
        v[i] = v2[k];
    }
    free(v2);
}

void merge_sort(Item *v, int l, int r){
    if (l >= r) return;
    int m = (l+r)/2;
    
    merge_sort(v, l, m);
    merge_sort(v, m + 1, r);
    merge(v, l, m, r);
}

void imprimir(Item *v, int l, int r){
    for (int i = l; i < r; i++)
        printf("%d ", v[i]);

    printf("%d\n", v[r]);
}

int main(void){
    int n, elem;
    scanf("%d", &n);
    Item v[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &elem);
        v[i] = elem;
    }
    
    merge_sort(v, 0, n - 1);
    imprimir(v, 0, n - 1);

    return 0;
}