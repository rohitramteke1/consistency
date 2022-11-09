#include <bits/stdc++.h>
using namespace std;

int subsetSum(vector<int> &arr, int sum, int n) {
    vector< vector<int> > dp;
    vector<int> v;

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(j == 0)
                v.emplace_back(true);
            else if(i == 0 && j > 0)
                v.emplace_back(false);
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
            if(arr[i-1] <= j) {
                dp[i][j] = dp[i-1][j - arr[i-1]] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    

    return dp[n][sum];
}

int main()
{
    // vector<int> arr = {5,2,5,1};
    // vector<int> arr = {1, 1, 1, 1};
    int t;
    cin >> t;
    while(t--)
    {
        int n, diff = 0;
        cin >> n >> diff;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int a; cin >> a;
            arr.emplace_back(a);
        }
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int s1 = (sum + diff)/2;

        cout << subsetSum(arr, s1, n) << endl;
        arr.clear();
    }
    

    
    return 0;
}