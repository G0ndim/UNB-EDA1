#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    char sequencia[N+1];
    scanf("%s", sequencia);

    int i, j;
    int palindromo = 1;

    for (i = 0, j = strlen(sequencia) - 1; i < j; i++, j--) {
        if (sequencia[i] != sequencia[j]) {
            palindromo = 0;
            break;
        }
    }

    printf("%d\n", palindromo);

    return 0;
}
