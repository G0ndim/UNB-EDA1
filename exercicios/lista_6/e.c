#include <stdio.h>
#include <stdlib.h>
#define exchange(A, B) {int t = A; A = B; B = t;}

void SelectionSort(int *v, int l, int r){
  for(int i = l; i < r; i++){
    int menor = i;
    for(int j = i + 1; j <= r; j++){
      if(v[j] < v[menor]){
          menor = j;
      }
    }
    if(menor != i)  exchange(v[i], v[menor]);
   }
}

int main() {
  int vec[1000];
  int n = 0;

  while (scanf("%d", &vec[n]) != EOF) {
      n++;
  }

  SelectionSort(vec, 0, n-1);

  for (int i = 0; i < n; i++) {
    if (i > 0) {
      printf(" ");
    }
    
    printf("%d", vec[i]);
   }
   
  printf("\n");

  return 0;
}


