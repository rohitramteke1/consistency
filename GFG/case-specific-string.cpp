#include <bits/stdc++.h>
using namespace std;
bool isUpper(char ch) {
    if(ch >= 65 && ch <= 90) {
        return true;
    }
    return false;
}
int main()
{
    string s = "defRTSersUXI";
    
    int n = s.length();
    string str_lowers;
    string str_uppers;
    
    for (auto &&i : s)
    {
        if(isUpper(i))
            str_uppers.push_back(i);
        else
            str_lowers.push_back(i);
    }

    sort(begin(str_lowers), end(str_lowers));
    sort(begin(str_uppers), end(str_uppers));


    int i = 0;
    int j = 0;
    int k = 0;
    while (k < n)
    {
        if(isUpper(s[k]))
            s[k] = str_uppers[i++];
        else 
            s[k] = str_lowers[j++];
        k++;
    }
    cout << s << endl;
    return 0;
}