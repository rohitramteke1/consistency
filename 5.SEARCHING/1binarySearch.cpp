#include <bits/stdc++.h>
using namespace std;

// recursive O(logN) + O(H)
int binarySearchRecur(int arr[], int low, int high, int x) {
    int mid = low + (high - low)/2;
    if (arr[mid] == x)
        return mid;
    else if (arr[mid] > x)
        return binarySearchRecur(arr, low, mid - 1, x);
    else
        return binarySearchRecur(arr, mid + 1, high, x);
}

// iterative O(logN) + O(1)
int binarySearch(int *arr, int n, int x) {
    int low = 0, high = n-1;
    while (low <= high ){
        int mid = low + (high - low)/2;
        if (arr[mid] == x)
            return mid;
        else if ( arr[mid] > x) 
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,10,20,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << binarySearch(arr, n, 10) << endl;
    cout << binarySearchRecur(arr, 0, n-1, 10) << endl;
    
    return 0;
}