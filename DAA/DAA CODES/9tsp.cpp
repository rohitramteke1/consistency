#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int N = 4;  // Number of cities

int graph[N][N] = {{0, 10, 15, 20},
                   {10, 0, 35, 25},
                   {15, 35, 0, 30},
                   {20, 25, 30, 0}};  // Example graph

vector<int> visited(N, 0);  // Keep track of visited cities
vector<int> path(N, 0);  // Store the current path
vector<int> min_path(N, 0);  // Store the minimum path
int min_cost = numeric_limits<int>::max();  // Initialize minimum cost

void tsp(int city, int cost, int depth) {
    if (depth == N && cost < min_cost) {  // Base case: all cities visited
        min_cost = cost;
        min_path = path;
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
    cout << "Minimum cost: " << min_cost << endl;
    cout << "Minimum path: ";
    for (int i = 0; i < N; i++) {
        cout << min_path[i] << " ";
    }
    cout << endl;
    return 0;
}
