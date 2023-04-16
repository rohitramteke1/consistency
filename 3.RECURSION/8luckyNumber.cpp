#include <bits/stdc++.h>
using namespace std;

bool isLucky(int n) {
    static int counter = 2;

    if(counter > n)
        return 1;

    if(counter == n)
        return 0;

    int np = n;
    np = np - np / counter;
    counter++;
    return isLucky(np);
}

int main()
{
    int n = 85;
    cout << isLucky(n) << endl;
    
    return 0;
}