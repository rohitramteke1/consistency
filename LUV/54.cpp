#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
static int ct = 0;
// return (a ^ b)
int binExpRecur(int a, int b) {
    if(b == 0) return 1;
    int res = binExpRecur(a, b/2);
    if(b & 1){
        return (a * 1LL * (res * 1LL * res) % M) % M;
    }
    else {
        return (res * 1LL * res) % M;
    }
}

int main()
{
    cout << binExpRecur(2, 40) << endl;
    cout << ct << endl;
    return 0;
}