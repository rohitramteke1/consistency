// Time Limit: 2 sec / Memory Limit: 1024 MB

// Score : 100 points

// FROG-1 AtCoder DP
// Constraints
// All values in input are integers.
// 2≤N≤10^5
// 1≤h[i]≤10^4
// we've given 1 based indexing -> and we're using 0 based indexing

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int h[N];
int dp[N];
int k; // k steps

int func(int i) {
    // base condition
    if (i==0) return 0;
    // if i negative just return 0 and remove the if (i-j > 0) from loop
    // if(i < 0) return 0;

    // memoise
    if(dp[i] != -1) return dp[i];
    int cost = INT_MAX;

    for(int j=1; j<= k; j++)
        if(i-j >= 0)
            cost = min(cost, func(i-j) + abs(h[i] - h[i-j]));

    return dp[i] = cost;
    // Time Complexity: O(N*K) 
}

int main()
{
    memset(dp, -1, sizeof(dp)); 
    int n; cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> h[i];

    // why n-1 ? ==> 0 based indexing
    cout << func(n-1) << endl ;

    // iterative approach 
    // dp[0] = 0;
    // for (int i = 1; i < n; i++)
    // {
    //     int cost = INT_MAX;
    //     for (int j = 1; j <= k; j++)
    //     {
    //         if(i - j >= 0)
    //         cost = min(cost, dp[i-j] + abs(h[i] - h[i-j]));
    //         dp[i] = cost;
    //     }
    // }
    // cout << dp[n-1] << endl ;
    return 0;
}