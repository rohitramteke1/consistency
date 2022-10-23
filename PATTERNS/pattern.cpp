#include <iostream>
#include <math.h>
using namespace std;
// int max(int lhs, int rhs) {
//     return (lhs < rhs) ? rhs : lhs;
// }

// 5
// 5 5 5 5 5 5 5 5 5
// 5 4 4 4 4 4 4 4 5
// 5 4 3 3 3 3 3 4 5
// 5 4 3 2 2 2 3 4 5
// 5 4 3 2 1 2 3 4 5
// 5 4 3 2 2 2 3 4 5
// 5 4 3 3 3 3 3 4 5
// 5 4 4 4 4 4 4 4 5
// 5 5 5 5 5 5 5 5 5

int main() 
{
    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    for (int i=0; i<2*n-1; i++) {
        for (int j=0; j<2*n-1; j++)
            cout << max(abs(n-1-i), abs(n-1-j))+1 << ' ';
        putchar('\n');
    }
    return 0;
}