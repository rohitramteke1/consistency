#include <bits/stdc++.h>
using namespace std;

void countTable(int *arr, int n) {

    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] - 1;
    }

    for (int i = 0; i<n; i++) {
        int index = arr[i] % n;
        arr[index] = arr[index] + n;
    }

    for (int i = 0; i<n; i++) {
        cout << i + 1 << ' ' << arr[i] / n << endl;
    }

}

int main()
{
    int arr[] = {1,2,2,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);   
    countTable(arr, n);
    return 0;
}