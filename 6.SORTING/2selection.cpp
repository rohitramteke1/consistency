#include <bits/stdc++.h>
using namespace std;

// this type of idea is used in heap sort also
// selection sort
// algo
// we considered that there are two arrays
// sorted + unsorted
// we pick up the minimum element from the unsorted array
// and add it to the sorted array
void selectionSort(int arr[], int n) {

    for (int i=0; i<n; i++) {
        int min_idx = i;
        // find the index of min element in the rest of unsorted array
        for (int j=i+1; j<n; j++) {
            // update the min-index
            if (arr[min_idx] > arr[j])
                min_idx = j;
        }
        // swap the min-index with arr[i]
        swap(arr[min_idx], arr[i]);
    }

    for(int i=0; i<n; i++) {
        cout << arr[i] << ' ';
    }
}

int main()
{
    int arr[] = {4,57,2,1,9,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr, n);
    
    return 0;
}