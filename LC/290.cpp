// New Year 1st Problem and Unable to solve
// finally solved on 11.35Pm of 1st january 2023
#include <bits/stdc++.h>
// #include <sstream>
// #include <string>
// #include <iostream>
// #include <unordered_map>
using namespace std;


vector<string> split(string s) {
    stringstream ss(s);
    vector<string> v;
    while(ss >> s) {
        v.push_back(s);
    }
    return v;
}

int solve(string pattern, string s) {
    // TC: O(N)
    // SC: O(N)
    unordered_map<char, string> umap;
    unordered_set<string> uset;
    vector<string> v = split(s);
    // a b b a
    // cat dog dog cat
    for (int i = 0; i < pattern.size(); i++)
    {
        if(umap.find(pattern[i]) == umap.end() && uset.find(v[i]) == uset.end())
        {
            umap[pattern[i]] = v[i];
            uset.insert(v[i]);
        }
        else {
            if(umap[pattern[i]] != v[i]) {
                return false;
            }
        }
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