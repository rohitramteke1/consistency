#include <bits/stdc++.h>
using namespace std;

int specialSum(vector<int> &nums, int n) {
    int ans = 0;
    ans = accumulate(nums.begin(), nums.end(), 0);
    if(ans=0) return ans;
    return ans % 9 == 0 ? ans = 9 : ans;
}

int main()
{
    // vector<int> a = {8, 7, 0, 1, 2};
    vector<int> a = {4,2,1,1};
    cout << specialSum(a, a.size()) << endl;
    
    return 0;
}