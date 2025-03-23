#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int col;        
    int value;      
    struct Node *next;  
} Node;


typedef struct {
    Node **rows;    
    int m, n;       
} SparseMatrix;


Node* createNode(int col, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}


SparseMatrix* createSparseMatrix(int m, int n) {
    SparseMatrix *matrix = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    matrix->rows = (Node**)malloc(m * sizeof(Node*));
    for (int i = 0; i < m; i++) {
        matrix->rows[i] = NULL;
    }
    matrix->m = m;
    matrix->n = n;
    return matrix;
}


void addElement(SparseMatrix *matrix, int row, int col, int value) {
    Node *newNode = createNode(col, value);
    newNode->next = matrix->rows[row];
    matrix->rows[row] = newNode;
}


void freeSparseMatrix(SparseMatrix *matrix) {
    for (int i = 0; i < matrix->m; i++) {
        Node *current = matrix->rows[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(matrix->rows);
    free(matrix);
}


void multiplySparseMatrixVector(SparseMatrix *matrix, int *vector, int *result) {
    for (int i = 0; i < matrix->m; i++) {
        result[i] = 0;
        Node *current = matrix->rows[i];
        while (current != NULL) {
            result[i] += current->value * vector[current->col];
            current = current->next;
        }
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    SparseMatrix *matrix = createSparseMatrix(m, n);

    while (1) {
        int row, col, value;
        scanf("%d %d %d", &row, &col, &value);
        if (row == -1 && col == -1 && value == -1) {
            break;
        }
        addElement(matrix, row, col, value);
    }

    int *vector = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &vector[i]);
    }

    int *result = (int*)malloc(m * sizeof(int));
    multiplySparseMatrixVector(matrix, vector, result);


    for (int i = 0; i < m; i++) {
        printf("%d\n", result[i]);
    }

    free(vector);
    free(result);
    freeSparseMatrix(matrix);

    return 0;
}
