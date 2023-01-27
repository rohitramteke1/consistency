#include <bits/stdc++.h>
using namespace std;

bool isConcatenated(string word, unordered_set<string> &st) {

    int len = word.length();

    for (int i = 0; i < len; i++)
    {
        string prefix = word.substr(0, i+1);
        string suffix = word.substr(i+1);

        if( (st.find(prefix) != st.end() && st.find(suffix) != st.end()) || 
            (st.find(prefix) != st.end() && isConcatenated(suffix, st)) ) 
            return true;
    }

    return false;
}

vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    unordered_set<string> st(begin(words), end(words));
    vector<string> result;

    for (auto &&word : words)
    {
        if(isConcatenated(word, st)) {
            result.push_back(word);
        }
    }
    
    return result;
}

int main()
{
    vector<string> words = {
        "cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"
    };

    words = findAllConcatenatedWordsInADict(words);

    for (auto &&i : words)
    {
        cout << i << endl;
    }
    
    return 0;
}