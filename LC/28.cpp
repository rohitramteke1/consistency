#include <bits/stdc++.h>
using namespace std;


// Best Algo KMP


int solve(string haystack, string needle) {
 
    if(needle.size() > haystack.size())
        return -1;
    
    int n = needle.size();
    string temp = "";
    for (int i = 0; i < haystack.size(); i++)
    {
        temp = haystack.substr(i, n);
        cout << temp << ' ' << needle << endl;
        if(temp == needle)
            return i;
    }
    
    return -1;
}

int main()
{
    string s = "1sadbutsad";
    string t = "sad";
    solve(s, t);
    return 0;
}