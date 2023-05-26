#include <bits/stdc++.h>
using namespace std;

void countingSort(int arr[], int n, int exp) {
    int count[10];
    memset(count, 0, sizeof(count));

    // store the digit / reminder
    for (int i=0; i<n; i++) 
        count[ (arr[i] / exp) % 10 ]++;

    for (int i=1; i<10; i++)
        count[i] = count[i-1] + count[i];

    int output[n];

    for(int i=n-1; i>=0; i--) {
        output[ count[ (arr[i] / exp) % 10 ] - 1 ] = arr[i];
        count[ (arr[i] / exp) % 10]--;
    }
    for (int i=0; i<n; i++) 
    {
        arr[i] = output[i];
        cout << arr[i] << ' ';
    }
    cout << endl;
}


void radixSort(int arr[], int n) {
    int mx = *max_element(arr, arr + n);

    for (int exp=1; mx / exp > 0; exp = exp * 10) {
        countingSort(arr, n, exp);
    }
}

int main()
{
    int arr[] = {319,212,6,8,100,50};
    int n = sizeof(arr)/sizeof(arr[0]);

    radixSort(arr, n);
    
    return 0;
}