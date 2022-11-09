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
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[n][sum];
}

int main()
{
    vector<int> arr = {1,1,2,3};
    int n = arr.size();
    int sum = 5;
    cout << bottomUp(arr, sum, n) << endl;
    

    return 0;
}