#include <bits/stdc++.h>
using namespace std;

// bruteForce HashMap
// vector<int> v(10^6, false);
// sorting

int firstPositiveInteger(int *arr, int n ) {
    for (int i=0; i<n; i++) {
        if (arr[i] <= 0 or arr[i] > n)
            continue;
        int j = arr[i] - 1;
        if (arr[i] != arr[j] ) {
            swap(arr[i], arr[j]);
            i--;
        }
    }
    for (int i=0; i<n; i++) {
        if( arr[i] != i+1)
            return i+1;
    }
    return n+1;
}

int main()
{
    // int arr[] = {1,2,3,4,5};
    int arr[] = {0,-10,1,3,-20};
    int n = 5;
    
    cout << firstPositiveInteger(arr, n) << endl;

    return 0;
}