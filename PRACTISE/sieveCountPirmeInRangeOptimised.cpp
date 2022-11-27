#include <bits/stdc++.h>

const int N = 2e5+10;
bool p[N];
bool static flag = false;

class Solution {
  public:
    void prime(int n)
    {
        flag = true;
        for(int i=2; i<=N; i++) {
            p[i] = 1;
        }
        // O(N * log (logn) )
        for (int i = 2; i * i <= N; i++)
            if (p[i])
                for (int j = i * i; j <= N; j = j + i)
                    p[j] = false;
    }

    int countPrimes(int L, int R) {
        // code here
        if(!flag) prime(N);
        int ct = 0;
        for (int i = L; i <= R; i++)
            if (p[i])
                ct++;
        return ct;   
    }
};