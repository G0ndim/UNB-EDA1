#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char text[MAX_SIZE];
    struct Node *prev;
} Node;

Node *top = NULL;

void push(char *text) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erro de alocação de memória\n");
        exit(1);
    }
    strcpy(newNode->text, text);
    newNode->prev = top;
    top = newNode;
}

char* pop() {
    if (top == NULL) {
        return "NULL";
    }
    Node *temp = top;
    top = top->prev;
    char *text = strdup(temp->text);
    free(temp);
    return text;
}

int main() {
    char command[MAX_SIZE];
    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "desfazer") == 0) {
            printf("%s\n", pop());
        } else {
            char text[MAX_SIZE];
            scanf(" %[^\n]", text);
            push(text);
        }
    }
    return 0;
}
