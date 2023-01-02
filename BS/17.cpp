#include <bits/stdc++.h>
using namespace std;

// Binary Search on answer
// O(logN)
int binarySearch(vector<int> &nums) {
    int n = nums.size();
    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = low + (high - low)/2;
        if(mid > 0 && mid < n-1) {
            if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) {
                return mid;
            }
            else if(nums[mid] < nums[mid - 1]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        else if (mid == 0) {
            if(nums[0] > nums[1]) return 0;
            else return 1;
        }
        else if (mid == n-1)
        {
            if(nums[n-1] > nums[n-2]) {
                return n-1;
            }
            else {
                return n-2;
            }
        }
    }
    return -1;
}

// clean code
// O(logN)
int binarySearchClean(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] > nums[mid + 1])
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    vector<int> nums = {1,2,3,1};

    cout << binarySearch(nums) << endl;
    cout << binarySearchClean(nums) << endl;
    
    return 0;
}