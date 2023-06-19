// Naive Pattern Searching
#include <bits/stdc++.h>
using namespace std;

bool searchPattern(const string &str, const string &pattern)
{
    int n = str.length();
    int m = pattern.length();
    int rollingHash = 0, patternHash = 0;

    for (int i=0; i<m; i++) {
        patternHash += pattern[i] - 'a' + 1;
        rollingHash += str[i] - 'a' + 1;
    }
    
    for (int i=0; i<n-m+1; i++) {

        // do the pattern matching
        if (patternHash == rollingHash) {
            int j = 0;
            for ( ; j < m; j++)
                if ( str[i + j] != pattern[j] )
                    break;
            if (j == m)
                cout << "Pattern: " << i << ' ';
        }
        rollingHash = rollingHash - (str[i] - 'a' + 1) + (str[i + m] - 'a' + 1);
    }
    
    return 0;
}

int main()
{
    string s = "abceabcd";
    string pattern = "abcd";

    searchPattern(s, pattern);
    
    return 0;
}
