#include <bits/stdc++.h>
using namespace std;

int noOfBits(int n) {
    return floor(log2(n)) + 1;
}
int bitwiseComplement(int n) {
    // int bit = noOfBits(n);
    int bit = floor(log2(n)) + 1;
    
    // return ((1 << bit) - 1) ^ n;
    return ((1 << bit) - 1) - n;
}

int main()
{
    cout << bitwiseComplement(8) << endl;
    return 0;
}