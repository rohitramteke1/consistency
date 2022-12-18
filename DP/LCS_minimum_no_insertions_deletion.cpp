// minimum no of insertion and deletion 
// to convert string a to string b
// Link: https://youtu.be/-fx6aDxcWyg?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go


#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    string s1 = "leetcode";
    string s2 = "etco";
    int lcs = LCS(s1, s2, s1.length(), s2.length());
    cout << "LCS: " << lcs << endl;
    cout << "Insertion: " << s1.length() - lcs << endl;
    cout << "Deletion: " << s2.length() -lcs << endl;
    
    return 0;
}