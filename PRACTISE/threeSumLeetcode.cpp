#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> bruteForceSolution(vector<int>& nums) {
    vector< vector<int> > v;
    set <vector<int> > s;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i+1; j < nums.size(); j++)
        {
            for (int k = j+1; k < nums.size(); k++)
            {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> vt = {nums[i], nums[j], nums[k]};
                    sort(vt.begin(), vt.end());
                    s.insert(vt);
                }
            }   
        }
        
    } // for() end

    for (auto &&i : s)
    {
        v.emplace_back(i);
    }
    
    return v;
}

vector<vector<int>> threeSumHashing(vector<int>& nums) {
    vector< vector<int> > v;
    set< vector<int> > s;
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++)
    {
        hash[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        hash[nums[i]]--;
        for (int j = i+1; j < nums.size(); j++)
        {
            hash[nums[j]]--;
        }   
    }



    return v;
}


vector<vector<int>> threeSum(vector<int>& nums) {
    vector< vector<int> > v;
    

    return v;
}


int main()
{
    vector<int> nums = {0,0,0, 1, -1, 0, -1};
    vector< vector<int> > v = bruteForceSolution(nums);
    // vector< vector<int> > v = threeSum(nums);


    for (auto &&i : v)
    {
        for (auto &&item : i)
        {
            cout << item << ' ';
        }
        cout << endl;
    }
    
    return 0;
}