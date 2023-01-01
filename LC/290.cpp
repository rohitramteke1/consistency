// New Year 1st Problem and Unable to solve
#include <bits/stdc++.h>
// #include <sstream>
// #include <string>
// #include <iostream>
// #include <unordered_map>
using namespace std;

int solve(string pattern, string s) {
    unordered_map<char, string> umap;
    unordered_map<string, bool> flag;

    stringstream ss(s);
    s = "";
    int i = 0;
    while(ss >> s && i < pattern.length()) {

        if(flag.find(s) == flag.end()) {
            flag[s] = true;
            if(umap.find(pattern[i]) == umap.end()) {
                umap[pattern[i]] = s;
            }
        }
        else {
            if(umap.find(pattern[i]) == umap.end()) {
                return false;
            }
            else {
                if(umap[pattern[i]] != s) return false;
            }
        }
        i++;
    }
    return true;
}

int main()
{
    string s, pattern;
    getline(cin, pattern);
    getline(cin, s);
    cout << solve(pattern, s) << endl;
    return 0;
}