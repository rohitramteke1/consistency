// you have given a 2 strings s1 and s2
// you have to find the shortest comman super-sequence
// ex geek, eke
// 1. geekeke
// 2. geeke
// geekeke -> geek + eke
// geeke -> geek + eke   <--- This one is better
// and your task is to find the shortest super-sequence of the ans.


#include <bits/stdc++.h>
using namespace std;

// you have to print the length of shortest comman sub-sequence
// Trick: 
// total length of string - comman length of sub string of each string
// ( m + n ) - LCS()

int LCS(string s1, string s2, int m, int n) {

    vector < vector<int>> dp(m + 1, vector<int>(n+1, 0));

    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(
                    dp[i-1][j],
                    dp[i][j-1]
                );
            }
        }
    }

    return dp[m][n];
}

int SCS(string s1, string s2, int m, int n) {

    return m + n - LCS(s1, s2, m, n);
}

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    cout << SCS(s1, s2, s1.length(), s2.length()) << endl;
    // cout << LCS(s1, s2, s1.length(), s2.length()) << endl;
    
    return 0;
}