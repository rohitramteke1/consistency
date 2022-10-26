#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <sstream>
using namespace std;

int countWords(string str) {
    stringstream s(str);
    string word;
    int count = 0;
    while (s >> word) count++;
    return count;
}

void frequencyOfWords(string str) {
    map<string, int> fow;
    stringstream s(str);
    string word;
    while (s >> word)
    {
        fow[word]++;
    }
    map<string, int>::iterator iter;
    for(iter=fow.begin(); iter != fow.end(); iter++) {
        cout << iter->first << ' ' << iter->second << endl;
    }
}

int main()
{
    string str = "CPP CPP CPP C Python Java Java Carbon HTML CSS CSS JS";
    frequencyOfWords(str);
    cout << "no of words: " << countWords(str) << endl;
    return 0;
}