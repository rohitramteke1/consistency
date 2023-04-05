#include <bits/stdc++.h>
using namespace std;

int power(int x, int n) {
    long long int res = 1;

    while(n) {
        if(n & 1)
            res *= x;
        x *= x;
        n = n >> 1;
    }

    return res;
}

// there is pattern for this, just crack that pattern,
// & you'll get the answer

int countOfAllSetBits(int n) {
    // base case
    if(n <= 1)
        return n;

    // pattern, formula
    int x = log2(n);
    // totalSetBits = x * 2^(x-1) + (n - 2^x + 1) + repeat(n - 2^x)

    int power2x = power(2, x-1);

    return x * power2x + (n - power2x * 2 + 1) + countOfAllSetBits(n - power(2, x));
}

int main()
{
    cout << countOfAllSetBits(17) << endl; 
    return 0;
}