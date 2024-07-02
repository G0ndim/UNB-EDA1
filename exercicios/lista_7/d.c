#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define key(A) (A)
#define lesseq(A, B) (key(A) <= key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define cmpexch(A, B) {if(lesseq(B, A)) exch(A, B);}


int separa(Item *v, int l, int r){
    Item c = v[r];
    int j = l;

    for (int k = l; k < r; k++) {
        if (lesseq(v[k], c)) {
            exch(v[k], v[j]);
            j++;
        }
    }
    exch(v[j], v[r]);
    return j;
}

void quicksort(Item *v, int l, int r){
    int j;
    if (r <= l) return;

    cmpexch(v[(l+r)/2], v[r]);
    cmpexch(v[l], v[(l+r)/2]);
    cmpexch(v[r], v[(l+r)/2]);

    j = separa(v, l, r);
    quicksort(v, l, j-1);
    quicksort(v, j+1, r);
}

int remover_duplicados(Item *v, int n){
    int aux = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] != v[aux - 1]) 
            v[aux++] = v[i];
    }
    return aux;
}

int main(){
    int n;
    scanf("%d", &n);
    
    Item *vet = malloc(sizeof(int) * (2*n));
    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }
    
    quicksort(vet, 0, n-1);

    int t1 = remover_duplicados(vet, n);
    if (t1 % 2 != 0)
        vet[t1++] = 1000000000;

    int t2 = 0;
    for (int i = 0; i < t1-1; i+=2) {
        vet[t1+t2] = vet[i] + vet[i+1];
        t2++;
    }

    quicksort(vet, 0, t1+t2-1);

    t1 = remover_duplicados(vet, t1+t2);
    for (int i = 0; i < t1; i+=4) {
        printf("%d\n", vet[i]);
    }
    printf("Elementos: %d\n", t1);
    
    return 0;
}