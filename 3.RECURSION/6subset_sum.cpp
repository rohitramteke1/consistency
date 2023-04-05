#include <bits/stdc++.h>
using namespace std;

// All subset using recursion
void solve(vector<int> &arr, vector<int> &curr, int i) {
    
    if(i == arr.size()) {
        for (auto &ele : curr)
            cout << ele << ' ';
        cout << endl;
        return;
    }

    // take
    curr.push_back(arr[i]);
    solve(arr, curr, i + 1);

    // notake
    curr.pop_back();
    solve(arr, curr, i+1);
}

// SubSet Sum Using DP
bool helper(vector<int> &arr, int n, int sum, vector< vector<int> > &dp) {
    if(n == 0)
        return sum == 0 ? 1 : 0;

    if(dp[n][sum] != -1)
        return dp[n][sum];

    return dp[n][sum] = helper(arr, n - 1, sum - arr[n-1], dp) +
        helper(arr, n - 1, sum, dp);
}

int countSubSet(vector<int> &arr, int n, int sum) {
    vector< vector<int> > dp (n + 1, vector<int> (sum + 1, -1) );
    return helper(arr, n, sum, dp);
}

int main()
{
    vector<int> arr = {1,2,3};
    cout << countSubSet(arr, 3, 6) << endl;
    vector<int> curr;
    solve(arr, curr, 0);
    return 0;
}