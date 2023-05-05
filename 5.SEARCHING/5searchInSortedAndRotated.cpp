#include <bits/stdc++.h>
using namespace std;

// My Leetcode solution
class Solution {
public:
    int search(vector<int>& A, int key) {
        int index = findMin(A, A.size());
        int ans = binarySearch(A, 0, index-1, key); // left half
        if(ans != -1) return ans;
        ans = binarySearch(A, index, A.size()-1, key); // right half
        return ans;
    }
    int binarySearch(vector<int>& arr, int low, int high, int key) {
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(arr[mid] == key) {
                return mid;
            }
            else if(key > arr[mid]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
    int findMin(vector<int>& arr, int n) {
        int low = 0;
        int high = n-1;
        while(low <= high) {
            if(arr[low] <= arr[high]) return low;
            int mid = lxow + (high - low)/2;
            int prev = (mid - 1 + n) % n;
            int next = (mid + 1) % n;
            if(arr[mid] <= arr[prev] && arr[mid] <= arr[high]) {
                return mid;
            }
            if(arr[low] <= arr[mid]) {
                low = mid + 1;
            }
            else if(arr[mid] <= arr[high]) {
                high = mid - 1;
            }
        }
        
        return arr[0];
    }
};

// new solution
int binarySearch(vector<int> &nums, int target) {
    int low = 0, high = nums.size()-1;
    while (low <= high) {
        int mid = low + (high - low)/2;
        if (nums[mid] == target)
            return mid;
        if ( nums[low] <= nums[mid] ) {
            if (target >= nums[low] and target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else {
            if (target > nums[mid] and target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return-1;
}

int main()
{
    vector<int> nums = {4,5,6,7,1,2};
    
    cout << binarySearch(nums, 1) << endl;
    
    return 0;
}