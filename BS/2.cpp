#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n-1;
    while(low<=high) {
        // int mid = (low + high)/2; int may be overflow in this case
        int mid = low + (high - low)/2;
        if(target == arr[mid]) {
            return mid;
        } else if(target > arr[mid]) {
            low = mid + 1;
        } else { // target < arr[mid]
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10};
    cout << binarySearch(arr, 11, 11) << endl;
    // cout << binary_search(arr, arr + 11, 10) << endl;
    
    return 0;
}