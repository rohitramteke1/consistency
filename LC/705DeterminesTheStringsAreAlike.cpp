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

int main()
{
    string s = "botk";
    cout << is_halves_are_alike(s);
    return 0;
}