// Merge Sort
// One of the best sorting algorithm
// worst O(N*logN)
// best O(N*logN)
// average O(N*logN)

#include <iostream>
using namespace std;

void print(int arr[], int size) {
    cout << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
}

void merge(int arr[], int low, int mid, int high) {
    int size_L = mid - low + 1;
    int size_R = high - mid;
    int LEFT[size_L + 1];
    int RIGHT[size_R + 1];
    // set infinity
    LEFT[size_L] = RIGHT[size_R] = INT_MAX;
    // copy the arrays
    for (int i = 0; i < size_L; i++)
        LEFT[i] = arr[i + low];
    for (int j = 0; j < size_R; j++)
        RIGHT[j] = arr[mid + 1 + j];
    int i = 0;
    int j = 0;
    for (int k = low; k <= high; k++)
    {
        if(LEFT[i] <= RIGHT[j]) {
            arr[k] = LEFT[i];
            i++;
        } else {
            arr[k] = RIGHT[j];
            j++;
        }
    }
}

void mergeSort(int arr[], int low, int high) {
    if(low < high) {
        int mid = (low + high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {9, 4, 5, 6, 30, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    mergeSort(arr, 0, 6);
    print(arr, n);

    return 0;
}