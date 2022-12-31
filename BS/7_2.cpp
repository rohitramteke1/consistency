// 154 Leetcode
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr) {
    int N = arr.size();
    int low = 0;
    int high = N-1;
    while(low <= high) {

        int mid = low + (high-low)/2;
        int prev = (mid - 1 + N) % N;
        int next = (mid + 1) % N;

        cout << arr[mid] << endl;
        // 0 1 2 3
        // 3 3 3 1
        if(arr[mid] < arr[prev] && arr[mid] < arr[next]) return arr[mid];
        // if(arr[low] < arr[high]) return arr[mid];
        // it means that the left arr is sorted so the min ele. must be present in the right subarray
        if(arr[low] <= arr[mid]) low = mid + 1;
        else if(arr[high] >= arr[mid]) high = mid - 1;
    }

    return -1;
}

int main()
{
    vector<int> arr = {3,3,3,1};

    cout << binarySearch(arr) << endl;
    
    return 0;
}


