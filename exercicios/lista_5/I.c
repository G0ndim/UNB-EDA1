#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int length;
    char character;
    int position;
} Sequence;

int compare(const void *a, const void *b) {
    Sequence *seq1 = (Sequence *)a;
    Sequence *seq2 = (Sequence *)b;
    
    if (seq1->length != seq2->length) {
        return seq2->length - seq1->length;
    } else {
        return seq1->position - seq2->position;
    }
}

int main() {
    char input[100001];
    scanf("%s", input);
    
    int len = strlen(input);
    
    Sequence sequences[len];
    int seq_count = 0;
    
    int current_length = 1;
    char current_char = input[0];
    int current_position = 0;
    
    for (int i = 1; i < len; i++) {
        if (input[i] == current_char) {
            current_length++;
        } else {
            sequences[seq_count].length = current_length;
            sequences[seq_count].character = current_char;
            sequences[seq_count].position = current_position;
            seq_count++;
            
            current_char = input[i];
            current_length = 1;
            current_position = i;
        }
    }
    
    sequences[seq_count].length = current_length;
    sequences[seq_count].character = current_char;
    sequences[seq_count].position = current_position;
    seq_count++;
    
    qsort(sequences, seq_count, sizeof(Sequence), compare);
    
    for (int i = 0; i < seq_count; i++) {
        printf("%d %c %d\n", sequences[i].length, sequences[i].character, sequences[i].position);
    }
    
    return 0;
}
