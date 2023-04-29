#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> &nums, int target) {
    int low = 0, high = nums.size()-1;
    int index = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) 
        {
            index = mid;
            high = mid - 1;
        }
        else if (nums[mid] > target) 
            high = mid - 1;
        else
            low = mid + 1;
    }
    
    return index;
}

int lastOccurence(vector<int> &nums, int target) {
    int low = 0, high = nums.size()-1;
    int index = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) 
        {
            index = mid;
            low = mid + 1;
        }
        else if (nums[mid] > target) 
            high = mid - 1;
        else
            low = mid + 1;
    }
    
    return index;
}

vector<int> searchRange(vector<int>& nums, int target) {
    return {
        firstOccurence(nums, target),
        lastOccurence(nums, target)
    };
}

int main()
{
    vector<int> nums = {5,7,7,8,8,10};
    int target = 6;
    
    vector<int> ans = searchRange(nums, target);
    for (auto &i : ans) 
        cout << i << ' ';

    return 0;
}