#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findMin(int arr[], int n){
        int low = 0;
        int high = n-1;
        while (low < high) {
            if (arr[low] <= arr[high])
                return arr[low];

            int mid = low + (high - low ) / 2;

            if (arr[mid] <= arr[ ( mid + 1 ) % n] and arr[mid] <= arr[(mid - 1 + n) % n])
                return mid;
            // left half is sorted, if it was rotated then the first condition, 
            // should have become true...
            // it means that the min element is on right side 
            if (arr[mid] > arr[low]) 
                low = mid + 1;
            else if (arr[high] > arr[mid])
                high = mid - 1;
        }
        return -1;
    }
};

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 5, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    Solution s;
    cout << s.findMin(arr, n) << endl ;

    return 0;
}