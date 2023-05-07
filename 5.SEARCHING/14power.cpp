#include <bits/stdc++.h>
using namespace std;

int powerOfN(int x, int n) {
    int power = 1;
    int res = 1;

    while (n) {
        if (n & 1) {
            res = res * x;
            n--;
        }
        else {
            x = x * x;
            n = n / 2;
        }
    }

    return res;
}

int main()
{
    cout << powerOfN(2, 5) << endl;
    
    return 0;
}