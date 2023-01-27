#include <bits/stdc++.h>
using namespace std;

int miniFlipsMonoIncr(string s) {
    int ones = 0;
    int flips = 0;
    for (auto &&i : s)
    {
        if(i == '1') ones++;
        else flips++;
        flips = min(flips, ones);
    }
    return flips;
}

int main()
{
    string s = "00110";
    cout << miniFlipsMonoIncr(s) << endl;
    return 0;
}