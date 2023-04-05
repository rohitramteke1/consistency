#include <bits/stdc++.h>
using namespace std;

// better
bool isPowerOfTwo(int n) {
    return n & (n-1);
}

// brute
bool brute(int n) {
    int power = log2(n);
    return pow(2, power) == n;
}

// power of 3
int powerOfThree(int N) {
    int power = -1;
    int n = N;
    while(n) {
        n = n/3;
        power++;
    }
    cout << power << ' ' << N << endl;
    return pow(3, power) == N;
}

int powOf3(int n) {
    int log3n = log2(n)/log2(3);

    return pow(3, log3n) == n;
}

// GFG trick Sandeep Jain Another Method
// this method can be used for to check any isPower Of any
bool isPowerOfT3(int n) {
    while(n != 1) {
        if(n % 3 != 0) {
            return false;
        }
        n = n / 3;
    }
    return true;
}

int main()
{
    // cout << isPowerOfTwo(4) << endl;
    // cout << isPowerOfTwo(9) << endl;
    // cout << isPowerOfTwo(16) << endl;
    // cout << isPowerOfTwo(15) << endl;
    // cout << brute(16) << endl;
    cout << powerOfThree(3) << endl;
    cout << powOf3(27) << endl;
    cout << isPowerOfT3(27) << endl;
    
    return 0;
}