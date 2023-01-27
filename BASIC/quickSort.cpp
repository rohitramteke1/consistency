#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = low;
    while (low <= high)
    {
        while(arr[pivot] >= arr[low]) low++;
        while(arr[pivot] < arr[high]) high--;
    }
    swap(arr[high], arr[pivot]);
    return high;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int p_index = partition(arr, low, high);
        quickSort(arr, low, p_index-1);
        quickSort(arr, p_index+1, high);
    }
}


int main()
{
    int arr[] = {10,2,3,7,8,9,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, 6);
    for (auto &&i : arr)
    {
        cout << i << ' ';
    }
    
    return 0;
}