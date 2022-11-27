#include <bits/stdc++.h>
using namespace std;

// This is the Question from Matrix Chain Multiplication

int dp[10][10];

int MatrixChainOrder(int arr[], int i, int j) {
    if(i >= j) 
        return dp[i][j] = 0;
    if(dp[i][j] != -1) 
        return dp[i][j];

    int mn = INT_MAX;
    for (int k = i; k <= j-1; k++)
    {
        int temp = MatrixChainOrder(arr, i, k) + MatrixChainOrder(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        dp[i][j] = mn = min(mn, temp);
    }
    return dp[i][j] = mn;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 3 };
    int N = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof(dp));
    // Function call
    cout << "Minimum number of multiplications is " 
         << MatrixChainOrder(arr, 1, N - 1);

    // for (auto &&i : dp)
    // {
    //     for (auto &&j : i)
    //     {
    //         cout << setw(2) << j << ' ';
    //     }
    //     cout << endl;
    // }
    
    
    return 0;
}