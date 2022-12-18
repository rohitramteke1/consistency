#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "-91283472332";
    long long ans = 0;
    bool neg = false;
    for (int i = 0; i < s.length(); i++)
    {
        if(i+1 != s.length() && s[i] == '-' && isdigit(s[i+1]))
            neg = true;
        else if(isdigit(s[i])){
            ans = ans * 10LL + int(s[i]-'0') + 0LL;
            if(ans <= INT_MIN || ans >= INT_MAX)
            {
                ans = ans > 0 ? INT_MAX : INT_MIN;
                break;
            }

        }
    }
    ans = neg ? ans*(-1) : ans;
    cout << ans << endl;

    // cout << isalpha(9) << endl;
    
    return 0;
}