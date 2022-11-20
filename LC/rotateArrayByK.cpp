// 189
#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n) {
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void rotate(int arr[], int n) {
    int j = n-2;
    int key = arr[n-1];
    while(j >= 0) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
    print(arr, n);
    cout << endl;
}

void _reverse(int arr[], int low, int high) {
    while (low < high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}

void rotateOptimised(int arr[], int n, int k) {
    print(arr, n);
    _reverse(arr, n-k, n-1);
    _reverse(arr, 0, n-k-1);
    _reverse(arr, 0, n-1);
    print(arr, n);
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    print(arr, n);
    cout << endl;
    rotateOptimised(arr, n, k);
    
    return 0;
}