#include <bits/stdc++.h>
using namespace std;
int rangeSum(int arr[], int a, int b) {
    int res;
    while(a<=b) {
        res += arr[a++];
    }
    return res;
}
int minSubarraySum(int arr[], int n, int k) 
{
    int i = 0;
    int j = k;
    int minSum = INT_MAX;
    int curSum = 0;
    for (int i = 0, j = k-1; i < n-(k-1); i++,j++)
    {
        // cout << "i:" << i << ' ' << "j:" << j << endl ;
        curSum = rangeSum(arr, i, j);
        if(curSum < minSum) {
            minSum = curSum;
        }
    }
    return minSum;
}

int main()
{
    int arr[] = {0,1,1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << minSubarraySum(arr, n, 3) << endl ;
    return 0;
}