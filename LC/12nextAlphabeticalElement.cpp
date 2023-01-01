#include <bits/stdc++.h>
using namespace std;

// next alphabetical element
char nextAlphabeticalElement(vector<char> letters, char target) {
    int low = 0;
    int high = letters.size();
    char ans = '#';
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(letters[mid] == target) {
            low = mid + 1;
        }
        else if(letters[mid] < target) {
            low = mid + 1;
        }
        else if(letters[mid] > target) {
            high = mid - 1;
            ans = letters[mid];
        }
    }
    return ans;
}

int main()
{
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'a';

    cout << nextAlphabeticalElement(letters, target) << endl;
    
    return 0;
}