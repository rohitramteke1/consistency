#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++) cout << j+1 << ' ';
        for( int j = n-1; j > i; j--) cout << "  ";
        for( int j = n-1; j > i; j--) cout << "  ";
        for (int j = i; j >= 0; j--) cout << j+1 << ' ';
        cout << endl;
    }
    return 0;
}
/*
5
1                 1
1 2             2 1
1 2 3         3 2 1
1 2 3 4     4 3 2 1
1 2 3 4 5 5 4 3 2 1
*/