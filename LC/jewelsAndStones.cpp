#include <bits/stdc++.h>
using namespace std;
int numJewelsInStones(string jewels, string stones) {
    unordered_map<char, int> hash;
    for(auto s: stones) {
        hash[s]++;
    }
    int ans = 0;
    for (auto &&i : jewels)
    {
        if(hash.find(i) != hash.end()) {
            ans += hash[i];
        }
    }
    return ans;
}
int main()
{
    string jewels = "aA";
    string stones = "aAAbbbb";
    cout << numJewelsInStones(jewels, stones) << endl;
    
    
    return 0;
}