#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n) {
    for (int i=0; i<n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

void cycleSort(int arr[], int n) {
    for (int i=0; i<n;) {
        int correctIndex = arr[i] - 1;
        if (arr[i] == arr[correctIndex]) 
            i++;
        else
            swap(arr[i], arr[correctIndex]);
    }
}

int main()
{
    // arr is given in the range of 1 to n, now sort the arr in single pass
    int arr[] = {5,1,3,2,4};

    cycleSort(arr,5);
    
    print(arr, 5);

    return 0;
}