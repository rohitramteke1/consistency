#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;


ll reverse(int n) {
    int rev = 0;
    while(n) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}


int p(int x, int n) {
    if(n == 0)
        return 1;
    int temp = x;
}

ll power(int X, int n) {
    ll ans = 1;
    ll x = X;
    while(n) {
        if(n & 1)
        {
            ans = ( (ans % M) * (x % M)) % M;
            n--;
        }
        else {
            n = n / 2;
            // here when the x is very very large, close to int value, then
            // at that time the it gets out of range (INT Overflow...)
            // so that's why we need the larger data type to prevent the INT OVERLFLOW...
            x = ((x % M) * (x % M)) % M;
        }
        cout << x << ' ' << ans << endl;
    }
    return ans;
}

int main()
{
    cout << power(12, 21) << endl;
    
    return 0;
}