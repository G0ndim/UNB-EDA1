#include <stdio.h>

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

char *busca_binaria(Item *v, int l, int r, int k){
    if (l > r)  return "nao";

    int meio = (l+r)/2;

    if (k == v[meio]) 
        return "sim";
    else if (k < v[meio]) 
        return busca_binaria(v, 0, meio-1, k);

    return busca_binaria(v, meio + 1, r, k);
 }

int main(){
    int n;
    scanf("%d", &n);
    
    int np[140001];
    for (int i = 0; i < n; i++) {
        scanf("%d", &np[i]);
    }

    quicksort(np, 0, n-1);

    int num;
    while (scanf("%d", &num) != EOF) {
        printf("%s\n", busca_binaria(np, 0, n-1, num));
    }

    return 0;
}