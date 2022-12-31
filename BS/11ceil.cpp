#include <bits/stdc++.h>
using namespace std;

// ceil : smallest element which is greater than or equal to x
int findCeil(vector<int> arr, int n, int x) {
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
    // 0  1  2
    //       8
    //       ↑
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] == x) {
            return mid;
        }
        else if(arr[mid] > x ) { 
            // it means that the this element can become the possible candidate of ceil
            ans = mid;
            high = mid - 1;
        }
        else if(arr[mid] < x) {
            low = mid + 1;
        }
    }

    return arr[ans];
}

int main()
{
    vector<int> arr = {1,2,8,10,11,12,19};
    // cout << findCeil(arr, arr.size(), 5) << endl;
    auto i = find(arr.begin(), arr.end(), 0) - arr.begin();
    cout << i << endl;
    return 0;
}