// DP: Sequence Pattern Matching
// you have a given string a and b
// and you've to check whether a string-a is part of string-b

// IS string-a isSubsequence of string-b --> true/false

#include <bits/stdc++.h>
using namespace std;

int isSequence(string &s1, string &s2, int m, int n) {

    vector< vector<int> > dp(m + 1, vector<int>(n+1, 0));
    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
        }
    }

    return dp[m][n];
}

bool is_sub_sequence(string &s1, string &s2, int m, int n) {
    int i = m-1;
    int j = n-1;
    while(j >= 0) {
        if(s1[i] == s2[j])
            i--;
        j--;
    }
    return i == -1 ? 1 : 0;
}

/*
const int M = 1e3 + 10;
const int N = 1e3 + 10;
int dp[M][N];
bool subSequence(string &s1, string &s2, int m, int n)
{
    if (m == 0)
        return true;
    if (n == 0 && m > 0)
        return false;
    if (dp[m][n] != -1)
        return dp[m][n];
    if (s1[m - 1] == s2[n - 1])
        return subSequence(s1, s2, m - 1, n - 1);
    return subSequence(s1, s2, m, n - 1);
}
*/

int main()
{
    string s1 = "AXY";
    string s2 = "YADXCPY";
    cout << (s1.length() == isSequence(s1, s2, s1.length(), s2.length()) )<< endl ;
    cout << is_sub_sequence(s1, s2, s1.length(), s2.length()) << endl ;


    // memset(dp, -1, sizeof(dp));
    // cout << subSequence(s1, s2, s1.length(), s2.length()) << endl;

    return 0;
}