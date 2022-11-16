#include <bits/stdc++.h>
using namespace std;

double log_a_to_base_b(int a, int b) {
    return (log2(a)/log2(b));
}

int main()
{   
    int n = 45;
    int b = 3;
    double res = log_a_to_base_b(n, b);
    cout << res << endl;
    double no = pow(3, (int)res);
    cout << no << ' ' << n << endl;

    
    return 0;
}