#include <bits/stdc++.h>
using namespace std;

int ropeCutting(int n, int x, int y, int z, vector<int> &dp) {
    if(n == 0)
        return 0;
    if(n < 0)
        return INT_MIN;
    if(dp[n] != -1)
        return dp[n];

    int a = 1 + ropeCutting(n - x, x, y, z, dp);
    int b = 1 + ropeCutting(n - y, x, y, z, dp);
    int c = 1 + ropeCutting(n - z, x, y, z, dp);
    return dp[n] = max({a, b, c});
}

// Error not giving the expected output
int bottomUp(int n, int x, int y, int z) {
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;
    for(int i=1; i<=n; i++) {
        int a = 0, b = 0, c = 0;
        if(i - x >= 0)
            a = max(dp[i], dp[i-x] + 1);
        if(i - y >= 0)
            b = max(dp[i], dp[i-y] + 1);
        if(i - z >= 0)
            c = max(dp[i], dp[i-z] + 1);
        dp[i] = max({a,b,c});
    }
    return dp[n];
}

int main()
{
    int n = 5;
    int x = 5, y = 2, z = 1;

    vector<int> dp(n + 1, -1);
    cout << ropeCutting(n, x, y, z, dp) << endl;
    cout << bottomUp(n, x, y, z) << endl;

    return 0;
}