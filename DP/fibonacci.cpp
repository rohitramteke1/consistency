#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
const int M = 1e9 + 7;
int dp[N];

// 0 1 1 2 3 5 8 13 ...
// 0 1 2 3 4 5 6 7  ...

// TOP DOWN APPROACH (large to small problem)
//dp states ↓
int fib(int n)
{
    // base condition
    if (n == 1 || n == 0)
        return n;

    // memoise
    if (dp[n] != -1)
        return dp[n];
    
    return dp[n] = fib(n - 1) + fib(n - 2);
    // return dp[n] = (fib(n - 1) % M + fib(n - 2) % M) % M;
}

int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    // for (int i=0; i<n; i++)
    //     cout << dp[i] << ' ';

    cout << fib(n) << endl;

    // Iterative approach
    // dp[0] = 0;
    // dp[1] = 1;
    // for (int i = 2; i <= n; i++)
    // {
    //     dp[i] = dp[i-1] + dp[i-2];
    // }
    // cout << dp[n] ;
    
    return 0;
}