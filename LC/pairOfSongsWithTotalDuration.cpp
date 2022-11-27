#include <bits/stdc++.h>
using namespace std;

int pairOfSongs(vector<int> &nums) {
    int ans = 0;
    unordered_map<int, int> hash;

    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = nums[i] % 60;
        hash[nums[i]]++;
    }
    
    for (int i = 0; i < nums.size(); i++)
    {
        // hash[nums[i]]--;
        if(hash.find(0) != hash.end()) {
            ans += ( hash[0]*(hash[0]-1) )/2 ;
            hash[0] = 0;
        }
        else if(hash.find(30) != hash.end()) {
            ans += ( hash[30]*(hash[30]-1) )/2 ;
            hash[30] = 0;
        }
        else if(hash.find(60-nums[i]) != hash.end() ) {
            if(hash[60 - nums[i]] > 0) {
                ans += hash[60 - nums[i]];
            }
        }
    }

    return ans;
}
int main()
{
    vector<int> nums = {30,20,150,100,40};
    cout << pairOfSongs(nums);

    return 0;
}