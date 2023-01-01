#include <bits/stdc++.h>
using namespace std;

// O(logN) + O(1)
int minDiffElement(vector<int> nums, int target) {
    int low = 0;
    int high = nums.size()-1;
    int mid = low + (high - low)/2;
    while(low <= high) {
        if(nums[mid] == target) return nums[mid]-target; // ultimately 0 is the ans -> { nums[mid]-target == 0 }
        else if(nums[mid] < target) low = mid + 1;
        else if(nums[mid] > target) high = mid - 1;
        mid = low + (high - low)/2;
    }
    if(abs(nums[low] - target) < nums[high] - target)
        return nums[low];
    return nums[high];
}

int main()
{
    vector<int> nums = {2, 5, 6, 10, 12, 15};
    int target = 11;
    cout << minDiffElement(nums, target) << endl;
    
    return 0;
}