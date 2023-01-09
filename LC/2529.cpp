#include <bits/stdc++.h>
using namespace std;

int binarySearchForNegative(vector<int>& nums) {
    int low = 0;
    int high = nums.size();
    int mid;
    int ans = 0;
    while(low <= high) {
        mid = low + (high - low) / 2;
        if(nums[mid] < 0) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int binarySearchForPositive(vector<int>& nums) {
    int low = 0;
    int high = nums.size();
    int mid;
    int ans = 0;
    while(low <= high) {
        mid = low + (high - low) / 2;
        if(nums[mid] > 0) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-3,-2,-1,1,2,3};
    int n = nums.size();
    cout << 1 + binarySearchForNegative(nums) << endl;
    cout << n - binarySearchForPositive(nums) << endl;

    return 0;
}