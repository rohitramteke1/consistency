#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5];
    int k = 2; // delete 2 index value

    for (int i = 0; i < 5; i++)
        arr[i] = i+1;
    
    // delete the kth element
    for (int i = 0; i < 5; i++)
    {
        if(i >= k && i < 5)
            arr[i] = arr[i+1];
    }
    // marked with -1
    arr[4] = -1;
    
    // display
    for (int i = 0; i < 5; i++)
        cout << arr[i] << ' ';
    

    return 0;
}