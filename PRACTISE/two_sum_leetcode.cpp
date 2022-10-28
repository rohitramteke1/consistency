#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> hash;
    vector<int> v;

    for (int i = 0; i < nums.size(); i++)
    {
        if(hash.find(target - nums[i]) != hash.end()) 
        {
            v.emplace_back(hash[target - nums[i]]);
            v.emplace_back(i);
            return v;
        }
        hash[nums[i]] = i;
    }
    return v;
}

void twoSumBFS(vector<int>& nums, int target) {
    vector<int> v = nums; // O(N)
    sort(v.begin(), v.end()); // O(N * log N)
    int low = 0;
    int high = v.size() - 1;
    while (high > low) // O( low + high)  ~= O(N)
    {
        if(v[low] + v[high] < target) {
            low++;
        } 
        else if(v[low] + v[high] == target) break;
        else {
            high--;
        }
    }
    vector<int> indx;
    for (int i = 0; i < nums.size(); i++)
    {
        if(v[low] == nums[i] || v[high] == nums[i]) indx.emplace_back(i);
        if(indx.size() == 2) break;
    }
    
    // Time and Space complexity
    // O(N * logN + N + N) -=> ~= O(N * logN)
    // O(N + 2) -=> O(N)

    for (auto &&i : indx)
    {
        cout << i << ' ';
    }
}

int main()
{
    vector<int> arr1 = {2,7,11,15};
    vector<int> v = twoSum(arr1, 9);
    // twoSumBFS(arr1, 18);
    for (auto i : v)
    {
        cout << i << ' ';
    }
    
    return 0;
}