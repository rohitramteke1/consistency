// Naive Pattern Searching
#include <bits/stdc++.h>
using namespace std;

// O(N - M + M)
// Only iff when the pattern contains unique character's
bool searchPattern(const string &str, const string &pattern)
{
    int n = str.length();
    int m = pattern.length();
    
    for (int i=0; i<n-m+1; ) {
        int j=0;
        for ( ; j<m; j++) {
            if (str[i + j] != pattern[j]) 
                break;
        }
        if (j == m)
            cout << j << ' ';
        if (j == 0)
            i++;
        else
            i = i + j;
    }
    
    return 0;
}

int main()
{
    string s = "ABCEABCD";
    string pattern = "ABCD";

    searchPattern(s, pattern);
    
    return 0;
}
