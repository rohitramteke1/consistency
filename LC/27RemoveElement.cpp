#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {0,1,2,2,3,0,4,2};
    for (auto &&i : arr) cout << i << ' ';
    cout << endl;

    int n = sizeof(arr)/sizeof(arr[0]);
    int val = 2;
    int i = 0;
    int j = 0;
    while(j < n) {
        if(arr[j] != val) {
            if(arr[i] != arr[j]) swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
    for (auto &&i : arr) cout << i << ' ';
    

    return 0;
}