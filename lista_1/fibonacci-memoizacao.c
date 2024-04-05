#include <stdio.h>

long int fibonacci(int n){
    static long int vet[1000];
    if (n == 1 || n == 2) return 1;
    if (vet[n] != 0) return vet[n];
    vet[n] = fibonacci(n-1) + fibonacci(n-2);
    return vet[n];
}
