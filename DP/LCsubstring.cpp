// your task is to find the longest comman sub-sequence
// of the two given string's of size m and n

#include <bits/stdc++.h>
using namespace std;

int _count = 0;
int LCS_recursive(string s1, string s2, int m, int n, int _count) {

    if(m==0 || n==0)
        return _count + 0;

    if(s1[m-1] == s2[n-1])
        return LCS_recursive(s1, s2, m-1, n-1, 1 + _count);

    else
        return 
        _count = max (_count,
            max(
                LCS_recursive(s1, s2, m, n-1, 0),
                LCS_recursive(s1, s2, m-1, n, 0)
            )
        );
}

int LCS_bottom_up(string s1, string s2, int m, int n) {

    vector< vector<int> > dp(m + 1, vector<int> (n + 1, 0));
    int _len = 0;

    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                _len = max(_len, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }   
    }
    return _len;
}

int main()
{
    string s1 = "12321";
    string s2 = "32147";
    
    int m = s1.length();
    int n = s2.length();

    // cout << "longest comman subsequence: " << LCS_recursive(s1, s2, m, n, 0) << endl;
    // memset(dp, -1, sizeof(dp));

    cout << "longest comman subsequence: " << LCS_bottom_up(s1, s2, m, n) << endl;

    return 0;
}