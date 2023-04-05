#include <iostream>
using namespace std;

// O(N) + O(N)
int recursion(int n) {
    // Base-condition
    if(n <= 0)
        return 0;

    // Calling itself
    return n + recursion(n - 1);
}

int main()
{
    // cout << recursion(10) << endl;
    
    return 0;
}