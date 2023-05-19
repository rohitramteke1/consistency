#include <bits/stdc++.h>
using namespace std;


int lomuto(int arr[], int low, int high) {
    int i = low - 1;
    int pivot = arr[high];
    for (int i=low; i<= high-1; i++) {
        if (arr[i] > pivot) {
            i++;
            swap(arr[i], arr[high]);
        }
    }
    swap(arr[high], arr[i + 1]);
    return i + 1;
}

void qsort(int arr[], int low, int high) {

    if (low >= high) return;

    int pi = lomuto(arr, low, high);
    qsort(arr, low, pi - 1);
    qsort(arr, pi + 1, high);
}

int main()
{
    int arr[] = {3,8,6,12,10,4,-1};
    // int arr[] = {1,2,3,4,5,6,7,8};

    int n = sizeof(arr)/sizeof(arr[0]);

    qsort(arr, 0, n-1);

    for(int i=0; i<n; i++) cout << arr[i] << ' ';
    
    return 0;
}