#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int hoare(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
    return 0;
}

// advanced hoare
int advHoare(int arr[], int low, int high) {
    // select the first element as the pivot element
    int pivot = arr[low];

    // 3,8,6,12,10,4,-1
    
    while (low <= high){
        while (pivot > arr[low]) low++;
        while (pivot < arr[high]) high--;

        if (low < high)
            swap(arr[low++], arr[high--]);
    }

    swap(arr[high], pivot);
    return high;
}

void qsort(int arr[], int low, int high) {
    if (low >= high)
        return;
    int pi = hoare(arr, low, high);
    qsort(arr, low, pi);
    qsort(arr, pi + 1, high);
}

int main()
{
    int arr[] = {-1,8,6,12,10,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    // cout << hoare(arr, 0, n-1) << endl;
    qsort(arr, 0, n-1);
    print(arr, n);

    return 0;
}