// 01 Knapsack
// Top Down -> Real DP

#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 10;
const int W = 1e3 + 10;
int dp[N][W];

int knapsack(int wt[], int val[], int n, int w)
{
    if (n == 0 || w == 0)
        return 0;

    // memoize
    if (dp[n][w] != -1)
        return dp[n][w];

    if (wt[n - 1] <= w)
        return dp[n][w] = max(
                   val[n - 1] + knapsack(wt, val, n - 1, w - wt[n - 1]),
                   knapsack(wt, val, n - 1, w));

    // if (wt[n - 1] > w)
    else
        return dp[n][w] = knapsack(wt, val, n - 1, w);
}

int knapsackBottomUp(int wt[], int val[], int n, int w)
{
// base-condt -> initialise
    for (int i = 0; i < n+1; i++)
        dp[i][0] = 0;
    for (int j = 0; j < n+1; j++)
        dp[0][j] = 0;

// recursive -> iterative
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < w+1; j++)
        {
            if(wt[i] <= w) {
                dp[i][j] = max(
                    val[i-1] + dp[i-1][j - wt[i-1]],
                    dp[i-1][j]
                    );
            }
            else if(wt[i] > j) {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][w];
}

int main()
{
    int wt[] = {1, 2, 3, 4, 5, 6};
    int val[] = {6, 5, 4, 3, 2, 1};
    memset(dp, -1, sizeof(dp));

    cout << knapsackBottomUp(wt, val, 6, 10) << endl;

    return 0;
}