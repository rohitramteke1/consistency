#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size()-1;
    int ans = -1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(nums[mid] == target) {
            ans = mid;
            high = mid - 1;
        }
        else if(target > nums[mid]) {
            low = mid + 1;
        }
        else if(target < nums[mid]) {
            high = mid - 1;
        }
    }
    return ans;
}

int lastOccurence(vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size()-1;
    int ans = -1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(nums[mid] == target) {
            ans = mid;
            low = mid + 1;
        }
        else if(target > nums[mid]) {
            low = mid + 1;
        }
        else if(target < nums[mid]) {
            high = mid - 1;
        }
    }
    return ans;
}

// O(NlogN + 2*logN + 100) ~= O(NlogN + 2lognN) ~= O(NlogN)
vector<int> solve(vector<int> &nums, int target) {
    vector<int> v;

    sort(nums.begin(),nums.end());
    int fo = firstOccurence(nums, target);
    int lo = lastOccurence(nums, target);
    if(fo == -1 && lo == -1) {
        return v;
    }
    
    if(fo == lo) {
        return {fo};
    }
    return {fo, lo};
}

// O(N)
vector<int> optimal(vector<int> &nums, int target) {
    vector<int> v;
    int equalElementCount = 0;
    int smallerElementCount = 0;
    for (auto &&i : nums)
    {
        if(i == target) equalElementCount++;
        else if(i < target) smallerElementCount++;
    }
    while(equalElementCount--) {
        v.push_back(smallerElementCount++);
    }
    return v;
}

int main()
{
    vector<int> arr = {1,2,5,2,3};
    int target = 3; 
    vector<int> v = solve(arr, target);
    for (auto &&i : v)
    {
        cout << i << ' ';
    }
    
    return 0;
}