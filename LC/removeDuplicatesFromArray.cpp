// DATE: 2022-11-06
// 1 <= nums.length <= 3 * 10^4
// -100 <= nums[i] <= 100
// nums is sorted in non-decreasing order.

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums){
    int n = nums.size();
    if(n == 0 || n == 1) return n;
    int i = 0;
    int j = 1;
    while (j < n)
    {
        if(nums[i] != nums[j] ) {
            i++;
            if(i != j || nums[i] != nums[j])
                nums[i] = nums[j];
                // swap(nums[i], nums[j]);
        }
        j++;
    }
    
    
    return i+1;
}
int main()
{
    vector<int> nums = {0,1,2,3,4,5,6,7};

    removeDuplicates(nums);
    for (auto &&i : nums)
    {
        cout << i << ' ';
    }
    
    return 0;
}