#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strings) {
    if(strings.empty()) return "";
    for (int i = 0; ; ++i) {
        // char c = strings.front()[i];
        for (auto s : strings) {
            if(strings.front()[i] != s[i] || i >= s.length())
                return strings.front().substr(0, i);
        }
    }
}

int main()
{
    vector<string> strs = {"flower","flow","flight"};

    cout << longestCommonPrefix(strs) << endl;

    return 0;
}