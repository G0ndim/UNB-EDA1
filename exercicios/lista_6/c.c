#include <stdio.h>

typedef long Item;
#define less(A,B) (A < B)
#define exch(A,B){Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if (less(A,B)) exch(A,B);}

void insertionSort(Item *v, int l, int r){
    for (int i = r; i > l; i--)
        cmpexch(v[i], v[i-1]);
    
    for (int i = l + 2; i <= r; i++){
        int j = i; 
				Item temp = v[j];
        
				while (less(temp, v[j-1])){
            v[j] = v[j-1];
            j--;
        }
        v[j] = temp;
    }
}

int main() {
	Item vec[101], placa;
	int cmd, i = 0;
	
	while (scanf("%d %ld", &cmd, &placa) == 2) {
		if (cmd == 1) {
			if (i < 101){
				vec[i++] = placa;
				insertionSort(vec, 0, i-1);
			} 
			else{
				if (less(placa, vec[100])) {
					exch(placa, vec[100]);
					insertionSort(vec, 0, 100);
				}
			}
		} 
		else{
			int n = placa;
			for (int j = 0; j < n; j++)
				printf("%ld ", vec[j]);
			printf("\n");
		}
	}
	return 0;
}