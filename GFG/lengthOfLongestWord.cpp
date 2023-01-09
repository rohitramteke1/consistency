#include <bits/stdc++.h>
using namespace std;

string longestString(vector<string> &words)
{
    unordered_map<string, short> umap;
    for (auto &&word : words) 
        umap[word]++;
    sort(words.begin(), words.end());
    int len = 0;
    string ans;
    for(auto word: words) {
        int curr_len = 0;
        string temp = "";
        for (int i = 0; i < word.length(); i++)
        {
            temp.push_back(word[i]);
            if( umap.find(temp) != umap.end() )
            curr_len++;
        }
        if(curr_len == word.length() && curr_len > len)
        {
            len = curr_len;
            ans = word;
        }
    }
    return ans;
}

int main()
{
    vector< string > s = {"ab", "a", "abc", "abd"};
    cout << longestString(s);
    
    return 0;
}