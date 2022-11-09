// Count the number of subset that might have the sum equal to k 
// 01 knapsack problem 
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
const int W = 1e3+10;
int dp[N][W];

/* int knapsack(int wt[], int arr[], int w, int n) {
    if(n==0 || w==0) return 0;

    if(wt[n-1] <= w)
        return max(arr[n-1] + knapsack(wt, arr, w-wt[n-1], n-1), 
            knapsack(wt, arr, w, n-1));

    else
        return knapsack(wt, arr, w, n-1);
} */

/* int knapsack(int wt[], int sum, int n) {
    if(sum==0) return true;
    if(n == 0 && sum > 0) return false;

    if(wt[n-1] <= sum)
        return knapsack(wt, sum - wt[n-1], n-1) ||  
            knapsack(wt, sum, n-1);

    else
        return knapsack(wt, sum, n-1);
} */

int knapsack(int wt[], int sum, int n) {
    if(sum==0) return true;
    if(n == 0 && sum > 0) return false;

    if(wt[n-1] <= sum)
        return knapsack(wt, sum - wt[n-1], n-1) +  
            knapsack(wt, sum, n-1);

    else
        return knapsack(wt, sum, n-1);
}

int main()
{
    // int arr[] = {6,5,4,3,2,1};
    // int wt[] = {1,2,3,4,5,6};
    // int size = 6;
    // int w = 10;
    // memset(dp, -1, sizeof(dp));
    // cout << knapsack(wt, arr, w, size) << endl;

    // int wt[] = {1,2,3,4,5,6};
    // int size = 6;
    // int sum = 22;
    // cout << knapsack(wt, sum, size) << endl;


    int wt[] = {2,3,5,6,8,10};
    int size = 6;
    int sum = 10;
    cout << knapsack(wt, sum, size) << endl;


    

    return 0;
}