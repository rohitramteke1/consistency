#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i=low - 1;
    int j=high + 1;

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
}

int main()
{
    int arr[] = {5,8,6,12,10,4,-1};
    int n = sizeof(arr)/sizeof(arr[0]);

    //   pivot >   &&      pivot < 
    // low <==> j and j + 1 <==> high 

    cout << partition(arr, 0, n-1) << endl ;

    for(int i=0; i<n; i++)
        cout << arr[i] << ' ';

    return 0;
}