#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s) {
    string ans = "";
    // TC: O(N * N)
    // SC: O(N)
    for (int i = 0; i < s.length(); i++)
    {
        ans.push_back(s[i]);
        while (!ans.empty() && ans.back() == s[i+1])
        {
            ans.pop_back();
            i++;
        }
    }
    return ans;
}

int main()
{
    cout << removeDuplicates("abbaca") << endl;
    cout << removeDuplicates("azxxzy") << endl;
    
    return 0;
}