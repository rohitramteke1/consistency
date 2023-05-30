#include <bits/stdc++.h>
using namespace std;

// O(k * logk)
int countDistinctInArray(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int count = 1;
    for (int i=1; i<arr.size(); i++) {
        if (arr[i] != arr[i-1])
            ++count;
    }
    return count;
}

void brute(int arr[], int n, int k) {
    // O( (n-k) * k * logk )
    // O(N^2*logN)
    for (int i=0; i<n-k+1; i++) {
        vector<int> v(arr + i, arr + i + k);
        cout << countDistinctInArray(v) << ' ';
    }
}

// Efficeint Solution
void countDistinctInWindow(int arr[], int n, int k) {
    unordered_map<int, int> mp;

    // first window
    for (int i=0; i<k; i++) mp[arr[i]]++;
    cout << mp.size() << ' ';

    for (int i=k; i<n; i++) {
        mp[ arr[i-k] ]--;
        if (mp[arr[i-k]] == 0)
            mp.erase(arr[i-k]);
        mp[arr[i]]++;
        cout << mp.size() << ' ';
    }
}

int main()
{
    int arr[] = {10,10,5,3,20,5}; // 3 5 10 20
    int n = sizeof(arr)/sizeof(arr[0]);

    brute(arr, n, 4);
    cout << endl;
    countDistinctInWindow(arr, n, 4);

    
    return 0;
}