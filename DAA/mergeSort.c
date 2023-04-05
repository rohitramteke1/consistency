#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high) {
    int m = mid - low + 1;
    int n = high - mid;

    int *left = (int *)calloc(m + 1, sizeof(int));
    int *right = (int *)calloc(n + 1, sizeof(int));

    left[m] = right[n] = INT_MAX;

    // copy the elements in temp arrays'
    for(int i=0; i<m; ++i) {
        left[i] = arr[low + i];
    }

    for(int j=0; j<n; ++j) {
        right[j] = arr[mid + 1 + j];
    }

    int a = 0;
    int b = 0;

    for(int i=low; i<=high; i++) {
        if(left[a] <= right[b]) {
            arr[i] = left[a];
            a++;
        }
        else {
            arr[i] = right[b];
            b++;
        }
    }
    // freed the memory
    free(left);
    free(right);
}

void mergeSort(int arr[], int low, int high) {
    if(low < high) {
        int mid = low + (high - low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {

    int arr[] = {9,3,0,7,1,4,2,11};

    mergeSort(arr, 0, 5);

    for (int i = 0; i < 6; i++)
        printf("%d ", arr[i]);

    return 0;
}