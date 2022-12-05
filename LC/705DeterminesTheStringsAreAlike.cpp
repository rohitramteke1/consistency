#include <bits/stdc++.h>
using namespace std;

bool is_halves_are_alike(string s) {

    string vowels = "aeiouAEIOU";
    unordered_map<char, int> hash_map;

    for (int i = 0; i < 10; i++) hash_map[vowels[i]] = true;
    int i=0, j=s.size()-1;
    int rightVowel = 0;
    int leftVowel = 0;

    while(i<j) 
    {
        if(hash_map.find(s[i]) != hash_map.end()) leftVowel++;
        if(hash_map.find(s[j]) != hash_map.end()) rightVowel++;
        i++;
        j--;
    }
    
    return leftVowel == rightVowel;
}
/*
    static bool halvesAreAlike(string_view s) noexcept {
        return vowelCount(s.substr(0, size(s) / 2)) == vowelCount(s.substr(size(s) / 2));
    }
	
    static int vowelCount(string_view s) noexcept {
        return count_if(begin(s), end(s), isVowel);
    }

    static bool isVowel(char ch) noexcept {
        return
            ch == 'a' || ch == 'e' || ch == 'i'  || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I'  || ch == 'O' || ch == 'U' ;
    }
*/

int main()
{
    string s = "botk";
    cout << is_halves_are_alike(s);
    return 0;
}