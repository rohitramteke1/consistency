// 01 Knapsack

#include <bits/stdc++.h>
using namespace std;

const int N = 1e2+10;
const int W = 1e3+10;
int dp[N][W];

int knapsack(int wt[], int val[], int n, int w)
{
    if (n == 0 || w == 0)
        return 0;

    // memoize
    if(dp[n][w] != -1) 
        return dp[n][w];

    if (wt[n - 1] <= w)
        return dp[n][w] = max(
            val[n - 1] + knapsack(wt, val, n - 1, w - wt[n - 1]),
            knapsack(wt, val, n - 1, w));

    // if (wt[n - 1] > w)
    else
        return dp[n][w] = knapsack(wt, val, n - 1, w);

}

int main()
{
    int wt[] = {1,2,3,4,5,6};
    int val[] = {6,5,4,3,2,1};
    memset(dp, -1, sizeof(dp));

    // recursive call -> no dp
    // recursive call + table(matrix -> dp[n][w] )
    // only table(dp[n][w])
    cout << knapsack(wt, val, 6, 10) << endl ;

    return 0;
}