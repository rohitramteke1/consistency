#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
int p[N];

void prime(int n) {

    for (int i = 2; i*i <= n; i++)
    {
        if(p[i]) {
            for (int j = i*i; j <= n; j = j+i)
            {
                p[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if(p[i])
            cout << i << ' ';
    }
    
}

int main()
{
    // int n = 10; cin >> n;
    // memset(p, 1, sizeof(p));

    for (int i = 2; i <= N; i++)
    {
        p[i] = 1;
    }
    
    prime(100);
    
    
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

// const int N = 5e6+10;
// bool p[N];

int *prime(int n)
{
    int *p = new int[n + 1];
    p[0] = p[1] = false;
    for (int i = 2; i < n; i++)
        p[i] = 1;

    // O(N * log (logn) )
    for (int i = 2; i * i <= n; i++)
        if (p[i])
            for (int j = i * i; j <= n; j = j + i)
                p[j] = false;
    return p;
}

int main()
{
    // for (int i = 2; i < N; i++) p[i] = true;

    int n;
    cin >> n;
    int *p = prime(n);
    for (int i = 2; i <= n; i++)
        if (p[i])
            cout << i << ' ';
    return 0;
}
*/