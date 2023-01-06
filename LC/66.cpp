#include <bits/stdc++.h>
using namespace std;

vector<int> addOne(vector<int> digits) {
    int prevCarry = 1;
    int currCarry = 0;
    reverse(digits.begin(), digits.end());
    int i = 0;
    do {
        currCarry = (prevCarry + digits[i]) / 10;
        digits[i] = (prevCarry + digits[i]) % 10;
        prevCarry = currCarry;
        i++;
    } while(prevCarry != 0 && i < digits.size());

    // for (int i = 0; i < digits.size(); i++)
    // {
    //     currCarry = (prevCarry + digits[i]) / 10;
    //     digits[i] = (prevCarry + digits[i]) % 10;
    //     prevCarry = currCarry;
    // }

    if(prevCarry != 0) digits.push_back(prevCarry);
    reverse(digits.begin(), digits.end());
    return digits;
}

vector<int> solve(vector<int> digits) {
    int i;
    for (i = digits.size()-1; i >= 0; i--)
    { 
        if(digits[i] < 9)
        {
            digits[i]++;
            break;
        }
        else digits[i] = 0;
    }
    if(i == -1){
        vector<int> v(digits.size() + 1, 0);
        v[0] = 1; 
        return v;
    }
    return digits;
}

int main()
{
    vector<int> digits = {9,9,9,9};
    vector<int> v1 = addOne(digits);
    vector<int> v2 = solve(digits);

    for (auto &&i : v1) cout << i << ' ';
    cout << endl;
    for (auto &&i : v2) cout << i << ' ';
    cout << endl;
    
    return 0;
}