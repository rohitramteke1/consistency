#include <bits/stdc++.h>
using namespace std;

// leetcode-13
int romanToInteger(string s)
{
    int integer = 0;
    unordered_map<char, int> hash = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};
    // int sum = 0;
    int len = s.length();
    for (int i = 0; i < len;)
    {
        if ((hash[s[i]] >= hash[s[i+1]]) )
        {
            integer += hash[s[i]];
            i++;
        }
        else
        {   
            integer += hash[s[i+1]] - hash[s[i]];
            i += 2;
        }
    }
    return integer;
}

int main()
{
    string roman = "MCMXCIV";
    cout << romanToInteger(roman);

    return 0;
}