#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
int main()
{
    int arr[] = {99, 101, 130, 1,8,6,3,2,7,9};
    int size = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<size; i++)
        a[arr[i]]++;

    for (int i = 0; i < N; i++)
        if(a[i] != 0)
            cout << i << ' ';
            // cout << arr[i] << ' ';
    
    return 0;
}