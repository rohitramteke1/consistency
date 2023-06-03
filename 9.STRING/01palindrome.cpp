#include <bits/stdc++.h>
using namespace std;

// O(N)
bool isPalindrome(string &s) {
    int i=0, n = s.length();

    for (int i=0; i<n/2; i++) {
        if (s[i] != s[n-1-i])
            return false;
    }

    return true;
}

int main()
{
    string s = "radar";
    cout << isPalindrome(s) << endl;

    return 0;
}