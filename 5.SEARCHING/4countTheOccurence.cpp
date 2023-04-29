#include <bits/stdc++.h>
using namespace std;

class Solution{
    
    int firstCountOfZero(int arr[], int n) {
        
        int low = 0, high = n-1;
        int firstCount = -1;
        
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (arr[mid] == 0) {
                firstCount = mid;
                high = mid - 1;
            } else if (arr[mid] > 0) {
                low = mid + 1;
            } else
                high = mid - 1;
        }
        
        return firstCount;
    }
    
public:
    int countZeroes(int arr[], int n) {
        int index = firstCountOfZero(arr, n);
        if (index == -1)
            return 0;
        return n - index;
    }
};

int main()
{
    int arr[] = {1,2,6,5,4};
    
    return 0;
}