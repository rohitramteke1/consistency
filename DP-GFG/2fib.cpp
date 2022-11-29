#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;
const int N = 1e3+10;
int dp[N];

long long fib(int n) {
    if(n==0 || n==1) 
        return n;
    if(dp[n] != -1) 
        return dp[n];

    // (a + b) % M = (a % M + b % M ) % M
    return dp[n] = (fib(n-1) % M + fib(n-2) % M) % M;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cout << fib(10);
    
    return 0;
}