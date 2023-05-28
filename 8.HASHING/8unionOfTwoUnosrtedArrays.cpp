#include <bits/stdc++.h>
using namespace std;

// O(n + m)
void unionOfTwoArrays(int a[], int b[], int n, int m) {

    unordered_set<int> st;

    for (int i=0; i<n; i++)
        st.insert(a[i]);

    for (int j = 0; j<m; j++)
        st.insert(b[j]);

    for (auto &ele : st)
        cout << ele << ' ';

    // TODO: 
    // if you want the sorted order
    // vector<int> result(st.begin(), st.end());
    // sort(result.begin(), result.end());
    // return result;
}

int main()
{
    int arr[] = {10,10,20,30,30,20,30,20,20};
    int arr2[] = {10,20,20, 20,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);

    unionOfTwoArrays(arr, arr2, n, m);


    return 0;
}