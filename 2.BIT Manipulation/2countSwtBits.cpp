#include <bits/stdc++.h>
using namespace std;

int table[256];

void initialise() {
    table[0] = 0;
    for (int i = 0; i < 256; i++)
        table[i] = (i & 1) + table[i/2];
}

int optimised(int n) {
    initialise();
    int res = 0;
    res += table[n & 0xFF];
    n = n >> 8;
    res += table[n & 0xFF];
    n = n >> 8;
    res += table[n & 0xFF];
    n = n >> 8;
    res += table[n & 0xFF];
    n = n >> 8;
    return res;
}

// Brian Kerninger Algo
// TC: O(set-bits-count)
int better(int n) {
    int res = 0;
    while(n) {
        n = n & (n-1);
        res++;
    }
    return res;
}

int bfs(int n) {
    int res = 0;
    while(n) {
        res = res + (n & 1);
        n = n >> 1;
    }
    return res;
}

int main()
{
    int n = 13;
    cout << bfs(n) << endl;
    cout << better(n) << endl;
    cout << optimised(13) << endl;
    return 0;
}