#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch) {
    return (
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
        ch == 'A'+32 || ch == 'E'+32 || ch == 'I'+32 || ch == 'O'+32 || ch == 'U'+32
    );
}

int countVowels(string s) {
    return count_if(s.begin(), s.end(), isVowel);
}
bool isHalvesAreAlike(string s) {
    return 
        countVowels(s.substr(0, s.size()/2 ) ) 
            == 
        countVowels(s.substr(s.size()/2, s.size() ) );
}

int main()
{
    string s = "arigatoa";
    cout << isHalvesAreAlike(s);
    
    return 0;
}