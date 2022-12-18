#include <bits/stdc++.h>
using namespace std;

inline int gcd(int a, int b) {
    if(a % b == 0) return b;
    return gcd(b, a%b);
}
inline int _gcd(int a, int b) {
    while(a % b != 0) {
        a = b;
        b = a % b;
    }
    return b;
}

int main()
{
    cout << gcd(12, 4) << endl;
    cout << _gcd(12, 4) << endl;
    return 0;
}