// Quick Sort
// One of the best sorting algorithm
// worst O(N^2)
// best O(N*logN)
// average O(N*logN)

#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int partition(int arr[], int low, int high) {
    int pivot = low;
    while(low < high) {
        while(arr[pivot] >= arr[low]) low++;
        while(arr[pivot] < arr[high]) high--;
        if(low < high) swap(arr[low], arr[high]);
    }
    swap(arr[pivot], arr[high]);
    return high;
}

void quickSort(int arr[], int low, int high) {
    if(low > high) return;
    int p_index = partition(arr, low, high);
    quickSort(arr, low, p_index - 1);
    quickSort(arr, p_index + 1, high);
}

int main()
{
    int arr[] = {5,4,0,1,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, n-1);
    print(arr, n);
    
    return 0;
}

/*
#include <iostream>
using namespace std;

void print(int arr[], int size) {
    cout << endl;
    for (int i = 0; i < size; i++)
         cout << arr[i] << ' ';
}

int partitionIndex(int arr[], int low, int high, int n) {
    int i = low;
    int j = high;
    int pivot = low;
    while (j > i)
    {
        while(arr[pivot] >= arr[i]) i++;
        while(arr[pivot] < arr[j]) j--;

        if(j > i)
            swap(arr[i], arr[j]);
    }
    swap(arr[pivot], arr[j]);

    return j;
}

void quickSort(int arr[], int low, int high, int n) {

    if( high < low ) return;
    int partition = partitionIndex(arr, low, high, n);
    quickSort(arr, low, partition-1, n);
    quickSort(arr, partition+1, high, n);
}

int main()
{
    int arr[] = {9, 4, 5, 5, 6, 1, 7};
    // int arr[] = {4,6,2,5,7,9,1,3};
    // int arr[] = {1,2,3,4,5,6,7};

    int n = sizeof(arr) / sizeof(arr[0]);

    // partitionIndex(arr, 0, n-1, n);
    quickSort(arr, 0, n-1, n);
    print(arr, n);
    
    return 0;
}
*/