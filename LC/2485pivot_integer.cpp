#include <bits/stdc++.h>
using namespace std;

int pivot(int n) {
    int ans = (n * n + n)/2;
    int sq = sqrt(ans);
    return sq*sq == ans ? sq : -1;
}

int main()
{
    cout << pivot(8) << endl;
    s();
    return 0;
}