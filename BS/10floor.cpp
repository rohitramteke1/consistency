#include <bits/stdc++.h>
using namespace std;

// floor: largest element which is smaller than or equal to x
int findFloor(vector<int> arr, int n, int x) {
    int ans = -1;
    int low = 0;
    int high = n-1;
    
    // x = 5
    // 0  1  2   3   4   5   6
    // 1  2  8  10  11  12  19
    //           ↑

    // x = 5
    // 0  1  2
    // 1  2  8 
    //    ↑

    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] == x) {
            return mid;
        }
        else if(x < arr[mid]) {
            high = mid - 1;
        }
        else if(x > arr[mid]) {
            ans = mid;
            low = mid + 1;
        }
    }

    return arr[ans];
}

int main()
{
    vector<int> arr = {1,2,8,10,11,12,19};
    cout << findFloor(arr, arr.size(), 5) << endl;
    return 0;
}