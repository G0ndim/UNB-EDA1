#include <stdio.h>
#include <stdlib.h>
#define exchange(A, B) {int t = A; A = B; B = t;}

void InsertionSort(int *v, int l, int r){
  int i, j, elem;
  for(i = l+1; i <= r; i++){
    
    elem = v[i];
    
    for(j = i; j > l && elem < v[j-1]; j--){
      v[j] = v[j-1];
    }
    
    v[j] = elem;
  }
}

int main() {
  int vec[50000];
  int n = 0;

  while (scanf("%d", &vec[n]) != EOF) {
      n++;
  }

  InsertionSort(vec, 0, n-1);

  for (int i = 0; i < n; i++) {
    if (i > 0) {
      printf(" ");
    }
    
    printf("%d", vec[i]);
   }
   
  printf("\n");

  return 0;
}


