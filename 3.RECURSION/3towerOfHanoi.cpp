#include <iostream>
using namespace std;

// Famous Recursive Problem
void towerOfHanoi(int n, int s, int d, int h) {
    if(n == 1)
    {
        cout << "moving plate " << n << " from " << s << " to " << d << endl;
        return;
    }

    // moving plate source to helper
    towerOfHanoi(n-1, s, h, d);

    // move one plate
    cout << "moving plate " << n << " from " << s << " to " << d << endl;

    // moving plate from helper to source
    towerOfHanoi(n-1, h, d, s);
}

int main()
{
    towerOfHanoi(5, 1,2,3);
    
    return 0;
}