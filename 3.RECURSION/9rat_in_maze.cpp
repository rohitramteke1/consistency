#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, vector< vector<int> > &maze, 
    vector<vector<int> > &visited) {
    
    bool isInRange = (x >= 0 && x < n && y >= 0 && y < n);

    return isInRange && !visited[x][y] && maze[x][y];
    // return isInRange && (visited[x][y] == 0) && (maze[x][y] == 1);
}

void solve(int x, int y, int n, string path, vector< vector<int> > &maze, 
    vector<vector<int> > &visited) {
    
    // base case
    if(x == n-1 && y == n-1) {
        cout << path << endl;
        return;
    }

    // move D | L | R | U
    visited[x][y] = 1;

    // move down
    if( isSafe(x + 1, y, n, maze, visited) ) {
        path.push_back('D');
        solve(x + 1, y, n, path, maze, visited);
        path.pop_back();
    }

    // move left
    if( isSafe(x, y - 1, n, maze, visited) ) {
        path.push_back('L');
        solve(x, y - 1, n, path, maze, visited);
        path.pop_back();
    }

    // move right
    if( isSafe(x, y + 1, n, maze, visited) ) {
        path.push_back('R');
        solve(x, y + 1, n, path, maze, visited);
        path.pop_back();
    }

    // move up
    if( isSafe(x - 1, y, n, maze, visited) ) {
        path.push_back('U');
        solve(x - 1, y, n, path, maze, visited);
        path.pop_back();
    }

    visited[x][y] = 0;
}

int main()
{
    vector<vector<int>> maze = { {1, 0, 0, 0},
                                 {1, 1, 0, 1},
                                 {1, 1, 0, 0},
                                 {0, 1, 1, 1} };

    // not possible
    if(m[0][0] == 0)
        return 0;


    int n = maze.size();
    string path = "";

    vector< vector<int> > visited (n , vector<int> (n, 0));
    solve(0, 0, n, path, maze, visited);

    return 0;
}