// Quick Sort
// One of the best sorting algorithm
// worst O(N^2)
// best O(N*logN)
// average O(N*logN)

#include <iostream>
using namespace std;

void print(int arr[], int size) {
    cout << endl;
    for (int i = 0; i < size; i++)
         cout << arr[i] << ' ';
}

int partitionIndex(int arr[], int n) {
    
}

void quickSort(int arr[], int n) {
    int partition = partitionIndex(arr, n);


}

int main()
{
    int arr[] = {9, 4, 5, 6, 30, 1, 5};
    // int arr[] = {1,2,3,4,5,6,7};

    int n = sizeof(arr) / sizeof(arr[0]);
    
    return 0;
}