#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
const int M = 1e5+10;
int dp[N][M];

/*
int bottomUp(vector<int> &arr, int sum, int n) {
// initialisation

    vector< vector<int> > dp;
    vector<int> v;
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(i==0 && j == 0) {
                v.emplace_back(1);
            } else if(j==0){
                v.emplace_back(1);
            } else {
                v.emplace_back(0);
            }
        }
        dp.emplace_back(v);
        v.clear();
    }
    
// recursive -> iterative
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];

            else if(arr[n-1] > j)
                dp[i][j] = dp[i-1][j];
        }
    }

    for (int i = 0; i <= sum; i++)
    {
        if(dp[n][i])
            v.emplace_back(i);
    }

    int mn = INT_MAX;
    for (int i = 0; i < v.size(); i++)
        mn = min(mn, abs(sum - 2*v[i]));

// return ans
    return dp[n][sum];
}
*/

int bottomUp(int arr[], int sum, int n) {
// initialisation
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = true;

    for (int j = 1; j < sum + 1; j++)
        dp[0][j] = false;
    
// recursive -> iterative
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
    
// return ans
    return dp[n][sum];
}


int main()
{   
    int arr[] = {11, 18, 21, 11, 20, 9};
    int n = 6;
    
    int sum = accumulate(arr, arr + n, 0);
    cout << sum << ' ';
    bottomUp(arr, sum, n);

    vector<int> v;
    for (int i = 0; i <= sum; i++)
    {
        if(dp[n][i])
            v.emplace_back(i);
    }

    int mn = INT_MAX;
    for (int i = 0; i < v.size(); i++)
        mn = min(mn, abs(sum - 2*v[i]));

    cout << mn << endl;
    return 0;
}