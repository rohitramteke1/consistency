#include <bits/stdc++.h>
using namespace std;


// Peak Elemenet
int binarySearch(int *arr, int n) {
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        int next = (mid + 1) % n;
        int prev = (mid - 1 + n)%n;
        if (arr[mid] >= arr[prev] && arr[mid] >= arr[high] )
            return mid;
        else if (arr[mid] >= arr[low])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Bitonic Element
int findMaximum(int arr[], int n) {
    // code here
    int low = 0, high = n-1;
    int ans = -1;
        
    while (low <= high) {
        int mid = low + (high - low)/2;
        int prev = (mid - 1);
        int next = (mid + 1);
        if ( ( mid == 0 or arr[mid] >= arr[prev] )  && (mid == n-1 or arr[mid] >= arr[next])  ) {
            ans = max(ans, arr[mid]);
        } 
        if (arr[mid] > arr[prev]) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    return ans;
}

// Brute Force Solution
int peakElemenet(int *arr, int n) {
    int peak = max(arr[0], arr[n-1]);
    for (int i = 1; i < n-1; i++)
    {
        if (arr[i] >= arr[i-1] && arr[i] >= arr[i+1]) {
            peak = max(peak, arr[i]);
        }
    }
    
    return peak;
}

int main()
{
    int arr[] = {1,2,6,5,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << peakElemenet(arr, n) << endl;
    cout << binarySearch(arr, n) << endl;

    return 0;
}