#include <bits/stdc++.h>
using namespace std;

// O(nlogn)
int brute(int arr[], int n, int k) {
    sort(arr, arr + n);
    int i = 1;
    int totalCount = 0;

    while (i < n) {
        int count = 1;
        while (arr[i] == arr[i-1])
        {
            ++count;
            i++;
        }
        if (count > n / k)
            totalCount += 1;
        i++;
    }

    return totalCount;
}

// Efficeint Solution
// O(n) + O(n)
int countDistinctInWindow(int arr[], int n, int k) {
    unordered_map<int, int> mp;

    // first window
    for (int i=0; i<n; i++) 
        mp[ arr[i] ]++;

    int totalCount = 0;
    for (auto &pair : mp) {
        if (pair.second > n / k)
            totalCount++;
    }

    return totalCount;
}

int main()
{
    int arr[] = {10,10,5,10,20}; // 5 10 20
    int n = sizeof(arr)/sizeof(arr[0]);

    // brute solution to use sorting
    // hashMap
    cout << countDistinctInWindow(arr, n, 2) << endl;
    cout << brute(arr, n, 2) << endl;

    return 0;
}