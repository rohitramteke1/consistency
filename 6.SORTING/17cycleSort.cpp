#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n) {
    for (int i=0; i<n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

void cycleSort(int arr[], int n) {
    for (int i=0; i<n;) {
        int mn_cnt = 0;
        for (int j=i+1; j<n; j++) {
            if (arr[i] >= arr[j]) {
                mn_cnt++;
            } 
        }
        if (mn_cnt == 0) {
            i++;
            continue;
        }
        swap(arr[i], arr[i+mn_cnt]);
        print(arr, n);
    }
}

int main()
{
    int arr[] = {5,2,1,10, -7, 6};

    cycleSort(arr, 6);
    
    // print(arr, n);

    return 0;
}