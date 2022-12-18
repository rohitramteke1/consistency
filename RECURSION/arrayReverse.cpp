#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int i, int j) {
    if(i >= j) return;
    swap(arr[i], arr[j]);
    reverse(arr, i+1, j-1);
}

int main()
{
    int arr[] = {5,4,3,2,1,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    for (auto &&i : arr) cout << i << ' ';
    reverse(arr, 0, size-1);
    cout << endl;
    for (auto &&i : arr) cout << i << ' ';
    return 0;
}