#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 4  // Number of cities

int graph[N][N] = {{0, 10, 15, 20},
                   {10, 0, 35, 25},
                   {15, 35, 0, 30},
                   {20, 25, 30, 0}};  // Example graph

int visited[N] = {0};  // Keep track of visited cities
int path[N] = {0};  // Store the current path
int min_path[N] = {0};  // Store the minimum path
int min_cost = INT_MAX;  // Initialize minimum cost

void tsp(int city, int cost, int depth) {
    if (depth == N && cost < min_cost) {  // Base case: all cities visited
        min_cost = cost;
        for (int i = 0; i < N; i++) {
            min_path[i] = path[i];
        }
    } else {
        for (int i = 0; i < N; i++) {
            if (visited[i] == 0) {  // Visit an unvisited city
                visited[i] = 1;
                path[depth] = i;
                tsp(i, cost + graph[city][i], depth + 1);  // Recurse
                visited[i] = 0;  // Backtrack
            }
        }
    }
}

int main() {
    visited[0] = 1;  // Start from city 0
    tsp(0, 0, 1);
    printf("Minimum cost: %d\n", min_cost);
    printf("Minimum path: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", min_path[i]);
    }
    return 0;
}
