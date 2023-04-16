#include <bits/stdc++.h>
using namespace std;

// MY KADANES SOLUTION
int kadanes(vector<int> &arr) {
    int n = arr.size();
    int minSum = 0;
    int currSum = 0;
    // 5 4 -5 1 8
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if(currSum < 0) {
            currSum = 0;
        }
        minSum = max(minSum, currSum);
    }
    
    return minSum;
}

// CIRCULAR SUBARRAY SUM
// O(N ^ 2) + O(1)
int brute(vector<int> &arr) {
    int n = arr.size();
    int maxSum = 0;

    for (int i = 0; i < n; i++)
    {
        int currSum = 0;
        int j = i;
        do {
            currSum += arr[j];
            if(currSum < 0)
                currSum = 0;
            maxSum = max(maxSum, currSum);
            j = (j+1)% n;
        } while(i != j);
    }
    
    return maxSum;
}

// GFG sandeep jain
// BETTER SOLUTION
// O(N) + O(1)
int gfg(vector<int> &arr) {
    int n = arr.size();
    int cs = arr[0];
    int ms = arr[0];
    for (int i = 1; i < n; i++)
    {
        cs = max(cs + arr[i], arr[i]);
        ms = max(ms, cs);
    }
    return ms;
}

int circularSubArraySum(vector<int> &arr) {
    int n = arr.size();
    int normal_sum = gfg(arr);

    // it means all the array elements are negative
    if(normal_sum <= 0)
        return normal_sum;

    int total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
        // change arr[i] sign to calculate the min_sum
        arr[i] = -arr[i];
    }
    int min_sum = gfg(arr);
    // max_sub_arr_sum -> total_sum - min_sub_arr_sum
    int circular_sum = total_sum + min_sum;
    return max(circular_sum, normal_sum);
}

// O(N) + O(1)
int min_kadanes(vector<int> &arr) {
    int n = arr.size();
    int minSum = arr[0];
    int currSum = arr[0];

    for (int i = 1; i < n; i++)
    {
        minSum = min(minSum, currSum);
        if(currSum > 0)
            currSum = 0;
        currSum += arr[i];
    }
    
    return min(minSum, currSum);
}

int max_kadanes(vector<int> &arr) {
    int n = arr.size();
    int maxSum = arr[0];
    int currSum = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxSum = max(maxSum, currSum);
        if(currSum < 0)
            currSum = 0;
        currSum += arr[i];
    }
    
    return max(currSum, maxSum);
}

int main()
{
    vector<int> arr = {5,4,-5,1,8};

    cout << circularSubArraySum(arr) << endl;
    
    return 0;
}