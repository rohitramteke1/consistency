#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int dp[N];

int jump(int arr[], int n)
{
    dp[0] = dp[1] = 0;

    int cost = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        cost = min(cost, abs(arr[i] - arr[i-1]) + dp[i-1] );
        if(i > 1)
            cost = min(cost, abs(arr[i] - arr[i-2]) + dp[i-2] );
        dp[i] = cost;
    }
    
    return dp[n];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i <= n; i++)
        cin >> arr[i];

    cout << jump(arr, n) << endl;

    return 0;
}