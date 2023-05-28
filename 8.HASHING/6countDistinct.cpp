#include <bits/stdc++.h>
using namespace std;

// naive solution O(N ^ 2) + O(1)
int countDistinct(int arr[], int n) {
    int unique = 0;

    for (int i=0; i<n; i++) {
        bool flag = false;

        for (int j=0; j<i; j++) {
            if (arr[i] == arr[j]) {
                flag = true;
                break;
            }
        }

        if (!flag)
            unique++;
    }

    return unique;
}

// better O(N * logN) + O(1)
int better(int arr[], int n) {
    sort(arr, arr + n);

    int unique = 1;
    for (int i=1; i<n; i++) 
        if (arr[i] != arr[i-1])
            unique++;

    return unique;
}

// optimal O(N) + O(N)
int optimal(int arr[], int n) {
    unordered_set<int> st;

    for (int i=0; i<n; i++) 
        st.insert(arr[i]);

    return st.size();
}

int main()
{
    int arr[] = {10,10,20,30,30,20,30};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << countDistinct(arr, n) << endl;
    cout << optimal(arr, n) << endl;
    cout << better(arr, n) << endl;

    return 0;
}