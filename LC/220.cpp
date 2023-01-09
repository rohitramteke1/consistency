#include <bits/stdc++.h>
using namespace std;

// Brute Force Solution
bool containsNearbyAlmostDuplicateBFS(vector<int>& nums, int indexDiff, int valueDiff) {
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(abs(i - j) <= indexDiff) {
                if(abs(nums[i] - nums[j]) <= valueDiff) {
                    return true;
                }
            }
            else break;
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {1,5,9,1,5,9};
    int indexDiff = 3, valueDiff = 0;
    cout << containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff) << endl;
    
    
    return 0;
}