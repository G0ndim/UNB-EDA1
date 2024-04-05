#include <stdio.h>

// Função recursiva para desenhar a régua inglesa de ordem n
void desenhar_regua(int n) {
    if (n == 0) {
        return;
    }
    
    // Desenhar segmento superior da régua
    desenhar_regua(n - 1);
    
    // Desenhar traços do ponto médio
    printf(".");
    for (int i = 0; i < n; i++) {
        printf("-");
    }
    printf("\n");
    
    // Desenhar segmento inferior da régua
    desenhar_regua(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    
    if (n >= 0) {
        desenhar_regua(n);
    } else {
        printf("O número deve ser não negativo.\n");
    }
    
    return 0;
}
