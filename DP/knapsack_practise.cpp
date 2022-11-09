#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e3+10;
const int W = 1e5+10;
int dp[N][W];


int knapsack(int wt[], int val[], int w, int n) {

    if(n==0 || w==0)
        return 0;
    
    else if(wt[n-1] <= w)
        return max(
            val[n-1] + knapsack(wt, val, w - wt[n-1], n-1),
            knapsack(wt, val, w, n-1)
        );

    else // if(wt[n-1] > w)
        return knapsack(wt, val, w, n-1);

}

int knap_dp(int wt[], int val[], int w, int n) {

    if(n==0 || w==0)
        return dp[n][w] = 0;
    
    else if(wt[n-1] <= w)
        return dp[n][w] = max(
            val[n-1] + knapsack(wt, val, w - wt[n-1], n-1),
            knapsack(wt, val, w, n-1)
        );

    else // if(wt[n-1] > w)
        return dp[n][w] = knapsack(wt, val, w, n-1);
}

int knap_bottomUp(int wt[], int val[], int w, int n) {
    
    for (int i = 1; i < w+1; i++)
        dp[0][i] = 0;
    
    for (int i = 0; i < n+1; i++)
        dp[i][0] = 0;
    
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < w+1; j++)
        {
            if (wt[i-1] <= j) {
                dp[i][j] = max(
                    val[i-1] + dp[i-1][j - wt[i-1]],
                    dp[i-1][j]
                );
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][w];
}

int main()
{
    int val[] = {1,2,3,4,5,6};
    int wt[] = {6,5,4,3,2,1};
    int n = 6;
    int w = 10;
    cout << knapsack(wt, val, w, n) << endl;
    
    memset(dp, -1, sizeof(dp));
    cout << knap_dp(wt, val, w, n) << endl;

    cout << knap_bottomUp(wt, val, w, n) << endl;


    return 0;
}