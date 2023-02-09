// anagrams: all possible rearrangement of given strings
// string s = "abcabdef" p = "abc"
// p = abc
// p = bca
// p = cab
// LC: find all anagrams
#include <bits/stdc++.h>
using namespace std;
vector<int> findAnagrams(string s, string p) {
    int n = s.length();
    int k = p.length();
    vector<int> v1(26, 0);
    vector<int> v2(26, 0);
    vector<int> result;

    // hashmap for string p
    for(auto &&i : p) { 
        v1[i - 'a']++;
    }

    int i = 0, j = 0;

    while(j < n) {
    // hashing for s string
        v2[ s[j] - 'a' ]++;

    // window formed
        if(j - i + 1 == k) {
            if(v2 == v1)
                result.emplace_back(i);
        }
    // make window
        if( j - i + 1 < k) {
            j++;
        }
    // slide the window
        else {
            v2[ s[i] - 'a']--;
            i++, j++;
        }
    }

    return result;
}
int main()
{
    string s = "cbaebabacd";
    string p = "abc";

    vector<int> v;
    v = findAnagrams(s, p);

    for (auto &&i : v)
        cout << i << ' ';
    
    
    return 0;
}