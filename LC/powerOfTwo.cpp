#include <bits/stdc++.h>
using namespace std;

bool powerOfTwo(int n) {
    int x = log2(n);
    return pow(2, x) == n; 
}

int main()
{
    for (int i = 0; i < 65; i++)
    {
        cout << i << " " << powerOfTwo(i) << endl;
    }
        
    return 0;
}