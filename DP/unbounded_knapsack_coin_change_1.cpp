// Unbounded knapsack
// * Coin change - 1

#include <bits/stdc++.h>
using namespace std;

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

// no of ways or count, asked to us -> then just do the '+' 
int main()
{
    int coins[] = {1, 2, 5};
    int sum = 11;
    int n = 3;

    cout << bottomUp(coins, sum, n) << endl;

    return 0;
}