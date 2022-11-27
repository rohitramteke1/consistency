#include <bits/stdc++.h>
using namespace std;
// Brute-Force -> O(N * logN) sort()
// Better -> O(2 * N + Range(3)) count-sort()
// Optimal -> O(N) Dutch National Flag Problem

// DNF  Sorting
void sort012(int arr[], int n) {
    int lo = 0;
    int mid = 0;
    int hi = n-1;
    while(mid <= hi) {
        switch (arr[mid])
        {
        case 0:
            swap(arr[mid], arr[lo]);
            mid++; lo++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid], arr[hi]);
            hi--;
            break;
        }
    }
}

int main()
{
    int arr[] = {1,2,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort012(arr, n);
    for (auto &&i : arr)
        cout << i << ' ';
/*
    void sort012(int arr[], int n) {
        // sort(arr, arr + n); // O ( N * logN )
        // hashmap -> O(2 * N)
        // Dutch National Flag Problem(DNF) O(N)
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++) hash[arr[i]]++;
        while (hash[0]-- > 0) cout << 0 << ' ';
        while (hash[1]-- > 0) cout << 1 << ' ';
        while (hash[2]-- > 0) cout << 2 << ' ';
    }
*/
    return 0;
}