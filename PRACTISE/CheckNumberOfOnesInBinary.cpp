// Given a base-10 integer, n, convert it to binary (base-2). 
// Then find and print the base-2 integer denoting the maximum number of 
// consecutive 1's in n's binary representation. When working with different bases, 
// it is common to show the base as a subscript.

#include <iostream>
#include <vector>

using namespace std;

void solution()
{
    vector<bool> vb;
    // decimal to binary
    cout << "Enter the number: " << endl;
    int n;
    cin >> n;
    if (n != 0 && n != 1)
    {
        while (n) // O(log base-2 N)
        {
            int rem = n % 2;
            vb.emplace_back(rem);
            n /= 2;
        }

        int size = vb.size(); // O(N)
        int i = 0, j = 1;
        int flag = 1, prevFlag = 0;
        for (int k = 0; k < size - 1; k++) // O(N)
        {
            if (vb[i] == 1 && vb[j] == 1)
            {
                ++flag;
            } 
            else {
                // reinitialise the flag here
                if (vb[i] == vb[j] ) // it means both are 0
                    flag = 0;
                else 
                    flag = 1;
            }                
            // binary num start's => 0 that's why "flag = 1" <= while declaration
            prevFlag = prevFlag > flag ? prevFlag : flag;
            i++; j++;
        }
        cout << "max: " << prevFlag << endl ;
    } else {
        cout << n << endl;
    }
}

int main()
{
    solution();

    return 0;
}

/*
// Given a base-10 integer, n, convert it to binary (base-2).
// Then find and print the base-2 integer denoting the maximum number of
// consecutive 1's in n's binary representation. When working with different bases,
// it is common to show the base as a subscript.

#include <iostream>
#include <vector>
using namespace std;

int CountNum(int N)
{
    int count = 0;
    while (N != 0)
    {
        // SR (x >> y) = x/2^y
        N = N & (N >> 1);
        count++;
    }
    return count;
}
int main()
{
    int out, input;
    cin >> input;
    out = CountNum(input);
    cout << output << endl ;
}
*/