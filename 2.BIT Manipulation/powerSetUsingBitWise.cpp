#include <bits/stdc++.h>
using namespace std;

// Binary exponentiation
// log2(n)
int power(int x, int n) {
    int res = 1;
    while(n) {
        if(n & 1) {
            res = res * x;
        }
        n = n >> 1;
        x = x * x;
    }
    return res;
}

vector<string> powerSet(string  s) {
    vector<string> res;
    int n = s.length();
    int power2n = power(2, n);

    for (int i = 0; i < power2n; i++)
    {
        string substr;
        for(int j = 0; j < n; j++) {
            if( (1 << j) & i )
                substr.push_back(s[j]);
        }
        cout << substr << endl;
        res.push_back(substr);
    }

    return res;
}

int main()
{
    string s = "abc";

    powerSet(s);
    
    return 0;
}