#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, i;
    cin >> a;
    for (i = 0; i * i <= a; i++);
    cout << endl << i-1 << endl;
    
    return 0;
}