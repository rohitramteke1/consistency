#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int prefix[N];
int ones = 0;

int solve(int n) {
    int cnt = 0;
    while(n) {
        int rem = n % 10;
        if(rem == 1)
            cnt++;
        n /= 10;
    }
    return prefix[n] = cnt;
}

int countOnes(int n) {
    prefix[0] = 0;
    prefix[1] = 1;

    for (int i = 2; i <= n; i++)
        prefix[i] = prefix[i-1] + solve(i);

    return prefix[n];
}
// failed 
// 0 <= n <= 1e9
int main()
{
    cout << countOnes(13) << endl;
    
    return 0;
}