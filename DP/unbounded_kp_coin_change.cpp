#include <bits/stdc++.h>
using namespace std;

// we've given an array of coins and sum and we're going to
// the pick up the coins in such way that the sum of all coins is
// equal to given sum and we've to find that the no of ways to do this. 
// and return the no of ways.

int unbounded_knapsack(int wt[], int val[], int w, int n) {
    if(w == 0 || n == 0)
        return 0;
    
    if(wt[n-1] <= w) {
        return max(
            val[n-1] + unbounded_knapsack(wt, val, w - wt[n-1], n), 
            unbounded_knapsack(wt, val, w, n-1)
        );
    }
    else {
        return unbounded_knapsack(wt, val, w, n-1);
    }
}

int coin_change(int coins[], int sum, int n) {

    if(sum == 0) // n >= 0 also covered here
        return 1;
    if(n==0 && sum > 0)
        return 0;

    if(coins[n-1] <= sum) {
        return 
        (coin_change(coins, sum - coins[n-1], n) + coin_change(coins, sum, n-1));
    }
    else {
        return coin_change(coins, sum, n-1);
    }
}

int coin_change_DP(int coins[], int sum, int n, vector< vector<int> > &dp) {

    if(sum == 0) // n >= 0 also covered here
        return dp[n][sum] = 1;
    if(n==0 && sum > 0)
        return dp[n][sum] = 0;
    
    // memoise
    if(dp[n][sum] != -1) {
        return dp[n][sum];
    }

    if(coins[n-1] <= sum) {
        return 
        dp[n][sum] =
            coin_change(coins, sum - coins[n-1], n) + 
            coin_change(coins, sum, n-1);
    }
    else {
        return dp[n][sum] = coin_change(coins, sum, n-1);
    }
}

int bottom_up(int coins[], int sum, int n, vector< vector<int> > &dp) {

    for (int i = 0; i < n+1; i++)
        dp[i][0] = 1;
    for (int j = 1; j < sum+1; j++)
        dp[0][j] = 0;

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            if(coins[i-1] <= j)
                dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 5;
    // 1 1 1 1 1 
    // 1 1 1 2
    // 1 2 2
    // 1 1 3
    // 2 3
    // total -> 5 ways

    // brute force recursion
    cout << coin_change(arr, sum, n) << endl;

    // dp array
    // vector < vector<int> > dp(n + 1, vector<int>(sum + 1, -1));
    // cout << coin_change_DP(arr, sum, n, dp) << endl;
    
    // bottom up
    vector < vector<int> > dp(n + 1, vector<int>(sum + 1, 0));
    cout << bottom_up(arr, sum, n, dp) << endl;

    return 0;
}