#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        while (a)
        {
            int rem = a % 10;
            if (rem == 7)
            {
                cout << "YES\n";
                break;
            }
            a /= 10;
        }
        if (a == 0)
        {
            cout << "NO\n";
        }
    }
    return 0;
}
