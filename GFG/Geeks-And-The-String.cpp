#include <bits/stdc++.h>
using namespace std;

bool containsAdjacent(string &s) {
    for (int i = 0; i < s.length(); i++)
    {
        if(i+1 < s.length() && s[i] == s[i+1]) {
            return true;
        }
    }
    return false;
}

string removePair(string s) {
    // code here
    int n = s.length();
    for (int i = 1; i < n;)
    {
        if(s[i] == s[i-1]) {
            s[i] = ' ';
            s[i-1] = ' ';
            i+= 2;
        }
        else {
            i++;
        }
    }
    
    string result;
    for (auto &&i : s)
    {
        if(i != ' ') {
            result.push_back(i);
        }
    }
    
    if(containsAdjacent(result)) {
        goto lb;
    }

    return result == "" ? "-1" : result;
}

int main()
{
    string s = "xiiccccssxxxgggww";
    s = removePair(s);
    cout << s << endl;
    cout << containsAdjacent(s);
    
    return 0;
}