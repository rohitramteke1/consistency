#include <bits/stdc++.h>
using namespace std;

int partition_index(vector<int> &arr, int low, int high);

void quickSort(vector<int> &arr, int low, int high) {
    if(low < high) {
        int pi = partition_index(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition_index(vector<int> &arr, int low, int high) {
    int pivot = low;
    while(low < high) {
        while(arr[pivot] >= arr[low])
            low++;
        while(arr[pivot] < arr[high])
            high--;
        if(low < high)
            swap(arr[low], arr[high]);
    }
    swap(arr[high], arr[pivot]);
    return high;
}

int main()
{
    vector<int> arr = {1,2,5,6,0,7};
    
    quickSort(arr, 0, arr.size() - 1);

    for (auto &&i : arr) 
        cout << i << ' ';
    
    
    return 0;
}