#include <bits/stdc++.h>
using namespace std;

int unbounded(int wt[], int val[], int w, int n) {

    if(n == 0 || w == 0) return 0;

    if(wt[n-1] <= w) {
        return max(
            val[n-1] + unbounded(wt, val, w - wt[n-1], n),
            unbounded(wt, val, w, n-1)
        );
    } else {
        return unbounded(wt, val, w, n-1);
    }
}

// bottomUp unbounded knapsack
int bottomUp(int coin[], int sum, int n) {

    vector< vector<int> > dp;
    for (int i = 0; i < n+1; i++)
    {
        vector<int> v;
        for (int j = 0; j < sum+1; j++)
        {
            if(j == 0)
                v.emplace_back(1);
            else
                v.emplace_back(0);
        }
        dp.emplace_back(v);
        v.clear();
    }    

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coin[i - 1] <= j)
                dp[i][j] = dp[i][j - coin[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][sum];
}


int coin_change2(int coins[], int sum, int n) {
    vector< vector<int> > dp(n+1, vector<int>(sum+1, 0));

    for (int j = 0; j < sum+1; j++)
        dp[0][j] = INT_MAX - 1;
    
    for (int i = 0; i < n+1; i++)
        dp[i][0] = 0;
    
    for (int j = 1; j < sum+1; j++)
    {
        if(j % coins[0] == 0)
            dp[1][j] = 1;
        else
            dp[1][j] = INT_MAX - 1;
    }
    

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coins[i - 1] <= j)
                dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    
    return dp[n][sum];
}

int main()
{
    int wt[] = {25, 10, 5};
    int w = 30;
    int n = 3;
    cout << coin_change2(wt, w, n) << endl;
    
    return 0;
}