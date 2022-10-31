#include <bits/stdc++.h>
using namespace std;

int minimiseTheHeight(int arr[], int n, int k) {

    sort(arr, arr+n); // O(n * logn )
    int _max = arr[n-1];
    int _min = arr[0];
    int diff = _max - _min;

    for (int i = 1; i < n; i++)
    {
        if(arr[i]-k < 0) continue;
        
        _max = max(arr[i-1]+k, arr[n-1]-k);
        _min = min(arr[i]-k, arr[0]+k);

        diff = min(diff, _max - _min);
    }
    
    return diff;
}

int main()
{
    int arr[] = {3, 9, 12, 16, 20};
    int n = 5;
    int k = 3;
    cout << minimiseTheHeight(arr, n, k) << endl;
    
    return 0;
}