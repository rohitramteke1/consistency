#include <iostream>
using namespace std;

void poweSet(string s, string curr, int i) {
    if(s.length() == i)
    {
        cout << curr << ' ';
        return;
    }
    // take
    poweSet(s, curr + s[i], i+1);
    // notake
    poweSet(s, curr, i+1);
}

int main()
{
    poweSet("abc", "", 0);
    
    return 0;
}