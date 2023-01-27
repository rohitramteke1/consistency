#include <bits/stdc++.h>
using namespace std;

int kadanes(vector<int> & nums) {
    int n = nums.size();
    int maxSum = INT_MIN;
    int minSum = INT_MAX;
    int curr_maxSum = 0;
    int curr_minSum = 0;
    int totalSum = 0;

    for (int i = 0; i < n; i++)
    {
        curr_maxSum += nums[i];
        curr_minSum += nums[i];
        totalSum += nums[i];
        maxSum = max(maxSum, curr_maxSum);
        minSum = min(minSum, curr_minSum);
        if(curr_maxSum < 0) {
            curr_maxSum = 0;
        }
        if(curr_minSum > 0) {
            curr_minSum = 0;
        }
    }
    cout << minSum << ' ' << maxSum << endl;
    return minSum == totalSum ? maxSum : max(maxSum, totalSum - minSum);
}

int main()
{
    vector<int> nums;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        nums.emplace_back(a);
    }

    cout << kadanes(nums) << endl;
    
    
    
    return 0;
}