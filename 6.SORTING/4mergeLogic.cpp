#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << ' ';
    }
}

void mergeLogic(int arr[], int low, int mid, int high) {
    
    int a_size = mid - low + 1;
    int b_size = high - mid;

    int a[a_size + 1];
    int b[b_size + 1];

    a[a_size] = b[b_size] = INT_MAX;

    for (int i=0; i<a_size; i++)
        a[i] = arr[i + low];

    for (int i=0; i<b_size; i++)
        b[i] = arr[i + mid + 1];

    int k=0; int j=0;
    for (int i=low; i<=high; i++) {
        if (a[k] <= b[j]) {
            arr[i] = a[k];
            k++;
        }
        else {
            arr[i] = b[j];
            j++;
        }
    }
}

int main()
{
    int arr[] = {3,4,5,6,0,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int low = 0;
    int high = n - 1;
    int mid = (low + high) >> 1;

    mergeLogic(arr, low, mid, high);
    print(arr, n);

    return 0;
}