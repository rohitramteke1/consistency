#include <bits/stdc++.h>
using namespace std;


int maximumGap(vector<int> nums) {
    int gap = INT_MIN;
    
    sort(nums.begin(), nums.end());
    
    for(int i=1; i<nums.size(); i++) {
        gap = max(gap, nums[i]-nums[i-1]);
    }
    return gap;
}

int main()
{
    vector<int> nums = {3,6,9,1};
    cout << endl << maximumGap(nums) << endl;
    
    return 0;
}