#include <bits/stdc++.h>
using namespace std;

// Brute Force 
// Time Limit Exceeded
int minIncrementForUniqueBFS(vector<int>& nums) {
    unordered_set<int> uset;
    int ans = 0;
    int i = 0;
    while(i < nums.size()) {
        if(uset.find(nums[i]) == uset.end()) {
            uset.insert(nums[i]);
            i++;
        }
        else {
            nums[i] += 1;
            ans++;
        }
    }
    return ans;
}

int minIncrementForUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int cnt = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        int next = nums[i];
        int prev = nums[i-1];
        if(next <= prev) {
            // change the next to prev + 1, this way next become greater than prev 
            // as well as unique
            // now this new_value is our new-next value
            int new_value = prev + 1;
            // how much we add to make it unique
            cnt += new_value - next;
            nums[i] = new_value;
        }
    }

    return cnt;
}
int solve(vector<int>& nums) {
    unordered_set<int> uset;

    int cnt = 0;
    int maxSoFar = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        // cout << nums[i] << ' ';
        if(uset.find(nums[i]) == uset.end()) {
            uset.insert(nums[i]);
            maxSoFar = max(maxSoFar, nums[i]);
        }
        else {
            // cout << "We're in else block\n";
            maxSoFar += 1;
            uset.insert(nums[i]);
            cnt += abs(maxSoFar - nums[i]);
            nums[i] = maxSoFar;
        }
    }

    return cnt;
}

int main()
{
    vector<int> nums = {1,2,2};
    // cout << minIncrementForUnique(nums) << endl;
    cout << solve(nums) << endl;
    
    return 0;
}
