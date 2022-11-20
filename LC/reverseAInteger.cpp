#include <bits/stdc++.h>
using namespace std;

int _rev(int n) {
    int no = n;
    long rev = 0;
    int rem = 0;
    while(n) {
        rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }
    if(rev > INT_MAX/2 - 1 && rev < INT_MIN/2)
        return 0;
    return rev;
}

int main()
{
    cout << _rev(-123) << endl;
    
    return 0;
}