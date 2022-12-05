#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums){
    int n = nums.size(); 
    
    long sum = accumulate(nums.begin(), nums.end(), 0);
    long mn = LONG_MAX;
    int idx = -1;
    long temp = 0;
    long avg = 0;

    for (int i = 0; i < n; i++)
    {
        temp += nums[i];
        sum = sum - nums[i];
        cout  << sum << ' ' << temp << endl;
        if(n-i-1 == 0) n = 0;
        avg = abs( temp/(i+1) - sum/(n-i-1));
        if( mn > avg ) {
            mn = avg;
            idx = i;
        }
    }
    
    return idx;
}

int main()
{
    vector<int> nums = {2,5,3,9,5,3};
    cout << solve(nums) << endl;
    
    return 0;
}