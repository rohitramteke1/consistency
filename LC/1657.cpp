#include <bits/stdc++.h>
using namespace std;

bool closeStrings(string word1, string word2)
{
    if( word1.length() != word2.length()) return false;

    vector<int> v1(26, 0), v2(26, 0);
    vector<int> s1(26, 0), s2(26, 0);

    for (auto a : word1)
        v1[a - 'a']++, s1[a - 'a'] = 1;

    for (auto a : word2)
        v2[a - 'a']++, s2[a - 'a'] = 1;
    
    // what if the both string doesn't contain the same characters
    if(s1 != s2) return false;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    return v1 == v2;
}

int main()
{
    string word1 = "xxzzbbz";
    string word2 = "bbbzzxx";
    cout << closeStrings(word1, word2) << endl;

    return 0;
}