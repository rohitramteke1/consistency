#include <bits/stdc++.h>
using namespace std;

// 1.Longest palindromic subsequence
// NOTE: On applying LCS on -> reverse of string with 
// itself gives you longest palindromic

string reverse(string s) {
    for (int i = 0; i < s.length()/2; i++)
        swap(s[i], s[s.length()-1-i]);
    return s;
}

int LCS(string s1, string s2, int m, int n) {

    vector< vector<int> > dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
        }
    }
    return dp[m][n];
}

int main()
{
    // this is very intersting question
    // understand the concept
    // NOTE: On applying LCS on -> reverse of string with itself
    // gives you longest palindromic subs-equence
    
    string s1 = "madam";
    cout << LCS(s1, reverse(s1), s1.length(), s1.length()) << endl;
    
    return 0;
}