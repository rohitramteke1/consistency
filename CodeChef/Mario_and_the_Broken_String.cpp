#include <bits/stdc++.h>
using namespace std;

bool solution() {
    bool res = false;
        string s;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            char ch; cin >> ch;
            s.push_back(ch);
        }
        cout << s << endl;
        int len = s.length();
        string s1 = s.substr(0, len/2), s2 = s.substr(len/2);

    // cout << s1 << " " << s2 << endl;

    return (s1+s2 == s2+s1);
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        solution() == 1 ? cout << "YES\n" : cout << "NO\n"; 
    }
    return 0;
}