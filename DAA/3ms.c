#include <stdio.h>
#include <stdlib.h>

int arr[100];

void merge(int low, int mid, int high) {
    // create two arrays
    int m = mid - low + 1;
    int n = high - mid;
    int a[m + 1];
    int b[n + 1];
    a[m] = b[n] = INT_MAX;

    // copy the array data int temp arrays
    for(int i=0; i<m; ++i)
        a[i] = arr[i + low];
    for(int j=0; j<n; ++j)
        b[j] = arr[mid + 1 + j];
    
    // store the array data into the original array
    int i = 0;
    int j = 0;
    int k = low;

    while(i < m && j < n) {
        if(a[i] <= b[j]) {
            arr[k] = a[i];
            i++;
        }
        else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }
    while(i < m) {
        arr[k] = a[i];
        i++;
        k++;
    }
    while(j < n) {
        arr[k] = b[j];
        j++;
        k++;
    }
}

void mergeSort(int low, int high) {
    if(low < high) {
        int mid = low + (high - low)/2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main() {
    for (int i = 0; i < 8; i++)
        arr[i] = 8-i;
    
    mergeSort(0, 7);

    for(int i=0; i<8; ++i) 
        printf("%d ", arr[i]);
    
    return 0;
}