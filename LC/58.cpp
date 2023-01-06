#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s) {

    if(s.length() == 1)
        if(s[0] != ' ') return 1;
        else return 0;

    int i = s.length()-1;
    while(s[i] == ' ') --i;
    if( i == -1) return 0;
    cout << i << endl;
    int len = 0;
    bool firstTime = false;
    for(int k=i; k >= 0; --k) {
        cout << s[k] << ' ';
        if(s[k] == ' '){
            return len;
        }
        else {
            ++len;
        }
    }
    return len;
}

int main()
{
    string s = "a ";
    cout << lengthOfLastWord(s) << endl;
    
    return 0;
}