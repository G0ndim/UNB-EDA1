#include <stdio.h>

int main() {
    int tamanho, pares_corretos = 0;
    int contagem[61][2] = {0}; 

    while (scanf("%d", &tamanho) != EOF) {
        char pe;
        scanf(" %c", &pe);

        if (pe == 'D') {
            contagem[tamanho][0]++; 
        } else {
            contagem[tamanho][1]++; 
        }

        if (contagem[tamanho][0] > 0 && contagem[tamanho][1] > 0) {
            pares_corretos++;
            contagem[tamanho][0]--; 
            contagem[tamanho][1]--; 
        }
    }

    printf("%d\n", pares_corretos);

    return 0;
}
