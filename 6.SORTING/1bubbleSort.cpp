#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {

    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }

    for(int i=0; i<n; i++) {
        cout << arr[i] << ' ';
    }
}

int main()
{
    int arr[] = {4,57,2,1,9,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, n);
    
    return 0;
}