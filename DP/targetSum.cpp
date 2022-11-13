// we have a given a target sum, and we've to initialise the sign +,- in such a way that the 
// sum of array equal to target sum
// ex [1 2 3 4]
// target = 2
// [+1 +2 +3 -4]
// basically subset sum diff
// s1(+ve values) + (-ve values)s2 = target
// and count the possible no of ways to initialise the signs

#include <bits/stdc++.h>
using namespace std;

int bottomUp(vector<int> &arr, int sum, int n) {

    vector< vector<int> > dp;
    for (int i = 0; i < n+1; i++)
    {
        vector<int> v;
        for (int j = 0; j < sum+1; j++)
        {
            if(j == 0) 
                v.emplace_back(true);
            else
                v.emplace_back(false);   
        }
        dp.emplace_back(v);
        v.clear();
    }

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j - arr[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[n][sum];
}

int main()
{
    vector<int> arr = {1,1,1,1,1};
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);

    // s1 - s2 = diff
    // s1 + s2 = sum
    // 2s1 + 0 = sum + diff
    int target = 3;
    int s1 = (sum + target)/2;

    cout << bottomUp(arr, s1, n) << endl;
    

    return 0;
}