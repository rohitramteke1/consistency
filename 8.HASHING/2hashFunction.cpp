#include <bits/stdc++.h>
using namespace std;

int hashOnInt(int value, int m) {
    int key = value % m;
    return key;
}

int hashOnString(string s, int x, int m) {
    int key = 0;
    for (int i=0; i<s.length(); i++) {
        key += s[i] * pow(x, i);
    }
    return key % m;
}

int main()
{
    string s = "abcd";
    int m = 231;
    int x = 33;
    int data = 12;

    cout << hashOnString(s, x, m) << endl;
    cout << hashOnInt(data, m) << endl;

    return 0;
}