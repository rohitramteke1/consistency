// 01 Knapsack
// Top Down -> Real DP

#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 10;
const int S = 1e5 + 10;
int dp[N][S];

int knapsackBottomUp(int arr[], int sum, int n)
{
// base-condt -> initialise
    // size (n)
    // |
    // ↓
    //   sub-array-sum ---->
    //   0 1 2 3 4 5 6 ...
    // 0 T F F F F F F ...
    // 1 T x x x x x x ...
    // 2 T x x x x x x ...
    // 3 T x x x x x x ...
    // 4 T x x x x x x ...
    // ....

    for (int i = 0; i < n+1; i++)
        dp[i][0] = true;
    for (int j = 1; j < sum+1; j++)
        dp[0][j] = false;

    int i, j;
    for (i = 1; i < n+1; i++)
    {
        for (j = 1; j < sum+1; j++)
        {
            if(arr[i-1] <= j) {
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            }
            else if(arr[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}

bool knapsack(int arr[], int sum, int n)
{
    if (sum == 0) // n can be anything, it doesn't matter
        return dp[n][sum] = true;
    if (n == 0 && sum > 0)
        return dp[n][sum] = false;

    // memoise
    if(dp[n][sum] != -1) 
        return dp[n][sum];

    if(arr[n-1] <= sum) {
        return dp[n][sum] = knapsack(arr, sum - arr[n-1], n-1) || 
        knapsack(arr, sum, n-1);
    }
    if(arr[n-1] > sum) {
        return dp[n][sum] = knapsack(arr, sum, n-1);
    }
    return false;
}

bool subsetSum(int arr[],int sum, int n) {
    // if(sum == 0) return true;
    // if(sum > 0 && n == 0) return false;

    // if(arr[n-1] <= sum) {
    //     return subsetSum(arr, sum - arr[n-1], n-1) || subsetSum(arr, sum, n-1);
    // }
    // else// if(arr[n-1] > sum) 
    // {
    //     return subsetSum(arr, sum, n-1);
    // }

    for (int i = 0; i < n+1; i++)
        dp[i][0] = true;

    for (int i = 1; i < sum+1; i++)
        dp[0][i] = false;

    for (int i = 1; i < n+1; i++)
        for (int j = 1; j < sum+1; j++)
            dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];

    return dp[n][sum];
}

int main()
{
    int arr[] = {3, 34, 4, 12, 5, 2};
    int size = 6;
    int sum = 3;

    memset(dp, -1, sizeof(dp));
    // cout << knapsack(arr, sum, size) << endl;
    
    // cout << knapsackBottomUp(arr, sum, size) << endl;
    cout << subsetSum(arr, sum, size) << endl;
    
    return 0;
}