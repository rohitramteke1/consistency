// Facebook 4th most asked que.

#include <bits/stdc++.h>
using namespace std;
string addBinary(string a, string b) {
    int i = 0;
    int alen = a.length();
    int blen = b.length();
    string result = "";
    int carry = 0;
    while (i < alen || i < blen || carry != 0)
    {
        short x = 0;
        if(i < alen && a[alen - i - 1] == '1') x = 1;
        short y = 0;
        if(i < blen && b[blen - i - 1] == '1') y = 1;

        result.push_back(((x + y + carry) % 2 ) + 48);
        
        carry = (x + y + carry) / 2;
        i++;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string a = "11";
    string b = "1";

    cout << addBinary(a, b) << endl;

    return 0;
}