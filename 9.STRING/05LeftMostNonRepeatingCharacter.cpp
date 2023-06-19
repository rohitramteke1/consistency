#include <bits/stdc++.h>
using namespace std;

// Brute Force + Hashing
void leftMost(const string &s) {
    int n = s.length();

    vector<int> mp(26, 0);

    // O(N)
    for (int i=0; i<n; i++) {
        mp[ s[i] - 'a']++;
    }
    // O(N)
    for (int i=0; i<n; i++) {
        if (mp[s[i] - 'a'] == 1)
            cout << s[i] << endl;
    }
    // O(2N) ~= O(N) + O(1)
}


// Optimisation
void leftMostOptimised(const string &s) {
    int n = s.length();

    vector<int> mp(26, -1);

    // states 
    // -1 for not present
    //  index    1 times
    // -2     more than 1 times

    for (int i=0; i<n; i++) {
        int index = s[i] - 'a';

        if ( mp[index] == -1 )
            mp[index] = i;
        else
            mp[index] = -2;
    }

    int ans = -3;
    for (int i=0; i<26; i++) {
        if (mp[i] >= 0) {
            ans = min(ans, mp[i]);
        }
    }

    cout << s[ans] << endl;
}


// stringstream O(N) + O(N)
void reverseWords(const string &sentence) {
    int len = sentence.length();
    stringstream ss(sentence);
    string word;

    while (ss >> word) {
        reverse(word.begin(), word.end());
        cout << word << endl;
    }
}

// better O(N)
void reverseWordsBetter(string s) {
    s.push_back(' ');
    int n = s.length();
    int start = 0, end = 0;

    for ( ; end < n; end++) {

        if (s[end] == ' ') {
            reverse(s.begin() + start, s.begin() + end);
            while(s[end] == ' ') end++;
            start = end;
        }

    }
    s.pop_back();
    cout << s << endl;
}


int main()
{
    string s = "geeksforgeeks";
    leftMostOptimised(s);
    reverseWordsBetter("Hello  world from another world");
    return 0;
}