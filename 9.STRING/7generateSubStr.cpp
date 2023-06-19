#include <iostream>
#include <string>
using namespace std;

int power(int x, int n) {
    long long res = 1;

    while (n) {
        if (n & 1) {
            res = res * x;
            n--;
        }
        else {
            x = x * x;
            n = n / 2;
        }
    }
    return res;
}

void generateSubStr(const string& s, const string& str) {
    int len = s.length();
    int n = s.length();

    int _pow = power(2, len);
    for (int j=0; j<_pow; ++j) {

        string substr = "";
        for (int i=0; i<n; ++i) {
            if (j & (1 << i)) 
                substr.push_back(s[i]);
        }

        if ( substr == str) {
            cout << "YES" << endl;
            return;   
        }
    }
    cout << "NO" << endl;
}

// using DP
void usingDP(const string &s, string str, int i) {
    if (i >= s.length()) {
        cout << str << endl;
        return;
    }
    usingDP(s, str + s[i],  i + 1);
    usingDP(s, str,  i + 1);
}

// check if it is the subsequence or not
bool isSubSeq(const string &s, const string &sub) {
    int i = 0, j = 0;
    int n = s.length();
    int m = sub.length();

    for( ; i < n; i++) {
        if (s[i] == sub[j])
            j++;
        
    }

    return (j == m);
}

// recursive of the above
bool isSubSeqRec(const string &s, const string &str, int i, int j) {
    if ( j <= 0)
        return 1;
    if (i < 0)
        return 0;
    bool f = 0, g = 0;

    if (s[i] == str[j]) 
        f = isSubSeqRec(s, str, i - 1, j - 1);
    else 
        g = isSubSeqRec(s, str, i - 1, j);
    return f || g ;
}



int main() {
    string s = "geeksforgeeks";
    string str = "fgee";
    // generateSubStr(s, str);
    // usingDP(s, "", 0);

    cout << isSubSeq(s, str) << endl;
    cout << isSubSeqRec(s, str, s.length(), str.length()) << endl;

    return 0;
}
