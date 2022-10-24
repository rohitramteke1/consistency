// Longest increasing subsequence of array
// length of longest incresing subsequence
// subsequence(pick any element and order matters)
// and subarray (continuous and order)

#include <bits/stdc++.h>
using namespace std;
const int N = 25e2+10;
int dp[3000];
vector<int> a(N);

// dp state ↓ => 1
int lis(int i) {
    // memoise
    if (dp[i] != -1) return dp[i];

    int ans = 1;
    for (int j = 0; j < i; j++)
        if(a[i] > a[j])
            ans = max(ans, lis(j) + 1);

    return dp[i] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    // arr[] = 10 9 2 5 3 7 101 18
    // 10 101
    // 10 18
    // 9 101
    // 9 18
    // 2 3 7 101 => 4
    // 2 5 7 101 => 4
    // and so on... longest increasing subsequece can be 1 or more than 1 
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, lis(i));
    }
    cout << ans << endl ;

    // print dp[i] here so that we'll get actually happening here
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "i:" << i << " " << dp[i] << endl ;
    // }
    
    return 0;
}