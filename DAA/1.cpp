#include <bits/stdc++.h>
using namespace std;
class Practical{
    vector<int> nums;
public:
    Practical(vector<int> nums) {
        this->nums = nums;
    }
    // TC: O(logN) + SC: O(1)
    int binarySearch(int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        while(low <= high) {
            mid = low + (high - low)/2;
            if(nums[mid] == target) 
                return mid;
            else if(nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
    // TC: O(logN) + SC: O(logH) where H is the Height og perfect Binary Tree
    int binarySearchRecur(int target, int low=0, int high=0) {
        if(low > high)
            return -1;
        int mid = low + (high - low)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            return binarySearchRecur(target, low, mid - 1);
        return binarySearchRecur(target, mid + 1, high);
    }
    // TC: O(N) + SC: O(1)
    int linearSearch(int target) {
        if(nums[0] == target)
            return 0;
        if(nums[nums.size()-1] == target)
            return nums.size()-1;
        for(int i=1; i<nums.size()-1; i++) {
            if(nums[i] == target)
                return i;
        }
        return -1;
    }
    // TC: O(N) + SC: O(N)
    int linearSearchRecur(int target, int i=0) {
        if(i > nums.size())
            return -1;
        if(nums[i] == target)
            return i;
        return linearSearchRecur(target, i + 1);
    }
};

int main()
{
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9,10};
    Practical p(nums);
    // cout << "Binary-Search: element found at index: " << p.binarySearch(10) << endl;
    // cout << "Binary-Search-Recursive: element found at index: " << p.binarySearchRecur(10, 0, nums.size()-1) << endl;
    cout << "Linear-Search: element found at index: " << p.linearSearch(5) << endl;
    cout << "Linear-Search-Recursive: element found at index " << p.linearSearchRecur(6, 0) << endl;
    return 0;
}