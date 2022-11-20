// Print SCS between 2 strings

#include <bits/stdc++.h>
using namespace std;

string printSCS(string s1, string s2, int m, int n) {

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

    int i = m;
    int j = n;
    string ans;
    while(i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1])
        {
            ans.push_back(s1[i-1]); i--; j--;
        }
        else {
            if(dp[i][j-1] > dp[i-1][j]) {
                ans.push_back(s2[j-1]);
                j--;
            } 
            else {
                ans.push_back(s1[i-1]);
                i--;
            }
        }
    }

    while(i > 0) {
        ans.push_back(s1[i-1]);
        i--;
    }
    while(j > 0) {
        ans.push_back(s2[j-1]);
        j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s1 = "abcde";
    string s2 = "abcfe";
    cout << printSCS(s1, s2, s1.length(), s2.length()) << endl;
    
    return 0;
}