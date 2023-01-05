#include <bits/stdc++.h>
using namespace std;

char to_lower(char ch) {
    if(ch >= 'A' && ch <= 'Z')
        return ch + 32;
    return ch;
}

string transform(string s) {
    string ans = "";
    int cnt = 1;
    // convert whole string to lowercase
    // for (int i = 0; i < s.length(); i++)
    //     s[i] = tolower(s[i]);

    s.push_back('#');

    for (int i = 0; i < s.length()-1; i++)
    {
        if( to_lower(s[i]) == to_lower(s[i+1]) )
        {
            cnt++;
        }
        else {
            ans += to_string(cnt);
            ans.push_back(to_lower(s[i]));
            cnt = 1;
        }
    }
    
    return ans;
}


int main()
{
    string s = "aaABBb";
    cout << transform(s) << endl;

    return 0;
}