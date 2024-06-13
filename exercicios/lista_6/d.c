#include <stdio.h>
#include <stdlib.h>
#define exchange(A, B) {int t = A; A = B; B = t;}

void bubbleSort(int *v, int l, int r){
    int swap = 1;
    for(; r > l && swap; r--){
        swap = 0;
        for(int j = l; j < r; j++){
            if(v[j] > v[j+1]){
                exchange(v[j], v[j+1]);
                swap = 1;
            }
        }
    }
}

int main() {
  int vec[1000];
  int n = 0;

  while (scanf("%d", &vec[n]) != EOF) {
      n++;
  }

  bubbleSort(vec, 0, n-1);

  for (int i = 0; i < n; i++) {
    if (i > 0) {
      printf(" ");
    }
    
    printf("%d", vec[i]);
   }
   
  printf("\n");

  return 0;
}


