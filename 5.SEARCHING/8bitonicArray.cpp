#include <bits/stdc++.h>
using namespace std;

// Bitonic Element
int findMaximum(int arr[], int n) {

    int low = 0, high = n-1;
    int ans = -1;
        
    while (low <= high) {
        int mid = low + (high - low)/2;
        int prev = (mid - 1);
        int next = (mid + 1);
        if ( ( mid == 0 or arr[mid] >= arr[prev] )  && (mid == n-1 or arr[mid] >= arr[next])  ) {
            ans = max(ans, arr[mid]);
        } 
        if (prev >= 0 and arr[mid] > arr[prev]) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{   
    // same as peak element but, now we've to return the max peak element
    int arr[] = {1,2,6,5,4};
    // int arr[] = {3,5,3,2,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << findMaximum(arr, n) << endl;

    return 0;
}