#include <bits/stdc++.h>
using namespace std;

// Kadanes Algorithm
// O(N) + O(1)
int maxSubArraySum(vector<int> &arr) {
    int maxSum = 0;
    int currSum = 0;
    
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if(currSum < 0)
            currSum = 0;
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

// Recursion Sandeep Jain Solution
int solve(vector<int> &arr) {
    int n = arr.size();
    int currSum = arr[0];
    int maxSum = INT_MIN;

    // 2 3 -8 7 -1 2 3
    for (int i = 1; i < n; i++)
    {
        currSum = max(currSum + arr[i], arr[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

// O(N^2) + O(1)
int brute(vector<int> &arr) {
    int n = arr.size();
    int maxSum = 0;
    // int minSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        // int minSum = max(arr[i], minSum);
        int currSum = 0;
        for (int j = i; j < n; j++)
            currSum += arr[j];
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main()
{
    vector<int> arr = {2,3,-8,7,-1,2,3};
    cout << solve(arr) << endl;
    return 0;
}