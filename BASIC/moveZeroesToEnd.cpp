#include <bits/stdc++.h>
using namespace std;

void pushZerosToEnd(int arr[], int n)
{
    int low = 0, mid = 0;
    while (mid < n)
    {
        // 3, 5, 0, 0, 4, 0
        // 3, 5, 0, 0, 4, 0
        // 3, 5, 4, 0, 0, 0
        if (arr[low] == 0 && arr[mid] == 0) mid++;
        else if (arr[low] == 0 && arr[mid] != 0) swap(arr[low], arr[mid]);
        else low++, mid++;
    }
}
    void solve(int arr[], int n)
    {
        int j = n-1;
        int i = 0;
        while(i < j) {
            while(arr[i] == 0 && i < j) {
                i++;
            }
            while(arr[j] != 0 && j > i) {
                j--;
            }
            swap(arr[i], arr[j]);
        }
        reverse(arr, arr + n);
    }

    int main()
    {
        int arr[] = {0, 0, 0, 4};
        int n = sizeof(arr) / sizeof(arr[0]);
        // pushZerosToEnd(arr, n);
        solve(arr, n);
        for (auto &&i : arr)
            cout << i << ' ';

        return 0;
    }