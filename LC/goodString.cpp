#include <bits/stdc++.h>
using namespace std;

string goodString(string s) {
    string ans;
    for (int i = 0; i < s.size(); i++)
    {
        ans.push_back(s[i]);
        while(!ans.empty() && abs(ans.back() - s[i+1]) == 32) {
            ans.pop_back();
            i++;
        }
    }
    return ans;
}

int main()
{
    string s = "leEeetcode";
    
    // cout << s << endl;
    cout << goodString(s) << endl;

    return 0;
}