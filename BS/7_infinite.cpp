#include <bits/stdc++.h>
using namespace std;

int searchInfinite(vector<int>& arr, int key) {
    int high = 1;
    int low = 0;
    while(arr[high] <= key) {
        low = high;
        high = high * 2;
    }
    return binarySearch(arr, low, high, key);
}

int binarySearch(vector<int>& arr, int l, int h, int key) {
    while(l <= h) {
        int mid = l + (h - l)/2;
        if(arr[mid] == key) {
            return mid;
        }
        else if(key > arr[mid]) {
            l = mid + 1; // it means mid is present on right side
        }
        else {
            h = mid - 1; // it means mid is present on left side
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34};
    
    cout << binarySearch(arr, 0, high, key) << endl;
   
    return 0;
}