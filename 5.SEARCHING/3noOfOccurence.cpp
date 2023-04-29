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

	int count(vector<int> &nums, int n, int x) {
        int first = firstOccurence(nums, x);
        if ( first == -1)
            return 0;
        int last = lastOccurence(nums, x);
        return (last - first) + 1;
	}

int main()
{
    vector<int> nums = {5,7,7,8,8,10};
    int target = 6;
    
    cout << count(nums, nums.size(), target) << endl;

    return 0;
}