// your task is to find the longest comman sub-sequence
// of the two given string's of size m and n

#include <bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2, int m, int n) {

    if(m==0 || n==0) return 0;

    if(s1[m-1] == s2[n-1]) {
        return 1 + LCS(s1, s2, m-1, n-1);
    }
    else {
        return max(
            LCS(s1, s2, m, n-1),
            LCS(s1, s2, m-1, n)
            );
    }
}

const int N = 1e3 + 10;
const int M = 1e3 + 10;
int dp[M][N];

int LCS_DP(string s1, string s2, int m, int n) {

    if(m==0 || n==0) 
        return dp[m][n] = 0;

    if(dp[m][n] != -1) 
        return dp[m][n];

    if(s1[m-1] == s2[n-1]) {
        return dp[m][n] = ( 1 + LCS_DP(s1, s2, m-1, n-1) );
    }
    else {
        return dp[m][n] = max(
            LCS_DP(s1, s2, m, n-1),
            LCS_DP(s1, s2, m-1, n)
            );
    }
}

int bottomUp(string s1, string s2, int m, int n) {
    vector< vector<int> > dp(m+1, vector<int>(n+1, 0));

    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } 
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    
    return dp[m][n];
}

int main()
{
    string s1 = "abcde";
    string s2 = "abfce";
    
    int m = s1.length();
    int n = s2.length();
    // cout << "longest comman subsequence: " << LCS(s1, s2, 3, 2) << endl;
    
    // memset(dp, -1, sizeof(dp));
    // cout << "LCS DP: " << LCS_DP(s1, s2, m, n) << endl;
    cout << "Bottom Up: " << bottomUp(s1, s2, m, n) << endl;


    
    return 0;
}