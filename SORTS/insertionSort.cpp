#include <iostream>
using namespace std;

template <typename T>
void swap(T *xp, T *yp)
{
    T temp = *xp;
    *xp = *yp;
    *yp = temp;
}

template <typename T>
void print(T arr[], int size) {
    cout << endl;
    for (int i = 0; i < size; i++)
         cout << arr[i] << ' ';
}

template <typename T=int>
void selectionSort(T arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
            if (arr[min_idx] > arr[j])
                min_idx = j;

        print<T>(arr, size);
        // swap min_idx element with initial element

        if(min_idx != i)
            swap<T>(&arr[min_idx], &arr[i]);
    }
}

int main()
{
    int arr[] = {9, 4, 5, 6, 30, 1, 5};
    // int arr[] = {1,2,3,4,5,6,7};
    // 9 4 5 6 30 1 5 => 6
    // 1 4 5 6 30 9 5 => 0
    // 1 4 5 6 30 9 5 => 0
    // 1 4 5 5 30 9 5 => 3
    // 1 4 5 5 5 9 30 => 2
    // 1 4 5 5 5 9 30 => 1

    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);
    print(arr, n);
    return 0;
}