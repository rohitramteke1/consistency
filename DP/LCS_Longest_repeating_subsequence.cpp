// Find the longest repeating subsequence in a string
// you've given a string-s -> "abcedabcd" and you 
// have to find the repeating subsequence in that string
// -> abcecabcd
// -> abc e d abcd
// -> abcd e abcd 
// -> abcd is repeated -> so ans -> 4 length

#include <bits/stdc++.h>
using namespace std;

int printLongestRepeatingSubsequence(string s1, string s2, int m, int n) {

    vector< vector<int> > dp(m + 1, vector<int>(n+1, 0));

    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            // LCS small change here -> i != j
            if(s1[i-1] == s2[j-1] && i != j)
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
        }
    }

    return dp[m][n];
}

int main()
{
    string s1 = "aabebcdd";
    cout << printLongestRepeatingSubsequence(s1, s1, s1.length(), s1.length()) << endl;
    
    return 0;
}