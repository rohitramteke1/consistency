#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;

// BFS
    // int maxi = INT_MIN;
    // for (int i = 0; i < nums.size() - k + 1; i++)
    // {
    //     maxi = INT_MIN;
    //     for (int j = 0; j < k; j++)
    //     {
    //         maxi = max(nums[i+j], maxi);
    //     }
    //     ans.emplace_back(maxi);
    // }
    // return ans;

// Optimised
    list<int> l;
    int i = 0;
    int j = 0;
    while (j < nums.size())
    {
        // calculations
        while (!l.empty() && l.back() < nums[j])
        {
            l.pop_back();
        }
        l.push_back(nums[j]);
        if(j < k) {
            j++;
        } 
        if(j - i + 1 == k) {
            ans.emplace_back(l.front());
            if(nums[i] == l.front())
                l.pop_front();
            i++, j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> arr = maxSlidingWindow(nums, k);
    
    for (auto &&i : arr)
    {
        cout << i << ' ';
    }
    
    return 0;
}