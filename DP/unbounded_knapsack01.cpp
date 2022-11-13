// Unbounded knapsack
// * Rod cutting
// * Coin change 1 (maximum no of ways)
// * Coin change 2 (minimum no of ways)
// * Maximum ribbon cut 

#include <bits/stdc++.h>
using namespace std;

int unbounded_knapsack(int wt[], int val[], int w, int n) {
    if(w == 0 || n == 0)
        return 0;
    
    if(wt[n-1] <= w) {
        return max(val[n-1] + unbounded_knapsack(wt, val, w - wt[n-1], n), unbounded_knapsack(wt, val, w, n-1) );
    }
    else {
        return unbounded_knapsack(wt, val, w, n-1);
    }
    
}

int knap(int wt[], int val[], int w, int n) {
    if(w == 0 || n == 0) return 0;

    if(wt[n-1] <= w)
        return 
        max(
            val[n-1] + knap(wt, val, w - wt[n-1], n),
            knap(wt, val, w, n-1)
        );
    else {
        return knap(wt, val, w, n-1);
    }
}

int unbound(int wt[], int val[], int w, int n) {

    vector< vector<int> > dp(n + 1, vector<int>(n + 1, -1));

    if(w==0 || n==0)
        return 0;
    
    if(wt[n-1] <= w) {
        return max(
                val[n-1] + unbound(wt, val, w - wt[n-1], n), 
                unbound(wt, val, w, n-1)
            );
    }
    else {
        return unbound(wt, val, w, n-1);
    }
}

// bottomUp unbounded knapsack
int bottomUp(int wt[], int val[], int w, int n) {

    vector< vector<int> > dp;
    for (int i = 0; i < n+1; i++)
    {
        vector<int> v;
        for (int j = 0; j < w+1; j++)
        {
            v.emplace_back(0);
        }
        dp.emplace_back(v);
        v.clear();
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max( val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j] );
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][w];
}

int main()
{
    vector<int> arr = {1,2,3,4};
    // unbounded_knapsack(arr, 10, 5);
    int length[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int price[] = {8,7,6,5,4,3,2,1};
    int n = 8;
    int w = 8;
    // cout << knapsack(wt, val, w, n) << endl;
    cout << "Bottom Up: " << bottomUp(length, price, w, n) << endl;
    cout << "Un Knapsack: " << knap(length, price, w, n) << endl;
    cout << "Recursive unbound" << unbound(length, price, w, n) << endl;
    
    

    return 0;
}