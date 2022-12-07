#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int>& nums, int s, int e) {
    if(s>=e) return;
    int l=s+1, r=e;
    while(l<r)
    {
        if(nums[l]<=nums[s]) l++;
        else if(nums[r]>nums[s]) r--;
        else swap(nums[l], nums[r--]);       
    }
    if(nums[l]>nums[s]) l--;
    swap(nums[s], nums[l]);
    quickSort(nums, s, l-1);
    quickSort(nums, l+1, e);
}

int main()
{
    vector<int> nums = {5,1,1,2,0,0};
    quickSort(nums, 0, nums.size()-1);
    for (auto &&i : nums) cout << i << ' ';
    

    return 0;
}