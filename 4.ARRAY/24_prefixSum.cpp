#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {3,4,8,-9,20,6};
    int n = nums.size();

    vector<int> prefix(n, 0), suffix(n, 0);
    prefix[0] = nums[0], suffix[n-1] = nums[n-1];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i-1] + nums[i];
        suffix[n-1-i] = suffix[n-i] + nums[n-1-i];
    }
    
    for (int i = 0; i < n; i++)
    {
        if(suffix[i] == prefix[i])
        {
            cout << "Equilibrium Point: " << i << endl;
            break;
        }
    }
    
    // store the right sum and in r_sum variable and maintain the left sum var
    // and add arr[i] into left_sum and subtract from the r_sum and check 
    // both the sum, if they are equal then that is the equilibrium point
     
    return 0;
}