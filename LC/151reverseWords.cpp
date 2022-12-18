#include <bits/stdc++.h>
using namespace std;
// Reverse the words in string

int main()
{
    string s = "the sky is blue";
    stringstream str(s);
    string word;
    vector<string> ans;

    while(str >> word) {
        ans.emplace_back(word);
    }
    word = "";
    for(auto itr = ans.rbegin(); itr != ans.rend(); itr++) {
        word += *itr + " ";
    }
    cout << word.length() << endl;
    word = word.substr(0, word.length()-1);
    cout << word.length() << endl;
    cout << word << endl;
    
    return 0;
}