#include <bits/stdc++.h>
using namespace std;

// without space
void better(int a[], int b[], int n, int m) {
    sort(a, a + n);
    sort(b, b + m);

    int i = 0, j = 0;

    while (i < m && j < n) {
        if (i > 0 && a[i] == a[i-1]) {
            i++;
            continue;
        }
        if (a[i] < b[j])
            i++;
        else if (a[i] > b[j])
            j++;
        else {
            cout << a[i] << ' ';
            i++, j++;
        }
    }
}

// naive solution O( 2 * max(n,m) ) + O( max(n,m) ) we can minimise the space by altering thw pointers
void countDistinct(int a[], int b[], int n, int m) {

    unordered_map<int, int> mp;

    for (int i=0; i<n; i++)
        mp[ a[i] ]++;

    for (int j = 0; j<m; j++) {
        if ( mp.find(b[j]) != mp.end() && mp[b[j]] > 0) {
            cout << b[j] << ' ';
            mp[b[j]] = 0;
        }
    }
}

int main()
{
    int arr[] = {10,10,20,30,30,20,30,20,20};
    int arr2[] = {10,20,20, 20,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);

    // countDistinct(arr, arr2, n, m);
    better(arr, arr2, n, m);


    return 0;
}