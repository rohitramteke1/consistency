#include <bits/stdc++.h>
using namespace std;

int binarySearchOnRange(vector<int> &nums, int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low)/2;
        if (nums[mid] == target) 
            return mid;
        if (nums[mid] < target) 
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int search(vector<int> &nums, int target) {
    int slow = 0;
    int fast = 1;

    while (target >= nums[fast]) {
        slow = fast;
        fast = 2 * fast;
    }

    return binarySearchOnRange(nums, slow, fast, target);
}

int main()
{
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    cout << search(nums, 10) << endl;
    return 0;
}