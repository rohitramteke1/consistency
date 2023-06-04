#include <iostream>
#include <string>
#include <algorithm> // reverse()
#include <sstream> // stringstream

using namespace std;

// Brute force O(N)
void reverseWords(string &s) {
    stringstream ss(s);
    string word;
    string res = "";
    
    while ( getline(ss, word, '.') ) {
        res = word + '.' + res;
    }
    res.pop_back();
    cout << res << endl;
}

// Efficient Solution 
class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        int start = 0, end = 0;
        int n = S.length();
        
        for ( ; end < n; end++) {
            if ( S[end] == '.' ) {
                reverse(S.begin() + start, S.begin() + end);
                start = end + 1;
            }
        }
        // last remainig word
        reverse( S.begin() + start, S.begin() + n );
        reverse( S.begin(), S.end() );
        
        return S;
    } 
};

int main()
{
    string s = "welcome.to.hello.world";
    
    reverseWords(s);

    return 0;
}