// we assumed that we've sorted and unsorted array 
// we pick up the element from unsorted array and placed into the  
// sorted array at it's correct position

#include <iostream>
using namespace std;

void print(int arr[], int size) {
    cout << endl;
    for (int i = 0; i < size; i++)
         cout << arr[i] << ' ';
}

void insertionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int key = arr[i];
        int j = i-1;
        while (arr[j] > key && j >= 0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        print(arr, size);
        arr[++j] = key;
    }
}

int main()
{
    int arr[] = {9, 4, 5, 6, 30, 1, 5};
    // int arr[] = {1,2,3,4,5,6,7};

    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    // print(arr, n);
    
    return 0;
}