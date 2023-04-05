#include <bits/stdc++.h>
using namespace std;

// TC: O(logN) + SC: O(logN)
int powerRec(int x, int n) {
    if(n == 0) 
        return 1;
    int temp = powerRec(x, n/2);
    temp = temp * temp;
    if(n % 2 == 0) {
        return temp;
    }
    else {
        return temp * x;
    }
}

// Binary Exponentiation
// TC: O(logN) + SC: O(1)
int power(int x, int n) {
    long long res = 1;

// GFG Approach
    while(n) {
        if(n & 1) {
            res = res * x;
        }
        x = x * x;
        n = n >> 1;
    }

// Striver's approach
    // while(n) {
    //     if(n % 2 == 0) {
    //         x = x * x;
    //         n = n/2; 
    //     }
    //     else {
    //         n--;
    //         res = x * res;
    //     }
    // }

    return res;
}

int main()
{
    int x, n; cin >> x >> n;
    
    cout << power(x, n) << endl;
    cout << powerRec(x, n) << endl;

    return 0;
}