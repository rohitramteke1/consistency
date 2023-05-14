#include <bits/stdc++.h>
using namespace std;

void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);

void print(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << ' ';
    }
}

int main()
{
    int arr[] = {9,7,8,4,1,3,2,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, n-1);
    print(arr, n);
    return 0;
}

void mergeSort(int arr[], int low, int high) {
    if (high > low) {
        int mid = low + ((high - low) >> 1);
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// O(NlogN)

void merge(int arr[], int low, int mid, int high) {
    // create aux array
    int a_size = mid - (low - 1);
    int b_size = (high - 1) - (mid - 1);

    int *a = new int[a_size + 1];
    int *b = new int[b_size + 1];

    a[a_size] = b[b_size] = INT_MAX;

    // copy the elements from the original array to aux array
    for(int i=0; i<a_size; i++)
        a[i] = arr[i + low];

    for(int i=0; i<b_size; i++) 
        b[i] = arr[i + mid + 1];
    
    int i = 0, j = 0;
    // copy to original arrays
    for (int k=low; k<=high; k++) {
        if (a[i] <= b[j] ) {
            arr[k] = a[i];
            i++;
        }
        else {
            arr[k] = b[j];
            j++;
        }
    }
    delete a, b;
}