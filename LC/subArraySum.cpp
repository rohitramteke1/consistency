#include <bits/stdc++.h>
using namespace std;


int solve(vector<int> &nums, int k);
int main()
{
    vector<int> nums = {4,5,0,-2,3,1};
    int k = 5;

    cout << solve(nums, k) << endl;
    
    return 0;
}

int solve(vector<int> & nums, int k) {
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if(sum % k == 0) {
                cnt++;
            }
        }
    }
    return cnt;
}