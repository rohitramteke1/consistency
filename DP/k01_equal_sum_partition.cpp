#include <iostream>
#include <numeric>
#include <cstring>
using namespace std;
// divide the array of equal sum participation

const int N = 1e3+10;
const int W = 1e5+10;
int dp[N][W];

bool subsetSum(int arr[], int sum, int n) {

// base condition
    if(sum == 0) return dp[n][sum] = true;
    if(n == 0 && sum > 0) return dp[n][sum] = false;

// memoise
    if(dp[n][sum] != -1) return dp[n][sum];

// choice diagram code
    if(arr[n-1] <= sum) {
        return dp[n][sum] = subsetSum(arr, sum - arr[n-1], n-1) || subsetSum(arr, sum, n-1);
    }
    else // if(arr[n-1] > sum)
        return dp[n][sum] = subsetSum(arr, sum, n-1);
}

int subsetSumBottomUp(int arr[], int sum, int n) {
// initialisation
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = true;

    for (int j = 1; j < sum + 1; j++)
        dp[0][j] = false;
    
// recursive -> iterative
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];

            else if(arr[n-1] > j)
                dp[i][j] = dp[i-1][j];
        }
    }
    
// return ans
    return dp[n][sum];
}

bool knap(int arr[], int sum, int n) {

    if(sum == 0) return true;
    if(n == 0 && sum > 0) return false;

    if(arr[n-1] <= sum)
        return knap(arr, sum - arr[n-1], n-1) || knap(arr, sum, n-1);

    else
        return knap(arr, sum, n-1);

}

bool isEqualSumPartion(int arr[], int n) {
    int sum = accumulate(arr, arr + n, 0);

    if(sum & 1) return false; // if the sum is odd

    return subsetSumBottomUp(arr, sum/2, n);

}

int main()
{
    memset(dp, -1, sizeof(dp));

    int arr[] = {478, 757, 314, 471, 729, 100, 459, 618};
    int n = 8;
    // int sum = 22/2;
    // cout << subsetSum(arr, sum, n) << endl;
    // cout << subsetSumBottomUp(arr, sum, n) << endl;
    // cout << knap(arr, sum, n) << endl;

    // int sum = accumulate(arr, arr + n, 0);
    cout << isEqualSumPartion(arr, n) << endl;

    return 0;
}