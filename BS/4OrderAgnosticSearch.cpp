#include <bits/stdc++.h>
using namespace std;

int binarySearchAsc(int arr[], int n, int target) {
    int low = 0;
    int high = n-1;

    while(low<=high) 
    {
        int mid = low + (high - low)/2;
        if(target == arr[mid])
            return mid;
        else if(target > arr[mid])
            low = mid + 1;
        else // target < arr[mid]
            high = mid - 1;
    }
    return -1;
}
int binarySearchDesc(int arr[], int n, int target) {
    int low = 0;
    int high = n-1;

    while(low<=high) 
    {
        int mid = low + (high - low)/2;
        if(target == arr[mid])
            return mid;
        else if(target < arr[mid])
            low = mid + 1;
        else // target > arr[mid]
            high = mid - 1;
    }
    return -1;
}

int binarySearch(int arr[], int n, int target) {
    if(n==1 or n==0)
        if(n==1) 
            return target == arr[0] ? 0 : -1;
        else 
            return -1;

    bool whichOrder = arr[0] < arr[1];
    if(whichOrder)
        return binarySearchAsc(arr, n, target);
    return binarySearchDesc(arr, n, target);
}


int main()
{
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10};
    // cout << binarySearchAsc(arr, 11, 9) << endl;
    // cout << binarySearchDesc(arr, 11, 9) << endl;
    cout << binarySearch(arr, 11, 9) << endl;
    
    return 0;
}