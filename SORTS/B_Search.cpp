#include <bits/stdc++.h>
using namespace std;

int BSearch(int arr[], int k, int n) {
    int low = 0;
    int high = n-1;
    int mid = (high + low)/2;

    while(high >= low) {
        mid = (low + high + 1)/2;
        if(arr[mid] == k) return mid;
        else if(k < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }

    return -1;
}

int BS(int arr[], int k, int low, int high) {

    if(high < low) return -1;
    int mid = (high + low)/2;
    if(arr[mid] == k) return mid;
    else if(k < arr[mid]) return BS(arr, k, low,mid - 1);
    else return BS(arr, k, mid + 1, high);
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;

    cout << BSearch(arr, k, n) << endl;
    cout << BS(arr, k, 0, n-1) << endl;
    return 0;
}