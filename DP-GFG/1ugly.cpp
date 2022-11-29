#include <bits/stdc++.h>
using namespace std;

int checkForUgly(int n, int a) {
    while(n % a == 0) {
        n = n/a;
    }
    return n;
}

int isUgly(int n) {
    int no = n;
    no = checkForUgly(no, 2);
    no = checkForUgly(no, 3);
    no = checkForUgly(no, 5);
    return no == 1 ? 1 : 0;
}

int nthUgly(int n) {
    int dp[n+1];
    int p2 = 1;
    int p3 = 1;
    int p5 = 1;
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        int f2 = dp[p2] * 2;
        int f3 = dp[p3] * 3;
        int f5 = dp[p5] * 5;
        
        int __min = min(f2, min(f3, f5));
        dp[i] = __min;
        if(__min == f2) p2++;
        if(__min == f3) p3++;
        if(__min == f5) p5++;
    }
    
    return dp[n];
}

int main()
{
    int i = 1;
    int count = 1;
    int n = 150;
    while(count < n) {
        i++;
        if(isUgly(i)) count++;
    }
    cout << i << endl;
    cout << nthUgly(10) << endl;
    return 0;
}