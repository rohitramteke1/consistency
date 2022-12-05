#include <bits/stdc++.h>
using namespace std;

bool isCircular(string sentence) {

    stringstream s(sentence);
    string word;

    char prevWordLastChar;
    bool firsTime = true;
    char firstWordChar;
    while(s >> word) {
        if(firsTime) {
            firstWordChar = *word.begin();
            prevWordLastChar = *(word.end()-1);
            firsTime = false;
            continue;
        }
        if(prevWordLastChar != *word.begin() ) return false;
        else prevWordLastChar = *(word.end()-1);
    }
    return firstWordChar == prevWordLastChar;
}

int main()
{
    cout << isCircular("aeetcode ea");
    
    return 0;
}