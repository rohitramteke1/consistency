#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {-2,1,-3,3};
    int k = 2;

    int len = 0;

    int sum = 0;
    int cur = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        cur += nums[i];
        if(cur > sum) {
            sum = cur;
        }
        if(cur < 0) {
            cur = 0;
        }
    }
    cout << sum << endl;
    
    return 0;
}