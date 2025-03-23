#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int code;
    char keyword[16];
} Instruction;

char* binary_search(Instruction instructions[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (instructions[mid].code == target) {
            return instructions[mid].keyword;
        } else if (instructions[mid].code < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return "undefined";
}

int compare(const void *a, const void *b) {
    return ((Instruction *)a)->code - ((Instruction *)b)->code;
}

int main() {
    int n;
    
    scanf("%d", &n);

    Instruction instructions[10000];
    
    for (int i = 0; i < n; i++) {
        scanf("%d %s", &instructions[i].code, instructions[i].keyword);
    }
    
    qsort(instructions, n, sizeof(Instruction), compare);

    int query;

    while (scanf("%d", &query) != EOF) {
        printf("%s\n", binary_search(instructions, n, query));
    }

    return 0;
}
