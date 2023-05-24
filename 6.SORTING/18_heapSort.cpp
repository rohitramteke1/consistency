#include <bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n, int k) {
    int count[k];
    memset(count, 0, sizeof(count));

    for (int i=0; i<n; i++) 
        count[ arr[i] ]++;

    // prefix sum
    // 1 4 4 1 0 1
    // 0 4 4 2 4
    for (int i=1; i<n; i++)
        count[i] = count[i-1] + count[i];

    int output[n];

    for(int i=n-1; i>=0; i--) {
        int index = count[ arr[i] ];
        output[ index - 1 ] = arr[i];
        count[ arr[i] ]--;
    }
    for (int i=0; i<n; i++) 
    {
        arr[i] = output[i];
        cout << arr[i] << ' ';
    }
}

int main()
{
    int arr[] = {1,4,4,1,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int k = *max_element(arr, arr + n) + 1;
    countSort(arr, n, k);
    
    return 0;
}