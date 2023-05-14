#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << ' ';
    }
}

void insertionLogic(int arr[], int i) {
    int j = i-1;
    int key = arr[i];
    
    while (j >= 0 && key < arr[j]) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}

void insertionSort(int arr[], int n) {

    // we pick an element from the unsorted array
    // we find its correct position in the sorted array and 
    // insert it on that position
    // just like the playing cards in real life

    for (int i = 1; i < n; i++) {
        insertionLogic(arr, i);
    }
    print(arr, n);
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr, n);
    
    return 0;
}

