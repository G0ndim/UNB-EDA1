#include <stdio.h>

// Função recursiva para verificar se uma sequência é uma PA
int pa_recursiva(int *v, int primeiro, int ultimo) {
    // Caso base: Se o primeiro índice for maior ou igual ao último, então a sequência é uma PA
    if (primeiro >= ultimo) {
        return 1;
    }
    // Verificar se a soma do primeiro com o último elemento é igual à soma do segundo com o penúltimo
    if (v[primeiro] + v[ultimo] != v[primeiro + 1] + v[ultimo - 1]) {
        return 0; // Se as somas não forem iguais, não é uma PA
    }
    // Chamada recursiva para verificar o próximo par de elementos
    return pa_recursiva(v, primeiro + 1, ultimo - 1);
}
