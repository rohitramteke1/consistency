#include <bits/stdc++.h>
using namespace std;

int ascBS(vector<int> &nums, int low, int high, int target) {
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] > target){
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int descBS(vector<int> &nums, int low, int high, int target) {
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] < target){
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

// break the array in two parts based on a peak element
int binarySearch(vector<int> &nums) {
    int low = 0;
    int high = nums.size()-1;
    while(low < high) {
        int mid = low + (high - low)/2;
        if(nums[mid] > nums[mid + 1]){
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    return low; // peak element index
}

// Main
// TC: O(logN + logN) ~= O(logN)
// SC: O(1)
int main()
{
    vector<int> nums = {1,2,5,3,0};
    int index = binarySearch(nums);
    cout << ascBS(nums, 0, index - 1, 5) << endl;
    cout << descBS(nums, index, nums.size()-1, 5) << endl;   
    
    return 0;
}