// #include <iostream>
// #include <set>
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int b[N];
int main()
{
    set<int> s;
    int n; cin >> n;
    int m; cin >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]); // O(logN)
    }
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int c = 0;
    for (int i = 0; i < m; i++)
    {
        if(*s.find(b[i]) == b[i]) {
            c++;
        }
    } // O(M * log N)
    
    cout << "count: " << c << endl ;
    return 0;
}