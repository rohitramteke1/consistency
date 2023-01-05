#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<int, int > umap;
    for (int i = 0; i < s.length(); i++)
    {
        umap[s[i]]++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if(umap[s[i]] < 2) {
            return i;
        }
    }
    return -1;
}

int main()
{
    string s = "leetcode";
    cout << firstUniqChar(s) << endl;

    
    return 0;
}