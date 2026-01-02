#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n = 5;
    // DFS BAŞLANGIÇ

void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}
    // BFS BAŞLANGIÇ

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    int visitedB[MAX] = {0};

    queue[rear++] = start;
    visitedB[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && !visitedB[i]) {
                queue[rear++] = i;
                visitedB[i] = 1;
            }
        }
    }
}

int main() {
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][3] = 1;
    graph[1][4] = 1;
    graph[2][4] = 1;


    DFS(0);

    printf("\n");


    BFS(0);

    return 0;
}
