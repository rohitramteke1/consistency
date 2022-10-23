// Minimm SubArray Sum CodeStudio
#include <iostream>
using namespace std;

long minSubarraySum(int arr[], int n, int k) 
{
    // Write your code here
    long curSum = 0;
    long minSum = INT_MAX;
    for (int i = 0; i < k; i++)
        curSum += arr[i];

    if (n==k) return curSum;
    // cout << curSum << ' '<< endl ;
    int i;
    for (i = 1; i <= n-k; i++)
    {      
        curSum = curSum + arr[i+k-1] - arr[i-1];
        if (curSum < minSum)
            minSum = curSum;

        // cout << curSum << ' ' << minSum << ' ' << endl ; 
    }
    return minSum;
}

int main()
{
    // int arr[] = {1, -4, 2, 10, -2, 3, 1, 0};
    // cout << minSubarraySum(arr, 8, 4);
    int n; cin >> n;
    int k; cin >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> arr[i];
    }
    cout << minSubarraySum(arr, n, k);
    
    return 0;
}