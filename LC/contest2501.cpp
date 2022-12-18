#include <bits/stdc++.h>
using namespace std;

int longestSquareStreak(vector<int>& nums) {

    unordered_map<int, int> hash;
    sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size(); i++)
    {
        int _sqrt = sqrt(nums[i]);
        if(_sqrt*_sqrt == nums[i] && hash.find(_sqrt) != hash.end())
            hash[nums[i]] = hash[_sqrt] + 1;
        else
            hash[nums[i]] = 1;
    }
    
    int ans = -1;
    for (auto i : hash)
        ans = max(ans, i.second);

    return ans == -1 ? -1 : ans;
}

int longestSquareStreakBetter(vector<int>& nums) {
    unordered_map<int, int> hash;

    for (size_t i = 0; i < nums.size(); i++)
    {
        hash[nums[i]] = 1;
    }
    for (size_t i = 0; i < nums.size(); i++)
    {
        int _sqrt = sqrt(nums[i]);
        if(_sqrt*_sqrt == nums[i] && hash.find(_sqrt) != hash.end()) 
            hash[nums[i]] = hash[_sqrt] + 1;
    }
    int ans = -1;
    for (auto i : hash) 
        ans = max(ans, i.second);
    
    return ans == 1 ? -1 : ans;
}

int main()
{
    vector<int> nums = {4,3,6,16,8,2};
    cout << longestSquareStreakBetter(nums) << endl;
    
    return 0;
}