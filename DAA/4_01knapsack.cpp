#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int dp[N+1][N+1];

int knapsack(int wt[], int val[], int n, int w) {
    if(n == 0)
        return dp[n][w] = 0;
    if(dp[n][w] != -1)
        return dp[n][w];
    if(wt[n-1] <= w) {
        return dp[n][w] = max(
            val[n-1] + knapsack(wt, val, n-1, w - wt[n-1]),
            knapsack(wt, val, n-1, w)
        );
    }
    return dp[n][w] = knapsack(wt, val, n-1, w);
}

int main()
{
    int values[] = {1,2,3};
    int weight[] = {4,5,1};
    int n = 3;
    int wt = 4;
    memset(dp, -1, sizeof(dp));
    cout << knapsack(weight, values, n, wt) << endl;


    return 0;
}