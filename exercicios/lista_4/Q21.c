#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x, y;
} Position;

int min(int a, int b) {
    return a < b ? a : b;
}

int abs(int x) {
    return x < 0 ? -x : x;
}

int isValid(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int knightMoves(Position start, Position end) {
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int visited[8][8] = {0};
    Position queue[64];
    int front = 0, rear = 0;
    queue[rear++] = start;
    visited[start.x][start.y] = 1;

    while (front < rear) {
        Position current = queue[front++];
        if (current.x == end.x && current.y == end.y) {
            return visited[current.x][current.y] - 1;
        }
        for (int i = 0; i < 8; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];
            if (isValid(newX, newY) && !visited[newX][newY]) {
                visited[newX][newY] = visited[current.x][current.y] + 1;
                queue[rear++] = (Position){newX, newY};
            }
        }
    }
    return -1; // No path found
}

int main() {
    char square1[3], square2[3];
    while (scanf("%s %s", square1, square2) != EOF) {
        Position start = {(int)(square1[1] - '1'), (int)(square1[0] - 'a')};
        Position end = {(int)(square2[1] - '1'), (int)(square2[0] - 'a')};
        int moves = knightMoves(start, end);
        printf("To get from %s to %s takes %d knight moves.\n", square1, square2, moves);
    }
    return 0;
}
