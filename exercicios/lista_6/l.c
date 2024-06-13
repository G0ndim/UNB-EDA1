#include <stdio.h>
#include <stdlib.h>

int find_house_index(int* houses, int N, int house_number) {
    for (int i = 0; i < N; i++) {
        if (houses[i] == house_number) {
            return i;
        }
    }
    return -1;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int* houses = (int*)malloc(N * sizeof(int));
    int* deliveries = (int*)malloc(M * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &houses[i]);
    }

    for (int i = 0; i < M; i++) {
        scanf("%d", &deliveries[i]);
    }

    int current_pos = 0;
    int time_spent = 0;

    for (int i = 0; i < M; i++) {
        int next_pos = find_house_index(houses, N, deliveries[i]);
        time_spent += abs(next_pos - current_pos);
        current_pos = next_pos;
    }

    printf("%d\n", time_spent);

    free(houses);
    free(deliveries);

    return 0;
}
