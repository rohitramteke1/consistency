#include <bits/stdc++.h>
using namespace std;

int lomuto(int arr[], int low, int high) {
    int i = low - 1;
    int pivot = arr[high];
    for (int j=low; j<= high-1; j++) {
        if (pivot >= arr[j]) {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[high], arr[i + 1]);
    return i + 1;
}

int main()
{
    int arr[] = {3,8,6,12,10,4,-1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << lomuto(arr, 0, n-1) << endl;

    for(int i=0; i<n; i++)
        cout << arr[i] << ' ';

    return 0;
}