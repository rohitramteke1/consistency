// Unbounded knapsack
// * Rod cutting

#include <bits/stdc++.h>
using namespace std;

// bottomUp unbounded knapsack
// n -> array len
// w -> maximum rod length i.e. capacity of knapsack

int bottomUp(int wt[], int val[], int w, int n) {

    vector< vector<int> > dp;
    for (int i = 0; i < n+1; i++)
    {
        vector<int> v;
        for (int j = 0; j < w+1; j++)
            v.emplace_back(0);

        dp.emplace_back(v);
        v.clear();
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++) // rod len or capacity of knapsack
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max( val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][w];
}

int rod_cutting(int length[], int price[], int len, int n) {
    if(len == 0 || n == 0)
        return 0;
    
    if(length[n-1] <= len) {
        return
        max(
            price[n-1] + rod_cutting(length, price, len - length[n-1], n),
            rod_cutting(length, price, len, n-1)
        );
    } 
    else {
        return rod_cutting(length, price, len, n-1);
    }
}

int rod(int length[], int price[], int len, int n) {
    if(len == 0)
        return 0;
    if(n == 0)
        return 0;

    if(length[n-1] <= len) {
        return 
        max(
            price[n-1] + rod(length, price, len - length[n-1], n-1),
            rod(length, price, len, n-1)
        );
    }
    else {
        return rod(length, price, len, n-1);
    }
}

int main()
{
// we've to maximise the profit here,

    // vector<int> arr = {1,2,3,4};
    // unbounded_knapsack(arr, 10, 5);
    int lenght[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20}; // this is our profit
    int len = 8; // lenght of rod i.e. capacity of knapsack
    int n = 8; // arr length

    cout << "Bottom Up: " << bottomUp(lenght, price, len, n) << endl;
    cout << "Rod Cutting: " << rod_cutting(lenght, price, len, n) << endl;
    cout << "Rod: " << rod(lenght, price, len, n) << endl;

    return 0;
}