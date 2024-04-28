#include <stdio.h>
#include <string.h>

// Função recursiva para mover os caracteres 'x' minúsculos para o final da string
void move_x(char *str, int idx, int x_idx) {
    // Caso base: quando chegamos ao final da string
    if (idx == strlen(str)) {
        if (x_idx < strlen(str)) {
            str[x_idx] = 'x'; // Realoca 'x' para o final
            move_x(str, idx, x_idx + 1); // Continua a mover 'x' para o final
        }
        return;
    }

    // Se o caractere atual não for 'x', copiamos para a nova posição
    if (str[idx] != 'x') {
        str[x_idx] = str[idx];
        move_x(str, idx + 1, x_idx + 1);
    } else {
        // Se o caractere atual for 'x', avançamos para o próximo caractere sem copiá-lo
        move_x(str, idx + 1, x_idx);
    }
}

int main() {
    char str[101]; // Considerando o máximo de 100 caracteres e um caractere nulo
    fgets(str, 101, stdin);

    // Remover quebra de linha, se presente
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    // Chama a função para mover os 'x' minúsculos para o final
    move_x(str, 0, 0);

    // Imprime a nova string
    printf("%s\n", str);

    return 0;
}
