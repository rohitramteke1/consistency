#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high, int key) {
    int pivot = key;

    while (low <= high) {
        while (arr[key] >= arr[low]) {
            low++;
        }
        while (arr[key] < arr[high]) {
            high--;
        }
        if (low < high)
            swap(arr[low], arr[high]);
    }
    swap(arr[high], arr[key]);
}

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

int main()
{
    int arr[] = {3,8,6,12,10,4,-1};
    int n = sizeof(arr)/sizeof(arr[0]);

    // partition(arr, 0, n-1, 0);
    cout << lomuto(arr, 0, n-1) << endl;

    for(int i=0; i<n; i++)
        cout << arr[i] << ' ';

    return 0;
}