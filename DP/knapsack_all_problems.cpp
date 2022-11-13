#include <bits/stdc++.h>
using namespace std;

int knapsack01(int wt[], int val[], int w, int n) {
    if(n == 0 || w == 0) 
    return 0;

    if(wt[n-1] <= w) {
        return max(val[n-1] + knapsack01(wt, val, w - wt[n-1], n-1), knapsack01(wt, val, w, n-1)); 
    }
    else {
        return knapsack01(wt, val, w, n-1);
    }
}

int subsetSum(int arr[], int sum, int n) {
    
    if(sum == 0)
        return true;

    if(sum > 0 && n == 0)
        return false;
    
    if(arr[n-1] <= sum) {
        return subsetSum(arr, sum - arr[n-1], n-1) || subsetSum(arr, sum, n-1);
    }
    else {
        return subsetSum(arr, sum, n-1);
    }

}

int equalSumPartiton(int arr[], int ep_sum, int n) {
    // if sum is odd then, not possible
    if(ep_sum & 1) return -1;
    // if it's even then do the ops.
    return subsetSum(arr, ep_sum/2, n);
}

int count_no_of_subset_with_given_sum(int arr[], int sum, int n) {
    if(sum == 0)
        return true;

    if(sum > 0 && n == 0)
        return false;
    
    if(arr[n-1] <= sum) {
        return subsetSum(arr, sum - arr[n-1], n-1) + subsetSum(arr, sum, n-1);
    }
    else {
        return subsetSum(arr, sum, n-1);
    }
}

int minimumSubsetSumDiff(int arr[], int sum, int n) {

    vector< vector<int> > dp;
    
    // TC: O(2 * N * SUM + SUM ) ~= O(N * SUM)
    // SC: O(N * SUM + SUM + 1 ) ~= O(N * SUM)

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

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            if(arr[i-1] <= j) {
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    int mn = INT_MAX;
    for (int i = 0; i < sum+1; i++)
    {
        // s2 - s1 = diff <- (min)
        // sum - s1 - s1 = diff <- (min)
        // sum - 2 * s1 = diff <- (min)
        if(dp[n][i])
        {
            mn = min(mn, abs(sum - 2 * i));
        }
    }
    return mn;
}

int targetSum(int arr[], int target, int n) {
    int sum = accumulate(arr, arr + n, 0);
    int s1 = (sum + target)/2;
    return count_no_of_subset_with_given_sum(arr, s1, n);
}

int main()
{
    int wt[] = {1,2,3,4,5};
    int val[] = {5,4,3,2,1};

    int n = 6;
    int w = 10;
    cout << "Knapsack: " << knapsack01(wt, val, w, n) << endl;
    cout << "Subset sum: " << subsetSum(wt, w, n) << endl;
    
    int arr[] = {1,2,3,4};
    n = 4;
    int sum = accumulate(arr, arr + n, 0);
    cout << "Equal sum partiton: " << equalSumPartiton(arr, sum, 4) << endl;
    
    n = 4;
    sum = 11;
    cout << "Count no of subset with given sum: " << count_no_of_subset_with_given_sum(arr, sum, n) << endl;

    int arr2[] = {1,2,3,4,5,5};
    n = 6;
    sum = accumulate(arr2, arr2 + n, 0);
    cout << "Minimum subset difference: " << minimumSubsetSumDiff(arr2, sum, n) << endl;
    
    int arr3[] = {4,1,2,3};
    n = 4;
    int target = 2;
    cout << "Target sum: " << targetSum(arr2, target, n) << endl;
    
    
    return 0;
}