#include <bits/stdc++.h>
using namespace std;

string _reverse(string s) {
    for (int i = 0; i < s.length()/2; i++)
        swap(s[i], s[s.length() - 1 -i]);
    return s;
}

// minimum no of insertion to make a string palindrome
int minimum_no_insertion(string &s1, string &s2, int m, int n) {
    vector< vector<int> > dp( m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
        }
    }
    
    return dp[m][n];
}

int main()
{
    string s1 = "aebcbda";
    string s2 = _reverse(s1);
    int lcs = minimum_no_insertion(s1, s2, s1.length(), s2.length()) ;
    cout << "Minimum no of insertions: " << s1.length() - lcs<< endl;
    return 0;
}